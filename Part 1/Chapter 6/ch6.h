//
// Created by Denni on 2022-11-17.
//

#ifndef PART_1_CH6_H
#define PART_1_CH6_H


#include <cstdlib>
#include <concepts>

template<typename T>
concept Integer = std::is_integral<T>::value;

class ch6
{
public:
    static int main();
};


#endif //PART_1_CH6_H
