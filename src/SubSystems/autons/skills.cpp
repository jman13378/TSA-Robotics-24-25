#include "main.h"
namespace autons
{
    void autonskills()
    {
        arms::odom::reset({0, 0}, 0); // Reset point

        arms::chassis::turn(90, 100,0.25);
    }
}