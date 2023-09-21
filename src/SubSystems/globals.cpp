#include "main.h"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"

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

// port 20 not working
// left motor
// placeholder numbers

/**
 * radio - 21
 * IMU - 2
 *
 *  
*/

pros::ADIDigitalOut IntakePu1('A');
pros::ADIDigitalOut IntakePu2('B');

pros::ADIDigitalIn CataBumper('C');

pros::Motor Intake(13,pros::E_MOTOR_GEAR_GREEN,false, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Motor  Catapult(3, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Controller controller(pros::E_CONTROLLER_MASTER);