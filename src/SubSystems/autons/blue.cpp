#include "main.h"

void blueLeftStart()
{
    controller.print(0, 0, "x:%g y:%g", arms::odom::getPosition().x, arms::odom::getPosition().y);

arms::odom::reset({0,0}, 0); //Reset point

    arms::chassis::move(-4.8, 100,1, arms::REVERSE); //Move to get roller
    controller.print(0, 0, "x:%g y:%g", arms::odom::getPosition().x, arms::odom::getPosition().y);
}

void blueRightStart()
{
}