#include "main.h"
namespace autons
{
    void autonskills()
    {
        arms::odom::reset({0, 0}, 0);
        arms::chassis::turn(143, 100, arms::ASYNC);
        while (true) {
            printf("heading: %lf | target: %ld\n", arms::odom::getHeading(), arms::pid::angularTarget);
            pros::delay(10);
        }
    }
}