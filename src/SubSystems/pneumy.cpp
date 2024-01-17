#include "main.h"
#include "pros/misc.h"
void setIntakePiston(bool trigger)
{
    IntakePu1.set_value(trigger);
    IntakePu2.set_value(trigger);
}
void setWingPiston(bool trigger)
{
    WingPu1.set_value(trigger);
    WingPu2.set_value(trigger);
}
void setPistonStates()
{
    if (controller.get_digital_new_press(controls::intakePnu))
    {
        IntakeOut = IntakeOut ? false : true;
    }
    if (controller.get_digital_new_press(controls::wings))
    {
        WingsOut = WingsOut ? false : true;
    }
    if (controller.get_digital_new_press(controls::driveSwitch))
    {
        DriveReverse = DriveReverse ? false : true;
    }
     setIntakePiston(IntakeOut);
    setWingPiston(WingsOut);
}