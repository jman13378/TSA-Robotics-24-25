#include "main.h"
namespace autons
{

    void autonSkills()
    {
        setRedHue();
        IntakeOut=true;
        setIntake(IntakeOut);
        arms::odom::reset({0, 0}, 90);
        //arms::chassis::move({18, 4, 45}, 100, 0.25);
        bool i = true;
        while(i) {

            if (SkillsDistance.get()>5) {
                arms::chassis::move({-140,0}, 100);

            }
                FlyWheel.move(90);

        }
    }
}