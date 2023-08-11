#include "main.h"
#include <typeinfo>
#include <typeinfo>

#include <sstream>
using namespace std;

lv_obj_t *tabview;

lv_obj_t *tab1;
lv_obj_t *tab2;
lv_obj_t *tab3;
lv_obj_t *tab4;

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

    static void init()
    {
        task = lv_task_create(showMotors, 500, LV_TASK_PRIO_HIGHEST, NULL);
        tabview = lv_tabview_create(lv_scr_act(), NULL);
        /*Create a simple button style*/
        tab1 = lv_tabview_add_tab(tabview, "Tab 1");
        tab2 = lv_tabview_add_tab(tabview, "Auton");
        tab3 = lv_tabview_add_tab(tabview, "Motors");
        tab4 = lv_tabview_add_tab(tabview, "Debug");
        lv_tabview_set_tab_load_action(tabview, TabChange);
    }

private:
    static lv_res_t TabChange(lv_obj_t *tabview, uint16_t tab_id)
    {
        if (tab_id == 0)
        {
        }
        if (tab_id == 2)
        {
            lv_task_set_prio(task, LV_TASK_PRIO_HIGHEST);
            return LV_RES_OK;
        }
        else
        {
            lv_task_set_prio(task, LV_TASK_PRIO_OFF);
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
           << ((motor.get_temperature() == INFINITY) ? "Not Connected" : s.substr(0, s.find("."))) << "\n";
        // ss << "RPM/Velocity/Max: " << motor.get_target_velocity()
        //     << "/" << motor.get_actual_velocity() << "/" << gearing << "\n";
        // ss << "Gearing: " << motor.get_gearing() << "\n";
        // ss << "Voltage: " << motor.get_voltage() << "\n";
        // ss << "Torque: " << motor.get_torque() << "\n";

        return ss.str().c_str();
    }
};