#include "main.h"
namespace autons
{
    void blueLeftStart()
    {
        controller.print(0, 0, "x:%g y:%g", arms::odom::getPosition().x, arms::odom::getPosition().y);

        arms::odom::reset({0, 0}, 270); // Reset point

        arms::chassis::move({5,24}, 100, 1,arms::REVERSE); // Move to get roller
    }

    void blueRightStart()
    {
    }
}