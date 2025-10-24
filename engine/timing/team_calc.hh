#pragma once

#include <chrono>

namespace timing
{
    class team_calc
    {
    public:
        int calc(std::chrono::seconds t1, std::chrono::seconds t2);
    };
}