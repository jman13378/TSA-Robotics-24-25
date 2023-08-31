#include "m.h"
#include "main.h"

using namespace pros;
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button()
{
    static bool pressed = false;
    pressed = !pressed;
    if (pressed)
    {
        pros::lcd::set_text(2, "I was pressed!");
    }
    else
    {
        pros::lcd::clear_line(2);
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
    ui.init();
    // @TODO will mess with later
    /*pros::lcd::initialize();
    pros::lcd::set_text(1, "Hello PROS User!");

    pros::lcd::register_btn1_cb(on_center_button);

*/
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
void competition_initialize()
{
    ui.exit(); // exit the ui using the UIManager included in menu.hpp
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
// void opcontrol()
// {//{{4_in, 11.5_in}, okapi::imev5BlueTPR}
// 	auto chassis = okapi::ChassisControllerBuilder().withMotors(-19, -11, 1, 10).y.build();
// 	auto xModel = std::dynamic_pointer_cast<okapi::HDriveModel>(chassis->getModel());
// 	while (true)

// 	{

// 		/*
// 				int left = master.get_analog(ANALOG_LEFT_Y);
// 				int right = master.get_analog(ANALOG_RIGHT_Y);

// 				left_mtr = left;
// 				right_mtr = right;
// 		*/
// 		// drive
// chassis.
// 		xModel->tank(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y),
// 					 controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
// 		// xModel->arcade(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X),controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y),controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));

// 		pros::delay(20);
// 		/*FLeft.move(controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
// 		FRight.move(controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));

// 		RLeft.move(controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
// 		RRight.move(controller.get_analog(E_CONTROLLER_ANALOG_LEFT_Y));
// 		Strafe.move(controller.get_analog(E_CONTROLLER_ANALOG_RIGHT_X));
// 		pros::delay(20);
// 		*/
// 	}
// }
void opcontrol()
{
    while (true)
    {
        int r1=controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
        int r2=controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

    IntakePu1.set_value(r2==1 && r1==0? true : false);
    IntakePu2.set_value(r2==1 && r1==0? true : false);

        Intake.move((127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2))-(127*controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)));

        // Get joystick values
        int forward = controller.get_analog(ANALOG_LEFT_Y);
        int strafe = controller.get_analog(ANALOG_RIGHT_X);
        int rotate = controller.get_analog(ANALOG_LEFT_X);

        // Calculate motor powers for holonomic drive
        int frontLeftPower = forward + strafe + rotate;
        int frontRightPower = forward - strafe - rotate;
        int backLeftPower = forward - strafe + rotate;
        int backRightPower = forward + strafe - rotate;
        int strafePower = controller.get_analog(ANALOG_RIGHT_X);

        // Set motor powers
        FLeft.move(frontLeftPower);
        FRight.move(frontRightPower);
        RLeft.move(backLeftPower);
        RRight.move(backRightPower);
        Strafe.move(strafePower);

        delay(20); // Small delay to control loop speed
    }
}