#include "main.h"

int range[2]{111, 77};

//     Intake.move((127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))-(127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)));

void setIntake(int power)
{
    Intake.move(power);
}
bool isTriBall(pros::Optical op)
{
    double hue = op.get_hue();
    return (hue <= range[0] && hue >= range[1]);
}
void setIntakeMotor()
{
    bool isReverse = false;
    bool isForward = false;
    int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
    isReverse = (intakePower > 0 ? false : true);
    isForward = (intakePower < 0 ? false : true);
    if (isTriBall(IntakeOpticalIn) && isForward)
    {
        setIntake(0);
        return;
    }

    if (isTriBall(IntakeOpticalOut) && !isReverse)
        intakePower = 127;
    setIntake(intakePower);
}