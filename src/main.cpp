#include "main.h"
#include "ARMS/config.h"
#include "ui.h"
#include <map>
#include <iostream>
#include <sstream>
#include <string>
std::chrono::_V2::steady_clock::time_point start_time = std::chrono::steady_clock::now();
std::chrono::_V2::steady_clock::time_point auton_time;
std::chrono::_V2::steady_clock::time_point drive_time;
std::stringstream mapper("t");
bool debug = true;
void initialize()
{
    Arm.set_brake_mode(pros::motor_brake_mode_e_t::E_MOTOR_BRAKE_HOLD);
    Arm2.set_brake_mode(pros::motor_brake_mode_e_t::E_MOTOR_BRAKE_HOLD);
    Claw.set_brake_mode(pros::motor_brake_mode_e_t::E_MOTOR_BRAKE_HOLD);
    std::cout << "init1" << std::endl;
    arms::init();
    arms::selector::destroy();
    selector::init(-2);

    std::cout << "init2" << std::endl;
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

void autonomous()
{

    std::cout << "auton1" << std::endl;

    selector::shutdown();
    printf(mapper.str().c_str());
    selector::runauton();
}

void opcontrol()
{
    std::cout << "op1" << std::endl;
    std::cout << "Running Brain in " << (brain == 0 ? "DriveBase" : "Arm") << " Mode" << std::endl;

    arms::odom::reset({0, 0}, 0);
    // arms::chassis::move({0, 0, 0}, 100, 0.25);
    arms::chassis::setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    drive_time = std::chrono::steady_clock::now();
    while (true)
    {

        // End time: calculate it when you need to measure the elapsed time
        auto end_time = std::chrono::steady_clock::now();

        // Calculate the elapsed time in milliseconds
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - drive_time);

        // Convert to seconds and milliseconds
        int seconds = duration.count() / 1000;      // Total seconds
        int milliseconds = duration.count() % 1000; // Remaining milliseconds
        int elapsed_seconds = duration.count() / 1000;
        seconds %=60;

if (elapsed_seconds>=10 && elapsed_seconds<=13) selector::shutdown();
        selector::debugRuns();
        setDriveMotors();
        setClawMotors();
        setPistonStates();
        pros::delay(10);
    }
}
