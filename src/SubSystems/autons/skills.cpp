#include "main.h"
namespace autons
{
    void autonskills()
    {
        arms::odom::reset({0, 0}, 0);
        arms::chassis::turn(90, 100, arms::ASYNC);
        while (true) {
            printf("heading: %lf | target: %lf\n", arms::odom::getHeading(), arms::pid::angularTarget);
            pros::delay(10);
        }
    }
}