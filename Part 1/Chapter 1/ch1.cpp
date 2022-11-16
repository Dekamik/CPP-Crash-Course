//
// Created by dennis on 2022-11-14.
//

#include <cstdio>
#include "ch1.h"

int ch1::absolute_value(int x) {
    if (x >= 0)
        return x;
    return x * -1;
}

int ch1::main() {
    // Basics
    int my_num = -10;
    printf("The absolute value of %d is %d.\n", my_num, absolute_value(my_num));
    return 0;
}
