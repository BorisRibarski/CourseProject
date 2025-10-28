#include "precompiled.hh"

#include "team.hh"

namespace cyclist
{
    team::team(std::string_view name) : name_(name) {}
    std::string_view team::get_name() const
    {
        return this->name_;
    }

}
