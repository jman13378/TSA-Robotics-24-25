#include "main.h"
namespace autons
{
    void blueLeftStart()
    {

        arms::odom::reset({0, 0}, 0); // Reset point

        arms::chassis::move(48, 100, 0.25); // Move t o get roller
        arms::chassis::turn(90, 100);

        arms::chassis::move(24, 100, 0.25); // Move to get roller
        arms::chassis::turn(45, 100);
        arms::chassis::move(24, 100, 0.25,arms::REVERSE); // Move to get roller
    }

    void blueRightStart()
    {
    }
}