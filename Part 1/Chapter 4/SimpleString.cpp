//
// Created by dennis on 2022-11-17.
//

#include "SimpleString.h"

SimpleString::SimpleString(size_t max_size)
    : max_size{ max_size },
    length{ 0 },
    buffer{ new char[max_size] }
{

}

SimpleString::~SimpleString()
{
    delete[] buffer;
}

SimpleString::SimpleString(const SimpleString &other)
{

}

SimpleString::SimpleString(const SimpleString &&other) noexcept
{

}

SimpleString &SimpleString::operator=(const SimpleString &other)
{

}

SimpleString &SimpleString::operator=(SimpleString &&other) noexcept
{

}

void SimpleString::print(const char *tag) const
{

}

bool SimpleString::append_line(const char *x)
{

}
