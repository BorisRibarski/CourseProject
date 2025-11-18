#include "precompiled.hh"

#include "player.hh"

namespace cyclist
{
    player::~player()
    {
    }
    player::player(std::string_view name, int uci_id) : name_(name), uci_id_(uci_id)
    {
    }
    player::player(std::string &buff)
    {
        auto [name, id] = this->divide(buff);
        fmt::println("[{} {}]", name, id);
    }

    std::string player::to_string()
    {
        std::string s;
        fmt::format_to(std::back_inserter(s), "{}:{};", name_, uci_id_);
        return s;
    }

    std::pair<std::string, int> player::divide(std::string &buff)
    {
        std::string name = buff.substr(0, buff.find(':'));
        int id = std::stoi(buff.substr(buff.find(':') + 1, buff.find(';')));
        return {name, id};
    }
}