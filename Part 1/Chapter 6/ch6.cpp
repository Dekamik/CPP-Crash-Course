//
// Created by Denni on 2022-11-17.
//

#include <map>
#include <vector>
#include <cstdio>
#include "ch6.h"

using namespace std;

int ch6::main()
{
    // Compile-time polymorphism
    long* values = new long[] {
        1,
        1,
        2,
        2,
        2,
        3,
        3,
        4
    };
    auto mode = ch6::mode(values, 8);
    printf("Mode is %d", mode);
    return 0;
}

template <typename T>
bool sort_by_sec_desc(const pair<T, int> &a, const pair<T, int> &b)
{
    return (a.second > b.second);
}

template <typename T>
int ch6::mode(const T* values, size_t length)
{
    if (length == 0)
        return 0;

    map<T, int> value_modes;

    for (size_t i = 0; i < length; i++)
    {
        if (value_modes.contains(values[i]))
        {
            value_modes[values[i]]++;
            continue;
        }
        value_modes.insert(pair<T, int>(values[i], 1));
    }

    vector<pair<T, int> > v{ value_modes.begin(), value_modes.end() };
    sort(v.begin(), v.end(), sort_by_sec_desc<T>);

    if (v[0].second == v[1].second)
        return 0;

    return v[0].first;
}
