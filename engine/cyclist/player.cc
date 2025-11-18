#include "precompiled.hh"

#include "player.hh"

namespace cyclist
{
    player::player() : name_("Unknown"), uci_id_(-1)
    {
    }
    player::~player()
    {
    }
    player::player(std::string_view name, uint64_t uci_id) : name_(name), uci_id_(uci_id)
    {
    }

    std::string player::to_string() const
    {
        std::string s;
        fmt::format_to(std::back_inserter(s), "{}:{};", name_, uci_id_);
        return s;
    }
}