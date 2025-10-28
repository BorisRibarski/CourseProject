#include "precompiled.hh"

#include "player.hh"

namespace cyclist
{
    player::player(std::string_view name)
        : name_(name)
    {
    }
    std::string_view player::get_name() const
    {
        return this->name_;
    }
    void player::set_team(team *t)
    {
        this->team_ = t;
    }
    team *player::get_team() { return this->team_; }
}