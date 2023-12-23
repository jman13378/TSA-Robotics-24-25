#include "main.h"
#include "pros/misc.h"
// no more intake
// void setIntakePiston(bool trigger)
// {
//     IntakePu1.set_value(trigger);
//     IntakePu2.set_value(trigger);
// }
void setWingPiston(bool trigger)
{
    WingPu1.set_value(trigger);
    WingPu2.set_value(trigger);
}
void setPistonStates()
{
// no more intake
    // if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1))
    // {
    //     IntakeOut = IntakeOut ? false : true;
    // }
    if (controller.get_digital_new_press(controls::wings))
    {
        WingsOut = WingsOut ? false : true;
    }
        if (controller.get_digital_new_press(controls::driveSwitch))
    {
        DriveReverse = DriveReverse ? false : true;
    }
    //setIntakePiston(IntakeOut);
    setWingPiston(WingsOut);


}