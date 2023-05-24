#include "main.h"

#include <sstream>

using namespace std;
lv_obj_t *myButton;
lv_obj_t *tabview;

lv_obj_t *myButtonLabel;
lv_obj_t *myLabel;

lv_style_t myButtonStyleREL; // relesed style
lv_style_t myButtonStylePR;  // pressed style

lv_obj_t *tab1;
lv_obj_t *tab2;
lv_obj_t *tab3;

static lv_res_t btn_click_action(lv_obj_t *btn)
{

    uint8_t id = lv_obj_get_free_num(btn); // id usefull when there are multiple buttons

    if (id == 0)
    {
        char buffer[100];
        sprintf(buffer, "button was clicked %i seconds from start", pros::millis() / 100);
        lv_label_set_text(myLabel, buffer);
    }

    return LV_RES_OK;
}

class UIManager
{
public:
    static void init()
    {
        tabview = lv_tabview_create(lv_scr_act(), NULL);
        tab1 = lv_tabview_add_tab(tabview, "Tab 1");
        tab2 = lv_tabview_add_tab(tabview, "Tab 2");
        tab3 = lv_tabview_add_tab(tabview, "Motors");
        lv_tabview_set_tab_load_action(tabview, TabChange);
         
    }




private:
    static lv_res_t TabChange(lv_obj_t *tabview, uint16_t tab_id) {
        if (tab_id==2) showMotors();
        return LV_RES_OK;
    }


    static void showMotors()
    {
        lv_obj_t *table = lv_table_create(lv_scr_act(), NULL);
        lv_table_set_col_cnt(table, 2);
        lv_table_set_row_cnt(table, 5);
        lv_obj_align(table, NULL, LV_ALIGN_CENTER, 0, 0);

        /*Make the cells of the first row center aligned */
        lv_table_set_cell_align(table, 0, 0, LV_LABEL_ALIGN_CENTER);
        lv_table_set_cell_align(table, 0, 1, LV_LABEL_ALIGN_CENTER);

        /*Align the price values to the right in the 2nd column*/
        lv_table_set_cell_align(table, 1, 1, LV_LABEL_ALIGN_RIGHT);
        lv_table_set_cell_align(table, 2, 1, LV_LABEL_ALIGN_RIGHT);
        lv_table_set_cell_align(table, 3, 1, LV_LABEL_ALIGN_RIGHT);
        
        lv_table_set_cell_type(table, 0, 0, 2);
        lv_table_set_cell_type(table, 0, 1, 4);

        /*Fill the first column*/
        lv_table_set_cell_value(table, 0, 0, "PORT");
        lv_table_set_cell_value(table, 1, 0, "1");
        lv_table_set_cell_value(table, 2, 0, "10");
        lv_table_set_cell_value(table, 3, 0, "11");
        lv_table_set_cell_value(table, 4, 0, "19");

        /*Fill the second column*/
        lv_table_set_cell_value(table, 0, 1, "Type");
        lv_table_set_cell_value(table, 1, 1, "Motor");
        lv_table_set_cell_value(table, 2, 1, "Motor");
        lv_table_set_cell_value(table, 3, 1, "Motor");
        lv_table_set_cell_value(table, 4, 1, "Motor");
    }
    void showMotorInfo(pros::Motor motor)
    {
        lv_obj_t *label = lv_label_create(tab3, NULL);
        std::stringstream ss;
        ss << "Temp: " << motor.get_temperature() << "\n";
        ss << "Gearing: " << motor.get_gearing() << "\n";
        auto temp = ss.str();

        auto motor_info = temp.c_str();
        lv_label_set_text(label, motor_info);
    }
};