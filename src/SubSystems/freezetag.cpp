#include "main.h"
int disabletime = 3 ;
pros::Motor IntakeStartMotor(3, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_ROTATIONS);
int timespressed = 0;
bool Disabled = false;
pros::ADIDigitalIn FreezeTag1('G');
pros::ADIDigitalIn FreezeTag2('H');
int FreezeTag()
{
    Intake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
int speed = 0;
if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)==1) speed=127;
if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)==1) speed=-127;
if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)==1) timespressed=0;

    IntakeStartMotor.move(speed);
    controller.print(0, 0, "Pressed: %i", timespressed);

    if (FreezeTag1.get_value() == 1 || FreezeTag2.get_value() == 1)
    {
        timespressed++;
        controller.clear_line(0);
        Disabled = true;
        arms::chassis::leftMotors.get()->move(0);
        arms::chassis::rightMotors.get()->move(0);

        pros::delay(1000 * disabletime);
    }
    return 1;
}
