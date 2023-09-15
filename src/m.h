

// include okapi and pros
// the library itself
#include "main.h"
// include utils
#include "gif-pros/gifclass.hpp"
#include <list>
#include <iostream>
#include "ARMS/api.h"
#include "ARMS/config.h"
using namespace std;


Gif gif("/usd/mygif.gif", lv_scr_act());
/*class Debug
{
    static string lines[10];

public:
    static void addLine(string line)
    {
        lines->append(line);
    }
    static string getLine(int id) { return lines[id]; }
};*/

// controller
// better to init in this file than the ports file

pros::Controller controller(pros::E_CONTROLLER_MASTER);


#include "ports.hpp"
#include "menu.hpp"
#include "DriveTrain.hpp"

    // initialize variables

    // AFTER INCLUDE STMT
    //Debug debugger;

    UIManager ui;
