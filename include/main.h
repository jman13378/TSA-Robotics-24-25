/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * \copyright Copyright (c) 2017-2023, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convenient for most student programmers.
 */
#include "pros/adi.hpp"
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS
// default for pros
#include "api.h"

/**
 * You should add more #includes here
 */
// #include "okapi/api.hpp"
// #include "pros/api_legacy.h"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
// using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C"
{
#endif
    void autonomous(void);
    void initialize(void);
    void disabled(void);
    void competition_initialize(void);
    void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
// #include <iostream>
#endif

#endif // _PROS_MAIN_H_

#include "ARMS/api.h"

// initialize all motors and pneumatics

extern pros::Motor Intake;
extern pros::Motor FlyWheel;
extern pros::ADIDigitalOut IntakePu1;
extern pros::ADIDigitalOut IntakePu2;
extern pros::ADIDigitalOut WingPu1;
extern pros::ADIDigitalOut WingPu2;
extern pros::ADIDigitalOut EndGame1;
extern pros::ADIDigitalOut EndGame2;

/// initialize all variables

extern int hueRange[3][2];
extern bool debug;
extern bool WingsOut;
extern bool overrideIntake;
extern pros::Optical IntakeOpticalIn;
extern pros::Optical IntakeOpticalOut;
extern pros::Controller controller;
extern pros::Controller controller2;

// initialize functions
int FlyWheelControlTask();
void setFlyWheelMotors();
void setDriveMotors();
void setIntakeMotor();
void setIntake(int power);
bool isTriBall(pros::Optical op);
void setPistonStates();
void setIntakePiston(bool trigger);
void setWingPiston(bool trigger);
void setEndGamePiston(bool trigger);
int cataControl();

extern bool shoot;
extern bool IntakeOut;
extern bool EndGameOut;
extern pros::ADIDigitalIn CataBumper;
extern bool DriveReverse;
// initialize namespaces

namespace autons
{
    void redLeftStart();
    void redRightStart();
    void blueLeftStart();
    void blueRightStart();
    void autonSkills();
    void setRedHue();
    void setBlueHue();
}
namespace controls
{
    extern pros::controller_digital_e_t intakeIn;
    extern pros::controller_digital_e_t intakeOut;
    extern pros::controller_digital_e_t intakePnu;
    extern pros::controller_digital_e_t EndGame1;
    extern pros::controller_digital_e_t EndGame2;
    extern pros::controller_digital_e_t FlyWheel70;
    extern pros::controller_digital_e_t FlyWheel100;

    extern pros::controller_digital_e_t cata;
    extern pros::controller_digital_e_t wings;
    extern pros::controller_digital_e_t intakeOverride;

    extern pros::controller_digital_e_t driveSwitch;

}
// most objects will be initialized in globals.cpp
