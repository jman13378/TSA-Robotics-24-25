#include "main.h"
namespace autons
{

    void setHue()
    {
        hueRange[1][0] = 215;
        hueRange[1][1] = 140;
    }
    void blueLeftStart()
    {
        // account for the blue triballs(pre-load)
        setHue();

        IntakeOut = true;
        setIntakePiston(true);
        arms::odom::reset({0, 0}, 0); // Reset point
        arms::chassis::move({42.5, 0}, 100, 0.25);
        arms::chassis::turn(270, 100, 0.25, 1.85);
        arms::chassis::move({42.5, -2}, 100, 0.25);

        while (isTriBall(IntakeOpticalIn) || isTriBall(IntakeOpticalOut))
            Intake.move(-127);
        Intake.move(0);
    
        arms::chassis::move({42.5, 5}, 100, 0.25);
        arms::chassis::move({30, 15}, 100, 0.25);
        while (!isTriBall(IntakeOpticalIn) && isTriBall(IntakeOpticalOut))
            Intake.move(127);
        Intake.move(0);
        arms::chassis::move({42.5, 0, 270}, 100, 0.25);
        while (isTriBall(IntakeOpticalIn) || isTriBall(IntakeOpticalOut))
            Intake.move(-127);
        Intake.move(0);
        arms::chassis::move({42.5, -3}, 100, 0.25);
    }

    void blueRightStart()
    {
        setHue();
    }
}