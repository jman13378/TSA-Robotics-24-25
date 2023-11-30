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
        arms::odom::reset({0,0},90);
        
        //arms::chassis::turn(45, 100, 1);
        arms::chassis::move({0,60},100,0.25);

        arms::chassis::turn(0, 100, 1);

        arms::chassis::move({24, 60}, 100, 0.25);

        pros::delay(500);

        arms::chassis::move({0, 60}, 100, 0.25, arms::REVERSE);

        arms::chassis::turn(90, 100, 1);

        arms::chassis::move({0, 0}, 100, 0.25, arms::REVERSE);
    }
}