#pragma once

#include "base.hh"

namespace score
{
    class team : protected base
    {
    private:
        std::chrono::milliseconds time1;
        std::chrono::milliseconds time2;
        std::chrono::milliseconds time3;
        std::chrono::milliseconds time4;

    public:
        team() : base() {}

        void set_time1(std::chrono::milliseconds t)
        {
            time1 = t;
        }
        void set_time2(std::chrono::milliseconds t)
        {
            time2 = t;
        }
        void set_time3(std::chrono::milliseconds t)
        {
            time3 = t;
        }
        void set_time4(std::chrono::milliseconds t)
        {
            time4 = t;
        }

        std::chrono::milliseconds get_time() const
        {
            return time1 + time2 + time3 + time4;
        }
    };
}