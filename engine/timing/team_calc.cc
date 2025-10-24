#include "./timing/team_calc.hh"

namespace timing
{
    int team_calc::calc(std::chrono::seconds t1, std::chrono::seconds t2)
    {
        return (t2 + t1).count();
    }
}