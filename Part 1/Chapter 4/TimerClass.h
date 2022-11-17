//
// Created by Denni on 2022-11-17.
//

#ifndef PART_1_TIMERCLASS_H
#define PART_1_TIMERCLASS_H


struct TimerClass
{
    char* name;
    long int timestamp;

    explicit TimerClass(const char* name);
    TimerClass(const TimerClass& other);
    TimerClass(TimerClass&& other) noexcept;

    ~TimerClass();

    TimerClass& operator=(const TimerClass& other);
    TimerClass& operator=(TimerClass&& other) noexcept;

private:
    static long int get_millis_since_epoch();
};


#endif //PART_1_TIMERCLASS_H
