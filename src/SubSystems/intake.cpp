#include "main.h"

int hueRange[2]{111, 77};
bool overrideIntake = false;
//     Intake.move((127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))-(127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)));

void setIntake(int power)
{
    Intake.move(power);
}
bool isTriBall(pros::Optical op)
{
    double hue = op.get_hue();
    return (hue <= hueRange[0] && hue >= hueRange[1]);
}
void setIntakeMotor()
{
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        overrideIntake= (overrideIntake ? false : true);
    }
    controller.print(0, 0, "override:%g", (overrideIntake ? 1.0 : 0.0));
    bool isReverse = false;
    bool isForward = false;
    int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
    isReverse = (intakePower > 0 ? false : true);
    isForward = (intakePower < 0 ? false : true);
    if (!overrideIntake)
    {
        if (isTriBall(IntakeOpticalIn) && isForward)
        {
            setIntake(0);
            return;
        }

        if (isTriBall(IntakeOpticalOut) && !isReverse)
            intakePower = 12;
    }
    setIntake(intakePower);
}