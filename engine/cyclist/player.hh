#pragma once

class team;

namespace cyclist
{
    class player
    {
        std::string name_;
        int uci_id_;

    public:
        player() = delete;
        ~player();
        player(std::string_view name, int uci_id);
        player(std::string &buff);
        std::string to_string();

    private:
        std::pair<std::string, int> divide(std::string &buff);
    };
}