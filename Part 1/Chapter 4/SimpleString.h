//
// Created by dennis on 2022-11-17.
//

#ifndef PART_1_SIMPLESTRING_H
#define PART_1_SIMPLESTRING_H


#include <cstdio>

class SimpleString {
public:
    explicit SimpleString(size_t max_size);
    ~SimpleString();
    SimpleString(const SimpleString& other);
    SimpleString(const SimpleString&& other) noexcept;

    SimpleString& operator=(const SimpleString& other);
    SimpleString& operator=(SimpleString&& other) noexcept;

    void print(const char* tag) const;
    bool append_line(const char* x);

private:
    size_t max_size;
    char* buffer;
    size_t length;
};


#endif //PART_1_SIMPLESTRING_H
