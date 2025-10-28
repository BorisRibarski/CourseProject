#include "precompiled.hh"

#include "cyclist/cycler.hh"
#include "cyclist/player.hh"
#include "cyclist/team.hh"

#include "fs/sysadmin.hh"

namespace cyclist
{
    cycler::cycler(fs::sysadmin *sysadmin) : players_(), teams_()
    {
        sysadmin->asign(players_, teams_);
    }
    void cycler::run_dummy()
    {
        for (const auto &player : players_)
        {
            fmt::println("Player: {}", player.get_name());
        }
        for (const auto &team : teams_)
        {
            fmt::println("Team: {}", team.get_name());
        }
    }
}