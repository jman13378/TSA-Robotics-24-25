#include "main.h"
#include <iostream>
#include <sstream>
#include <string>
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
        std::stringstream loid("t");
        IntakeOut = true;

        arms::odom::reset({0, 0}, 0); // Reset point
        loid << arms::odom::getPosition().x << "," << arms::odom::getPosition().y << std::endl;

        arms::chassis::move({30.5, 0, 270}, 100, 0.2);
        loid << arms::odom::getPosition().x << "," << arms::odom::getPosition().y << std::endl;

        // arms::chassis::move({30.5, -2}, 100, 0.25);
        while (isTriBall(IntakeOpticalIn) || isTriBall(IntakeOpticalOut))
            Intake.move(-127);
        Intake.move(0);

        arms::chassis::move({30.5, -7}, 100, 0.25);
        loid << arms::odom::getPosition().x << "," << arms::odom::getPosition().y << std::endl;

        arms::chassis::move({30, 15}, 100, 0.25);
        loid << arms::odom::getPosition().x << "," << arms::odom::getPosition().y << std::endl;

        while (!isTriBall(IntakeOpticalIn) && isTriBall(IntakeOpticalOut))
            Intake.move(127);
        Intake.move(0);
        arms::chassis::move({30.5, 0, 270}, 100, 0.25);
        loid << arms::odom::getPosition().x << "," << arms::odom::getPosition().y << std::endl;

        while (isTriBall(IntakeOpticalIn) || isTriBall(IntakeOpticalOut))
            Intake.move(-127);
        Intake.move(0);
        arms::chassis::move({30.5, -2}, 100, 0.25);
        loid << arms::odom::getPosition().x << "," << arms::odom::getPosition().y << std::endl;
        lv_obj_t *label = lv_label_create(lv_scr_act(), NULL);
        lv_label_set_text(label, loid.str().c_str());
    }

    void blueRightStart()
    {
        setHue();
    }
}