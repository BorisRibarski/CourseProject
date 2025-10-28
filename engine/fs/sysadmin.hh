#pragma once

namespace fs
{
    class sysadmin
    {
    public:
        sysadmin() = default;
        template <class T, class U>
        void asign(std::vector<T> &players,
                   std::vector<U> &teams)
        {
            players.emplace_back("Alice");
            players.emplace_back("Bob");

            teams.emplace_back("Team A");
            teams.emplace_back("Team B");
        }
    };
}