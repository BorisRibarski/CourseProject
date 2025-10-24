#pragma once

#include "base.hh"

namespace score
{
    class solo : protected base
    {
    public:
        solo() : base() {}

        void set_time(std::chrono::milliseconds t)
        {
            time = t;
        }

        std::chrono::milliseconds get_time() const
        {
            return time;
        }
    };
}