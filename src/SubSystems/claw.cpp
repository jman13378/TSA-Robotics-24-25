#include "main.h"

void setClawMotors()
{

    int ClawPower = 127 * (controller.get_digital(controls::clawOut) - controller.get_digital(controls::clawIn));
    int ArmPower = 70 * (controller.get_digital(controls::armOut) - controller.get_digital(controls::armIn));
setArm(ArmPower);
setClaw(ClawPower);
}
void setClaw(int power)
{
    Claw.move(power);
    
}
void setArm(int power)
{
    Arm.move(power);
    Arm2.move(power);
}