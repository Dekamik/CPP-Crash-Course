//
// Created by Denni on 2022-11-15.
//

#include <cstdio>
#include "ch2.h"

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Operation operation;

    Calculator(Operation operation) {
        this->operation = operation;
    }

    int calculate(int a, int b) {
        switch (operation) {
            case Operation::Add: {
                return a + b;
            }

            case Operation::Subtract: {
                return a - b;
            }

            case Operation::Multiply: {
                return a * b;
            }

            case Operation::Divide: {
                return a / b;
            }

            default: {
                printf("Error: Unknown operation");
                return -1;
            }
        }
    }
};

int ch2::main()
{
    // Types
    Operation op = Operation::Add;
    Calculator c = Calculator{op};

    int result = c.calculate(100, 100);
    printf("The result is: %d", result);

    return 0;
}
