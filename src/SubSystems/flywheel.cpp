#include "main.h"

bool pressed = false;
void setFlyWheelMotors()
{

    if (controller.get_digital(controls::FlyWheel70))
        pressed = false;
    if (controller.get_digital(controls::FlyWheel100))
        pressed = true;
    FlyWheel.move(pressed ? FlyWheelPower: 0);
}