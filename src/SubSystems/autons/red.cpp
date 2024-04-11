#include "main.h"
#include <iostream>
#include <sstream>
#include <string>
namespace autons
{
    void setRedHue()
    {
        int i = 1;
        if (hueRange[1][0] == 145769)
            i = 2;
        hueRange[i][0] = 30;
        hueRange[i][1] = 10;
    }
    void redLeftStart()
    {
        arms::odom::reset({0, 0}, 0); // Reset point
        setRedHue();
        blueRightStart();
        // arms::chassis::leftMotors.get(0)->move(127);
        //         arms::chassis::leftMotors.get(1)->move(127);
        //         arms::chassis::rightMotors.get(0)->move(-127);
        //         arms::chassis::rightMotors.get(1)->move(-127);

    }

    void redRightStart()
    {
        arms::odom::reset({0, 0}, 0); // Reset point
        setRedHue();
        blueRightStart();
    }
}