#include "main.h"
#include <iostream>

namespace autons
{

    void autonSkills()
    {
        arms::chassis::
                IntakeOut = true;
        setIntakePiston(IntakeOut);
        FlyWheel.move(FlyWheelPower);
    }
}