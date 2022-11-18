//
// Created by dennis on 2022-11-17.
//

#include <cstring>
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
    : max_size{ other.max_size },
    length{ other.length },
    buffer{ new char[max_size] }
{
    max_size = other.max_size;
    length = other.length;
    std::strncpy(buffer, other.buffer, length);
}

SimpleString::SimpleString(SimpleString &&other) noexcept
    : max_size{ other.max_size },
    length{ other.length },
    buffer{ other.buffer }
{
    other.max_size = 0;
    other.length = 0;
    other.buffer = nullptr;
}

SimpleString &SimpleString::operator=(const SimpleString &other)
{
    if (this == &other)
        return *this;

    const auto new_buffer = new char[sizeof(other.buffer)];
    delete[] buffer;
    buffer = new_buffer;

    max_size = other.max_size;
    length = other.length;
    std::strncpy(buffer, other.buffer, length);

    return *this;
}

SimpleString &SimpleString::operator=(SimpleString &&other) noexcept
{
    delete[] buffer;

    max_size = other.max_size;
    length = other.length;
    buffer = other.buffer;

    other.max_size = 0;
    other.length = 0;
    other.buffer = nullptr;

    return *this;
}

void SimpleString::print(const char *tag) const
{
    printf("%s: %s", tag, buffer);
}

bool SimpleString::append_line(const char *x)
{
    
}
