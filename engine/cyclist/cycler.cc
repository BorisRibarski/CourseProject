#include "precompiled.hh"

#include "cyclist/cycler.hh"
#include "cyclist/player.hh"
#include "cyclist/team.hh"

#include "fs/sysadmin.hh"

namespace cyclist
{
    cycler::cycler()
    {
    }
    void cycler::run_dummy()
    {
        for (const auto &player : players_)
        {
            fmt::println("Player: {}", player.to_string());
        }
        for (const auto &team : teams_)
        {
            fmt::println("Team: {}", team.get_name());
        }
    }
    void cycler::load(fs::sysadmin *sysadmin)
    {
        load_players(sysadmin);
    }
    void cycler::load_players(fs::sysadmin *sysadmin)
    {
        using namespace std::string_view_literals;

        std::string_view path = "/home/ribcho/KP/engine/test_read2.tmp"sv;
        std::array<char, 65536> buff = {};
        sysadmin->read_file(buff, path);
        std::string content(buff.data());
        for (size_t i = 0, j = content.find('\n'); i < content.size(); i = j + 1, j = content.find('\n', i))
        {
            std::string line = content.substr(i, j - i);
            // fmt::println("Line: [{}]", line);
            auto [name, id] = divide(line);
            players_.emplace_back(name, id);
        }
        for ([[maybe_unused]] auto &p : players_)
        {
            // fmt::println("Loaded player: {}", p.to_string());
        }
    }
    void cycler::load_teams(fs::sysadmin *sysadmin)
    {
        sysadmin->asign(players_, teams_);
    }
    std::pair<std::string, uint64_t> cycler::divide(std::string &buff)
    {
        std::string name = buff.substr(0, buff.find(':'));
        std::string num = buff.substr(buff.find(':') + 1, buff.find('\n'));
        // fmt::println("Dividing buff: [{}] into name: [{}] and num: [{}]", buff, name, num);
        uint64_t id = 0;
        for (size_t i = 0; i < num.size(); id += num[i] - '0', id *= 10, i++)
        {
            // fmt::println("Char {} at pos {}", num[i], i);
        }
        id /= 10;
        // fmt::println("Parsed id: {}", id);
        return {name, id};
    }
}