#include "main.h"
#include "pros/misc.h"
void setIntakePiston(bool trigger) {
    IntakePu1.set_value(trigger);
    IntakePu2.set_value(trigger);

}

void setPistonStates() {
    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {IntakeOut = false;
        setIntakePiston(false);}
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){IntakeOut = true;
        setIntakePiston(true);}
}