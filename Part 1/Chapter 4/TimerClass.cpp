//
// Created by Denni on 2022-11-17.
//

#include <sys/time.h>
#include <cstdio>
#include <cstring>
#include "TimerClass.h"

TimerClass::TimerClass(const char* name) : name{ new char[sizeof(name)] }
{
    std::strncpy(this->name, name, sizeof(&name));

    timestamp = get_millis_since_epoch();
}

TimerClass::~TimerClass()
{
    long int age = get_millis_since_epoch() - timestamp;
    printf("%s: %ld", name, age);
}

TimerClass::TimerClass(const TimerClass& other)
    : name{ new char[sizeof(other.name)] },
    timestamp{ other.timestamp }
{
    std::strncpy(this->name, name, sizeof(&name));
}

TimerClass::TimerClass(TimerClass&& other) noexcept
    : name{ other.name },
    timestamp{ other.timestamp }
{
    other.name = nullptr;
    other.timestamp = 0;
}

TimerClass& TimerClass::operator=(const TimerClass& other)
{
    if (this == &other)
        return *this;

    const auto new_name = new char[sizeof(other.name)];
    delete[] name;
    name = new_name;
    std::strncpy(name, other.name, sizeof(&other.name));

    timestamp = other.timestamp;

    return *this;
}

TimerClass& TimerClass::operator=(TimerClass&& other) noexcept
{
    if (this == &other)
        return *this;

    delete[] name;

    name = other.name;
    timestamp = other.timestamp;

    other.name = nullptr;
    other.timestamp = 0;

    return *this;
}

/**
 * This is how you do it C-style
 **/
long int TimerClass::get_millis_since_epoch()
{
    struct timeval tp{};
    gettimeofday(&tp, nullptr);
    return tp.tv_sec * 1000 + tp.tv_usec / 1000;
}
