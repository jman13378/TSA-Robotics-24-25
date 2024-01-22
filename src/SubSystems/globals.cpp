#include "main.h"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"

namespace controls
{
        pros::controller_digital_e_t intakeIn = pros::E_CONTROLLER_DIGITAL_L1;
        pros::controller_digital_e_t intakeOut = pros::E_CONTROLLER_DIGITAL_L2;
        pros::controller_digital_e_t intakePnu = pros::E_CONTROLLER_DIGITAL_R1;
        pros::controller_digital_e_t EndGame1 = pros::E_CONTROLLER_DIGITAL_LEFT;
        pros::controller_digital_e_t EndGame2 = pros::E_CONTROLLER_DIGITAL_UP;
        pros::controller_digital_e_t FlyWheel70 = pros::E_CONTROLLER_DIGITAL_X;
        pros::controller_digital_e_t FlyWheel100 = pros::E_CONTROLLER_DIGITAL_A;

        pros::controller_digital_e_t cata = pros::E_CONTROLLER_DIGITAL_RIGHT;
        pros::controller_digital_e_t wings = pros::E_CONTROLLER_DIGITAL_B;
        pros::controller_digital_e_t intakeOverride = pros::E_CONTROLLER_DIGITAL_DOWN;
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

int hueRange[3][2] = {{100, 80}, {145769, 145769}};
pros::ADIDigitalOut IntakePu1('A');
pros::ADIDigitalOut IntakePu2('B');

pros::ADIDigitalIn CataBumper('C');

pros::ADIDigitalOut WingPu1('D');
pros::ADIDigitalOut WingPu2('E');

pros::ADIDigitalOut EndGame1('F');
pros::ADIDigitalOut EndGame2('G');
pros::ADIDigitalOut Temp('H');

pros::Optical IntakeOpticalIn(2);

pros::Optical IntakeOpticalOut(3);

pros::Motor Intake(4, pros::E_MOTOR_GEAR_GREEN, false, pros::E_MOTOR_ENCODER_ROTATIONS);
pros::Motor FlyWheel(19, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Motor IntakeStartMotor(4, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_ROTATIONS);

pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Controller controller2(pros::E_CONTROLLER_PARTNER);
bool EndGameOut = false;
bool IntakeOut = false;
bool WingsOut = false;
bool DriveReverse = false;