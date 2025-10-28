#pragma once

class team;

namespace cyclist
{
    class player
    {
        team *team_;
        std::string name_;

    public:
        player() = delete;
        player(std::string_view name);
        std::string_view get_name() const;
        void set_team(team *t);
        team *get_team();
    };
}