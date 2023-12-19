#include "main.h"
namespace autons
{
    void autonskills()
    {
        double coords[2][3] = {{0,0,0},{27.7,7.6,42.8}};
        arms::odom::reset({0, 0}, 0);
        arms::chassis::move({coords[1][0],coords[1][1]},coords[1][2]);
        // arms::chassis::turn(90, 100, arms::ASYNC);
        // while (true)
        // {
        //     printf("heading: %lf | target: %lf\n", arms::odom::getHeading(), arms::pid::angularTarget);
        //     pros::delay(10);
        // }
    }
}