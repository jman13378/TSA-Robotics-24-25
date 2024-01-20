#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

double fwerror;

double target;
double output;

double tbh;

double prev_error;

double gain = 0.08;

double kV = 1;
double totalOutput;

void setOutput()
{
    if (target <= 25)
        output = 0.25 * (output + tbh);
    else if (target <= 50 && target > 25)
        output = 0.3 * (output + tbh);
    else if (target <= 75 && target > 50)
        output = 0.4 * (output + tbh);
    else
        output = 0.45 * (output + tbh);
}

bool upToSpeed = false;

int FlyWheelControlTask()
{
    while (1)
    {
        fwerror = target - FlyWheel.get_actual_velocity();
        output += gain * fwerror;

        if (std::signbit(fwerror) != std::signbit(prev_error))
        {
            setOutput();
            tbh = output;
            prev_error = fwerror;
        }

        output = std::clamp(output, -12000.0, 12000.0);

        totalOutput = output + (kV * target);

        if (target != 0)
        {
            if (FlyWheel.get_actual_velocity() > target - 10 && !upToSpeed)
            {
                upToSpeed = true;
                controller.rumble(".");
            }

            FlyWheel.move(totalOutput);
        }

        else
        {
            FlyWheel.move(0);
            upToSpeed = false;
        }

        pros::delay(10);
    }

    return 1;
}

bool b = false;

void wait()
{
    int tempTime = pros::millis();
    int curTime = pros::millis();

    if (!b)
    {
        while (tempTime + 2000 >= curTime)
        {
            pros::delay(1);
            curTime = pros::millis();
        }
        b = true;
    }
}

int n = 1;

void setFlyWheelMotors()
{
    while (true)
    {
        FlyWheel.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        if (controller.get_digital(controls::FlyWheel70) || controller.get_digital(controls::FlyWheel100))
        {
            if (controller.get_digital(controls::FlyWheel70))
                target = 70;
            else if (controller.get_digital(controls::FlyWheel100))
                target = 100;
        }
        else if (n == 1)
        {
            n = 1;
            target = 70;
        }
        else
        {
            target = 0;
        }
        pros::delay(10);
    }
}