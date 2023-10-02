#include "main.h"

//     Intake.move((127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))-(127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)));

void setIntake(int power)
{
    Intake.move(power);
}
bool isTriBall(pros::Optical op)
{
    double hue = op.get_hue();
    return (hue <= 111 && hue >= 77);
}
void setIntakeMotor()
{

    int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));

    if (isTriBall(IntakeOpticalIn) && intakePower > 0)
    {
        setIntake(0);
        return;
    }
    if (isTriBall(IntakeOpticalOut))
        intakePower = -127;

    setIntake(intakePower);
}