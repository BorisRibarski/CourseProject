#pragma once

class team;

namespace cyclist
{
    class player
    {
        std::string name_;
        uint64_t uci_id_;

    public:
        player();
        ~player();
        player(std::string_view name, uint64_t uci_id);
        std::string to_string() const;
    };
}