//
// Created by Denni on 2022-11-16.
//

#include <thread>
#include "ch4.h"
#include "TimerClass.h"

int ch4::main()
{
    // Object lifecycle
    TimerClass t{ "Test" };
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return 0;
}
