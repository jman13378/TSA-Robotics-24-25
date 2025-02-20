#include "main.h"

#include <iostream>
#include <sstream>
#include <string>
namespace controls
{
        pros::controller_digital_e_t tankswitch = pros::E_CONTROLLER_DIGITAL_UP;

        pros::controller_digital_e_t driveSwitch = pros::E_CONTROLLER_DIGITAL_Y;
        pros::controller_digital_e_t armIn = pros::E_CONTROLLER_DIGITAL_L1;
        pros::controller_digital_e_t armOut = pros::E_CONTROLLER_DIGITAL_L2;
        pros::controller_digital_e_t clawIn = pros::E_CONTROLLER_DIGITAL_R1;
        pros::controller_digital_e_t clawOut = pros::E_CONTROLLER_DIGITAL_R2;
        pros::controller_digital_e_t speedTgl = pros::E_CONTROLLER_DIGITAL_RIGHT;

}

/*



*/

/*
<R12> Motors are limited. Robots may use any combination of VEX V5 Smart Motors (11W) (276-
4840) and V5 Smart Motors (5.5W) (276-4842), within the following criteria:
        a. The combined power of all motors (11W & 5.5W) must not exceed 88W.
        b. V5 Smart Motors, connected to Smart Ports, are the only motors that may be used with a V5
Robot Brain. The 3-wire ports may not be used to control motors of any kind.

Examples of legal motor combinations:
        Example A B C D E
        Qty of 11W Motors: 8 7 6 5 0
        Qty of 5.5W Motors: 0 2 4 6 16

<R12> Motors are limited. Robots may use any combination of VEX V5 Smart Motors (11W) (276-
4840) and V5 Smart Motors (5.5W) (276-4842), within the following criteria:
a. The combined power of all motors (11W & 5.5W) must not exceed 88W.
b. V5 Smart Motors, connected to Smart Ports, are the only motors that may be used with a V5
Robot Brain. The 3-wire ports may not be used to control motors of any kind.
*/

pros::Motor Arm(19, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor Arm2(17, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor Claw(18, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Controller controller2(pros::E_CONTROLLER_PARTNER);
bool DriveReverse = false;
int brain = 0;
bool speedTgl = false;
