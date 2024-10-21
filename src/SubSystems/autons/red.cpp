#include "main.h"
#include <iostream>
#include <sstream>
#include <string>
namespace autons
{

    void redLeftStart()
    {
        blueRightStart();
        // arms::chassis::leftMotors.get(0)->move(127);
        //         arms::chassis::leftMotors.get(1)->move(127);
        //         arms::chassis::rightMotors.get(0)->move(-127);
        //         arms::chassis::rightMotors.get(1)->move(-127);

    }

    void redRightStart()
    {
        blueRightStart();
    }
}