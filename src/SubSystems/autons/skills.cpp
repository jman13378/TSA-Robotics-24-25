#include "main.h"
#include <iostream>

namespace autons
{

    void autonSkills()
    {
        IntakeOut = true;
        setIntake(IntakeOut);
        pros::delay(10000);
        FlyWheel.move(-127);
    }
}