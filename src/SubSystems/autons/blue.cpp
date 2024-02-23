#include "main.h"
#include <iostream>
#include <sstream>
#include <string>
namespace autons
{

    void setBlueHue()
    {
        int i = 1;
        if (hueRange[1][0] == 145769)
            i = 2;
        hueRange[i][0] = 215;
        hueRange[i][1] = 150;
    }

    void blueRightStart()
    {
        // account for the blue triballs(pre-load)
        setBlueHue();
        IntakeOut = true;
        setIntakePiston(IntakeOut);



        arms::odom::reset({0, 0}, 0); // Reset point

        arms::chassis::move({32, 0, 270}, 100, 0.250);

        // arms::chassis::move({30.5, -2}, 100, 0.25);
        while (isTriBall(IntakeOpticalIn) || isTriBall(IntakeOpticalOut))
            Intake.move(-127);
        Intake.move(0);


        arms::chassis::move({32, 5}, 100, 0.25, arms::REVERSE);
        arms::chassis::move({23, 20}, 100, 0.25);

        while (!isTriBall(IntakeOpticalIn) && isTriBall(IntakeOpticalOut))
            Intake.move(127);
        Intake.move(0);
        arms::chassis::move({30, 0, 270}, 100, 0.25);

        while (isTriBall(IntakeOpticalIn) || isTriBall(IntakeOpticalOut))
            Intake.move(-127);
        Intake.move(0);
        IntakeOut = false;
        setIntakePiston(IntakeOut);
                arms::chassis::move({30, 10}, 100, 0.25, arms::REVERSE);

        arms::chassis::move({30, -20}, 100, 0.25);
        
    }

    void blueLeftStart()
    {
        setBlueHue();
    }
}