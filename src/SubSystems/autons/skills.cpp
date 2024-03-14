#include "main.h"
#include <iostream>

namespace autons
{

    void autonSkills()
    {
                IntakeOut = true;
        setIntakePiston(IntakeOut);
        FlyWheel.move(FlyWheelPower);
    }
}