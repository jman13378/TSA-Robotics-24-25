#include "main.h"
#define PNEUMATICA 'A'
#define PNEUMATICB 'B'
#define PNEUMATICC 'C'
#define PNEUMATICD 'D'
#define PNEUMATICE 'E'
#define PNEUMATICF 'F'
#define PNEUMATICG 'G'
#define PNEUMATICH 'H'


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

#ifndef _PORTS
#define _PORTS
/**
 * radio - 21
 * IMU - 2
 * 
 *  
*/

pros::ADIDigitalOut IntakePu1(PNEUMATICA);

pros::Motor Intake(13,pros::E_MOTOR_GEAR_GREEN,false);

pros::Motor Strafe(12, pros::E_MOTOR_GEAR_GREEN, true); // 11W


pros::Motor FLeft(19, pros::E_MOTOR_GEAR_BLUE, true); // 11W
pros::Motor RLeft(10, pros::E_MOTOR_GEAR_BLUE, true); // 11W

// left motors
// placeholder numbers 

pros::Motor FRight(11, pros::E_MOTOR_GEAR_BLUE, false); // 11W
pros::Motor RRight(1, pros::E_MOTOR_GEAR_BLUE, false);  // 11W
#endif /* _MY_HEADER_H_ */