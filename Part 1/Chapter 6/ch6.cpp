//
// Created by Denni on 2022-11-17.
//

#include <map>
#include <vector>
#include <cstdio>
#include "ch6.h"

using namespace std;

template <Integer T>
bool sort_by_sec_desc(const pair<T, int> &a, const pair<T, int> &b)
{
    return (a.second > b.second);
}

template <Integer T>
int mode(const T* values, size_t length)
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

    if (v.size() > 1)
    {
        sort(v.begin(), v.end(), sort_by_sec_desc<T>);
        if (v[0].second == v[1].second)
            return 0;
    }

    return v[0].first;
}

template<typename T>
T mean(const T* values, size_t length)
{
    int m = 0;

    for (size_t i = 0; i < length; ++i)
    {
        m += values[i];
    }

    return m / length;
}

int ch6::main()
{
    // Compile-time polymorphism
    auto* values = new int[] {
        1,
        1,
        2,
        2,
        2,
        3,
        3,
        1000
    };
    
    auto m = mean(values, 8);
    printf("Mean is %d", m);

    return 0;
}
