#include "main.h"

//     Intake.move((127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))-(127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)));

void setIntake(int power) {
    Intake.move(power);
}

void setIntakeMotor() {
    int intakePower = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
    setIntake(intakePower);
}