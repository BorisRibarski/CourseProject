#pragma once

namespace cyclist
{
    class team
    {
        std::string name_;

    public:
        team() = delete;
        team(std::string_view name);
        std::string_view get_name() const;
    };
}