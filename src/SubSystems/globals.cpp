#include "main.h"

#include <iostream>
#include <sstream>
#include <string>
namespace controls
{
        pros::controller_digital_e_t tankswitch = pros::E_CONTROLLER_DIGITAL_UP;

        pros::controller_digital_e_t driveSwitch = pros::E_CONTROLLER_DIGITAL_Y;

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







pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Controller controller2(pros::E_CONTROLLER_PARTNER);
bool DriveReverse = false;



