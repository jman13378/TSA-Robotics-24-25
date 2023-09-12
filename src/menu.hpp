#include "main.h"
#include <typeinfo>
#include <typeinfo>
#include "autoSelect/selection.h"
#include <sstream>
using namespace std;

lv_obj_t *tabview;

lv_obj_t *tab1;
lv_obj_t *tab2;
lv_obj_t *tab3;
lv_obj_t *tab4;

vector<string> debug;

lv_task_t *task;

class UIManager
{

public:
    static void exit()
    {

        lv_task_del(task);
        lv_tabview_clean(tabview);
        lv_obj_del(tabview);
    }
    static void update()
    {
    }

    static void init()
    {

        task = lv_task_create(showMotors, 500, LV_TASK_PRIO_HIGHEST, NULL);

        tabview = lv_tabview_create(lv_scr_act(), NULL);
        /*Create a simple button style*/
        tab1 = lv_tabview_add_tab(tabview, "Selectors");
        tab3 = lv_tabview_add_tab(tabview, "Motors");
        tab4 = lv_tabview_add_tab(tabview, "Debug");
        lv_tabview_set_tab_load_action(tabview, TabChange);
        const char *b[] = {"Front", "Back", "Do Nothing", ""};
        selector::init(360,1,b);
    }

private:
    static lv_res_t TabChange(lv_obj_t *tabview, uint16_t tab_id)
    {
        if (tab_id != 2)
            lv_task_del(task);
        switch (tab_id)
        {
        case 0:
            break;
        case 1:

            break;
        case 2:
            task = lv_task_create(showMotors, 500, LV_TASK_PRIO_HIGHEST, NULL);
            return LV_RES_OK;
            break;
        case 3:
            lv_tabview_clean(tab4);
            
            break;

        default:
            break;
        }

        return LV_RES_OK;
    }

    static void showMotors(void *task)
    {
        lv_tabview_clean(tab3);
        std::stringstream ss;
        lv_obj_t *label = lv_label_create(tab3, NULL);

        ss << showMotorInfo(FLeft, "Front Left") + showMotorInfo(RLeft, "Rear Left") + showMotorInfo(FRight, "Front Right") + showMotorInfo(RRight, "Rear Right");
        auto temp = ss.str();

        auto motor_info = temp.c_str();
        lv_label_set_text(label, motor_info);
    }

    static std::string showMotorInfo(pros::Motor motor, string name)
    {

        std::stringstream ss;

        /*if (motor.get_gearing() == 0)
            gearing = "100";
        if (motor.get_gearing() == 1)
            gearing = "200";
        if (motor.get_gearing() == 2)
            gearing = "600";*/
        std::string s = std::to_string(motor.get_temperature());
        ss << "Name: "
           << name
           << " | Temp: "
           << ((motor.get_temperature() == INFINITY) ? "Not Connected" : s.substr(0, s.find("."))) << " | Velocity: " << ((motor.get_temperature() == INFINITY) ? 0.00 : (motor.get_actual_velocity())) << "\n";
        // ss << "RPM/Velocity/Max: " << motor.get_target_velocity()
        //     << "/" << motor.get_actual_velocity() << "/" << gearing << "\n";
        // ss << "Gearing: " << motor.get_gearing() << "\n";
        // ss << "Voltage: " << motor.get_voltage() << "\n";
        // ss << "Torque: " << motor.get_torque() << "\n";

        return ss.str().c_str();
    }
};

namespace selector
{

    int auton;
    int autonCount;
    const char *btnmMap[] = {"", "", "", "", "", "", "", "", "", "", ""}; // up to 10 autons

    lv_obj_t *tabiew;
    lv_obj_t *redBtnm;
    lv_obj_t *blueBtnm;

    lv_res_t redBtnmAction(lv_obj_t *btnm, const char *txt)
    {
        // printf("red button: %s released\n", txt);

        for (int i = 0; i < autonCount; i++)
        {
            if (strcmp(txt, btnmMap[i]) == 0)
            {
                auton = i + 1;
            }
        }

        return LV_RES_OK; // return OK because the button matrix is not deleted
    }

    lv_res_t blueBtnmAction(lv_obj_t *btnm, const char *txt)
    {
        // printf("blue button: %s released\n", txt);

        for (int i = 0; i < autonCount; i++)
        {
            if (strcmp(txt, btnmMap[i]) == 0)
            {
                auton = -(i + 1);
            }
        }

        return LV_RES_OK; // return OK because the button matrix is not deleted
    }

    lv_res_t skillsBtnAction(lv_obj_t *btn)
    {
        // printf("skills pressed");
        auton = 0;
        return LV_RES_OK;
    }

    int tabWatcher()
    {
        int activeTab = lv_tabview_get_tab_act(tabview);
        while (1)
        {
            int currentTab = lv_tabview_get_tab_act(tabview);

            if (currentTab != activeTab)
            {
                activeTab = currentTab;
                if (activeTab == 0)
                {
                    if (auton == 0)
                        auton = 1;
                    auton = abs(auton);
                    lv_btnm_set_toggle(redBtnm, true, abs(auton) - 1);
                }
                else if (activeTab == 1)
                {
                    if (auton == 0)
                        auton = -1;
                    auton = -abs(auton);
                    lv_btnm_set_toggle(blueBtnm, true, abs(auton) - 1);
                }
                else
                {
                    auton = 0;
                }
            }

            pros::delay(20);
        }
    }
    void init(int hue, int default_auton, const char **autons)
    {

        int i = 0;
        do
        {
            memcpy(&btnmMap[i], &autons[i], sizeof(&autons));
            i++;
        } while (strcmp(autons[i], "") != 0);

        autonCount = i;
        auton = default_auton;

        // lvgl theme
        lv_theme_t *th = lv_theme_alien_init(hue, NULL); // Set a HUE value and keep font default RED
        lv_theme_set_current(th);

        // create a tab view object
        tabiew = lv_tabview_create(tab1, NULL);

        // add 3 tabs (the tabs are page (lv_page) and can be scrolled
        lv_obj_t *redTab = lv_tabview_add_tab(tabiew, "Red");
        lv_obj_t *blueTab = lv_tabview_add_tab(tabiew, "Blue");
        lv_obj_t *skillsTab = lv_tabview_add_tab(tabiew, "Skills");

        // set default tab
        if (auton < 0)
        {
            lv_tabview_set_tab_act(tabview, 1, LV_ANIM_NONE);
        }
        else if (auton == 0)
        {
            lv_tabview_set_tab_act(tabview, 2, LV_ANIM_NONE);
        }

        // add content to the tabs
        // button matrix
        redBtnm = lv_btnm_create(redTab, NULL);
        lv_btnm_set_map(redBtnm, btnmMap);
        lv_btnm_set_action(redBtnm, redBtnmAction);
        lv_btnm_set_toggle(redBtnm, true, abs(auton) - 1); // 3
        lv_obj_set_size(redBtnm, 450, 50);
        lv_obj_set_pos(redBtnm, 0, 100);
        lv_obj_align(redBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

        // blue tab
        blueBtnm = lv_btnm_create(blueTab, NULL);
        lv_btnm_set_map(blueBtnm, btnmMap);
        lv_btnm_set_action(blueBtnm, *blueBtnmAction);
        lv_btnm_set_toggle(blueBtnm, true, abs(auton) - 1);
        lv_obj_set_size(blueBtnm, 450, 50);
        lv_obj_set_pos(blueBtnm, 0, 100);
        lv_obj_align(blueBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

        // skills tab
        lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
        lv_obj_t *label = lv_label_create(skillsBtn, NULL);
        lv_label_set_text(label, "Skills");
        lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, *skillsBtnAction);
        // lv_btn_set_state(skillsBtn, LV_BTN_STATE_TGL_REL);
        lv_obj_set_size(skillsBtn, 450, 50);
        lv_obj_set_pos(skillsBtn, 0, 100);
        lv_obj_align(skillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);
        
        // start tab watcher
        pros::Task tabWatcher_task(tabWatcher);
    }
}