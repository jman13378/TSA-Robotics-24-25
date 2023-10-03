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
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP))
    {
        overrideIntake = (overrideIntake ? false : true);
    }
    controller.print(0, 0, "override:%g", (overrideIntake ? 1.0 : 0.0));
    bool isReverse = false;
    bool isForward = false;
    int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
    isReverse = (intakePower > 0 ? false : true);
    isForward = (intakePower < 0 ? false : true);
    if (!overrideIntake)
    {
        printf("1");

            // if tri ball is detected and the intake is spinning forward
            if (isTriBall(IntakeOpticalIn) && isForward)
        {
            printf("2");

                intakePower = 0;
            // return;
        }
        printf("3");
            // if tri ball is detected and the intake is NOT spinning backwards

            if (isTriBall(IntakeOpticalOut) && !isReverse)
        {
            printf("4");

                intakePower = 127;
        }
        printf("5");
    }
    printf("6\n");

        setIntake(intakePower);
}