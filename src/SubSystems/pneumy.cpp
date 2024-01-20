#include "main.h"
#include "pros/misc.h"
void setEndGamePiston(bool trigger)
{
    EndGame1.set_value(trigger);
    EndGame2.set_value(trigger);
}

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
    if (controller.get_digital(controls::EndGame1) && (controls::EndGame2 != 6 ? controller.get_digital(controls::EndGame2) : true))
    {
        printf("%l","1");
        EndGameOut = EndGameOut ? false : true;
    }
    setIntakePiston(IntakeOut);
    setWingPiston(WingsOut);
    printf("%l","2");
    setEndGamePiston(EndGameOut);
    printf("%l","3");
    
}