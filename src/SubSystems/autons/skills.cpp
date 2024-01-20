#include "main.h"
namespace autons
{

    void autonSkills()
    {
        setBlueHue();
        setRedHue();
        arms::odom::reset({0, 0}, 0);
        arms::chassis::move({18, 0, 270}, 100, 0.25);
    }
}