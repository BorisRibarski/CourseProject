#pragma once

#include "fs/rfile.hh"

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
            using namespace std::string_view_literals;

            players.emplace_back("Alice"sv, 124);
            players.emplace_back("Bob"sv, 124);
            teams.emplace_back("Team A"sv);
            teams.emplace_back("Team B"sv);
        }

        // private:
        template <size_t N>
        int read_file(std::array<char, N> &buff, std::string_view path)
        {
            rfile file(path);
            [[maybe_unused]] int res = file.read(buff);
            // fmt::println("Read {} bytes", res);
            return 0;
        }
    };
}