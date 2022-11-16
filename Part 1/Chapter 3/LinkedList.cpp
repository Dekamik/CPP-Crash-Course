//
// Created by Denni on 2022-11-16.
//

#include <cstdio>
#include "LinkedList.h"

struct Element {
    Element* next{};
    Element* previous{};

    void insert_after(Element* new_element) {
        new_element->next = next;
        new_element->previous = this;
        next = new_element;
    }

    void insert_before(Element* new_element) {
        new_element->previous = previous;
        new_element->next = this;
        previous = new_element;
    }

    char prefix[2];
    short operating_number;
};

void print_trooper(const Element* trooper) {
    printf("stormtrooper %c%c-%d\n",
           trooper->prefix[0],
           trooper->prefix[1],
           trooper->operating_number);
}

int LinkedList::main()
{
    Element trooper1, trooper2, trooper3;
    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421;
    trooper1.insert_after(&trooper2);
    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;
    trooper2.insert_after(&trooper3);
    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 005;    // Is interpreted as an octal due to leading 0

    // cursor assigned to first trooper ; returns true as long as cursor is not nullptr ; goes to next at end of loop
    for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
        print_trooper(cursor);
    }

    for (Element* cursor = &trooper3; cursor; cursor = cursor->previous) {
        print_trooper(cursor);
    }
    return 0;
}
