#include "main.h"

double percentPowerL = 100;
double percentPowerR = 100;
double lastTime = pros::millis();
double setPowerL = 0;
double setPowerR = 0;
bool tankswitch = false;
int sign(double x)
{
    if (x > 0)
        return 1;
    else if (x < 0)
        return -1;
    else
        return 0;
}

void setDriveMotors()
{
    if (controller.get_digital_new_press(controls::tankswitch))
    {
        tankswitch = !tankswitch;
    }
    if (controller.get_digital_new_press(controls::driveSwitch))
    {
        DriveReverse = !DriveReverse;
    }

    bool tank = true;
    // Tank
    // double leftJoyStick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    // double rightJoyStick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    // Arcade
    double leftJoyStick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    double rightJoyStick = controller.get_analog(tank && tankswitch
                                                     ? pros::E_CONTROLLER_ANALOG_RIGHT_Y
                                                     : pros::E_CONTROLLER_ANALOG_RIGHT_X);

    if (fabs(leftJoyStick) < 10)
        leftJoyStick = 0;
    if (fabs(rightJoyStick) < 10)
        rightJoyStick = 0;

    const double max_accel = 100.0 / 1000;
    setPowerL = leftJoyStick;
    setPowerR = rightJoyStick;

    double deltaL = setPowerL - percentPowerL;
    double deltaR = setPowerR - percentPowerR;
    double deltaTime = pros::millis() - lastTime;
    lastTime = pros::millis();

    if ((fabs(deltaL / deltaTime)) > max_accel && (deltaL * percentPowerL > 0))
        deltaL = sign(deltaL) * max_accel * deltaTime;
    if ((fabs(deltaR / deltaTime)) > max_accel && (deltaR * percentPowerR > 0))
        deltaR = sign(deltaR) * max_accel * deltaTime;
    percentPowerL += deltaL;
    percentPowerR += deltaR;
    if (percentPowerL > 127)
        percentPowerL = 127;
    if (percentPowerR > 127)
        percentPowerR = 127;

    if (controller.get_digital_new_press(controls::driveSwitch))
        DriveReverse = !DriveReverse;

    // Tank
    // arms::chassis::tank(percentPowerL, percentPowerR);
    percentPowerL = (DriveReverse ? -percentPowerL : percentPowerL);
    percentPowerR = (DriveReverse ? percentPowerR : percentPowerR);

    controller.print(0, 0, "Drive: %s", (DriveReverse ? "Reverse" : "Forward"));

    // controller.print(0, 0, "Drive: %s", (WingsOut ? "Reverse" : "Forward"));

    // Arcade
    if (tank && tankswitch)
        arms::chassis::tank(DriveReverse ? percentPowerR : percentPowerL, DriveReverse ? percentPowerL : percentPowerR);

    else
        arms::chassis::arcade(percentPowerL, percentPowerR);
}
