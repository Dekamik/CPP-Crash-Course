//
// Created by dennis on 2022-11-17.
//

#include <cstring>
#include <stdexcept>
#include "SimpleString.h"

SimpleString::SimpleString(size_t max_size)
    : max_size{ max_size },
    length{}
{
    if (max_size == 0) {
        throw std::runtime_error{ "Max size must be alt least 1." };
    }

    buffer = new char[max_size];
    buffer[0] = 0;
}

SimpleString::~SimpleString()
{
    delete[] buffer;
}

SimpleString::SimpleString(const SimpleString &other)
    : max_size{ other.max_size },
    length{ other.length },
    buffer{ new char[other.max_size] }
{
    std::strncpy(buffer, other.buffer, max_size);
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

    const auto new_buffer = new char[other.max_size];
    delete[] buffer;
    buffer = new_buffer;

    max_size = other.max_size;
    length = other.length;
    std::strncpy(buffer, other.buffer, max_size);

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
    size_t x_len = strlen(x);
    if (x_len + length + 2 > max_size)
        return false;

    std::strncpy(buffer + length, x, max_size - length);
    length += x_len;

    buffer[length++] = '\n';
    buffer[length] = 0;
    return true;
}
