// #include "main.h"

// void wait()
// {
//     bool b = false;

//     int tempTime = pros::millis();
//     int curTime = pros::millis();

//     if (!b)
//     {
//         while (tempTime + 380 >= curTime)
//         {
//             pros::delay(1);
//             curTime = pros::millis();
//         }
//         b = true;
//     }
// }

// void wait2()
// {
//     bool b = false;

//     int tempTime = pros::millis();
//     int curTime = pros::millis();

//     if (!b)
//     {
//         while (tempTime + 170 >= curTime)
//         {
//             pros::delay(1);
//             curTime = pros::millis();
//         }
//         b = true;
//     }
// }

// bool shoot = false;

// int cataControl()
// {
//     bool beenPressed = false;
//     while (1)
//     {
//         if (!CataBumper.get_value() && !beenPressed)
//         {
//             Catapult.move(127);
//         }
//         else if (CataBumper.get_value() || beenPressed)
//         {
//             beenPressed = true;
//             Catapult.move(0);
//             if (beenPressed  && (controller.get_digital_new_press(controls::cata) || shoot))
//             {
//                 Catapult.move(127);
//                 wait();
//                 beenPressed = false;
//                 shoot = false;
//             }
//         }

//         pros::delay(10);
//     }
// }