#include "main.h"
#include "ARMS/config.h"
#include "ui.h"
#include <map>
#include <iostream>
#include <sstream>
#include <string>
std::stringstream mapper("t");

bool debug = true;
void initialize()
{
    // pros::Task Flywheelcontrol(FlyWheelControlTask);

    // pros::Task CataController(cataControl);
    std::cout << "init1" << std::endl;
    arms::init();
    arms::selector::destroy();
    selector::init(-2);
    while ((*arms::odom::imu).is_calibrating())
    {
        pros::delay(10);
    }
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
    IntakeOut = true;
    printf(mapper.str().c_str());
    selector::runauton();
    //  selector::runauton();

    // if (au)
    //   arms::odom::reset({0, 0}, 0);
    // au=false;
    // chassis::move({24, 0,0}, 100);
}

void opcontrol()
{
    std::cout << "op1" << std::endl;

        std::cout << "Hello, World!" << FlyWheelPower << std::endl;

    IntakeOut = true;
    arms::odom::reset({0, 0}, 0);
    // arms::chassis::move({0, 0, 0}, 100, 0.25);
    arms::chassis::setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
    while (true)
    {
    if (controller.get_digital_new_press(controls::driveSwitch))
        std::cout << "x: " << arms::odom::getPosition().x << "y" << arms::odom::getPosition().y << std::endl;
        selector::debugRuns();
        setFlyWheelMotors();
        setDriveMotors();
        setIntakeMotor();
        setPistonStates();
        //FreezeTag();
        pros::delay(10);
    }
}
