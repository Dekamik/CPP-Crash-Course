//
// Created by Denni on 2022-11-16.
//

#include <cstdio>
#include "BufferOverflow.h"

bool is_within_bounds(const char array[], const size_t index) {
    size_t size = sizeof(&array) / sizeof(char);
    return index < size;
}

char read_from(const char array[], const size_t index) {
    if (!is_within_bounds(array, index)) {
        printf("Error: index out of bounds\n");
        return '-';
    }
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArrayIndexOutOfBounds"
    // ArrayIndexOutOfBounds handled by previous if-statement
    return array[index];
#pragma clang diagnostic pop
}

void write_to(char array[], const size_t index, const char c) {
    if (!is_within_bounds(array, index)) {
        printf("Error: index out of bounds\n");
        return;
    }
    array[index] = c;
}

int BufferOverflow::main()
{
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char* upper_ptr = upper;    // Equivalent: &upper[0]

    lower[3] = 'd';     // lower now contains a b c d e \0
    upper_ptr[3] = 'D'; // upper now contains A B C D E \0

    char letter_d = lower[3];       // letter_d equals 'd'
    char letter_D = upper_ptr[3];   // letter_D equals 'D'

    printf("lower: %s\nupper: %s\n", lower, upper);

    lower[7] = 'g'; // Awful. Never do this

    size_t index = -1;
    printf("read_from[%zu]: %c\n", index, read_from(lower, index));

    return 0;
}
