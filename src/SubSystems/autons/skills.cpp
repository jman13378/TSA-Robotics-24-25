#include "main.h"
namespace autons
{

    void autonSkills()
    {
        setBlueHue();
        setRedHue();
        arms::odom::reset({0, 0}, 90);
        arms::chassis::move({18, 4, 45}, 100, 0.25);
    }
}