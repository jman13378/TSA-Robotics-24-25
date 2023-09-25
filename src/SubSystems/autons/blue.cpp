#include "main.h"

void blueLeftStart() {
    		    controller.print(0,0,"x:%g y:%g",arms::odom::getPosition().x,arms::odom::getPosition().y);

 arms::chassis::move({0,24,0},100);
 		    controller.print(0,0,"x:%g y:%g",arms::odom::getPosition().x,arms::odom::getPosition().y);

}

void blueRightStart() {
    
}