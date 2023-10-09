#include "main.h"
namespace autons
{
    void blueLeftStart()
    {

        arms::odom::reset({0, 0}, 90); // Reset point

        arms::chassis::move({0, 24}, 100, 0.25); // Move to get roller
    }

    void blueRightStart()
    {
    }
}