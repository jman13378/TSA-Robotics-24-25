#include "main.h"
namespace autons
{

    void redLeftStart()
    {
                        arms::odom::reset({0, 0}, 0); // Reset point

        arms::chassis::move({2,0});
        controller.print(0,0,"%lf %lf", arms::odom::getPosition().x,arms::odom::getPosition().y);

    }

    void redRightStart()
    {
    }
}