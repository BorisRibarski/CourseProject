#pragma once

#include "cyclist/player.hh"
#include "cyclist/team.hh"
namespace fs
{
    class sysadmin;
}

namespace cyclist
{
    class cycler
    {
        std::vector<cyclist::player> players_;
        std::vector<cyclist::team> teams_;

    public:
        cycler(fs::sysadmin *sysadmin);
        void run_dummy();
    };
}