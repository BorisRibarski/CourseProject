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
        cycler();
        void run_dummy();
        void load(fs::sysadmin *sysadmin);

    private:
        void load_players(fs::sysadmin *sysadmin);
        void load_teams(fs::sysadmin *sysadmin);
        std::pair<std::string, uint64_t> divide(std::string &buff);
    };
}