#include "main.h"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"

namespace controls
{
        pros::controller_digital_e_t cata = pros::E_CONTROLLER_DIGITAL_RIGHT;
        pros::controller_digital_e_t wings = pros::E_CONTROLLER_DIGITAL_Y;
}

/*
UP - Override Intake
LEFT -
RIGHT -
DOWN -
X -
A - cata
B -
Y -
L1 - INTAKE OUT
L2 - INTAKE IN
R1 - INTAKE PNU OUT/IN
R2 - WINGS PNU OUT/IN
1 -
2 - tank right
3 - tank left
4 -




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

// port 20 not working
// left motor
// placeholder numbers

/**
 * radio - 21
 * IMU - 2
 *
 *
 */

int hueRange[2][2] = {{111, 77}};
// no more intake
// pros::ADIDigitalOut IntakePu1('A');

// pros::ADIDigitalOut IntakePu2('B');
pros::ADIDigitalIn CataBumper('C');
pros::ADIDigitalOut WingPu1('D');
pros::ADIDigitalOut WingPu2('E');

pros::Optical IntakeOpticalIn(14);

pros::Optical IntakeOpticalOut(15);

pros::Motor Intake(13, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Motor Catapult(3, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Controller controller(pros::E_CONTROLLER_MASTER);
bool IntakeOut = false;
bool WingsOut = false;