#pragma once

#include <string>

//selector configuration
#define DEFAULT 0
#define AUTONS "Left", "Right", "Do Nothing"

namespace selector{
    extern int auton;
    const char *b[] = {AUTONS, ""};
    void init(int default_auton = DEFAULT, const char **autons = b);
    void shutdown();
    void runauton();
    void debugRuns();
}