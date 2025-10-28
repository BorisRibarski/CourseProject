#include "precompiled.hh"

#include "engine.hh"

engine::engine() : owl_(nullptr)
{
    sysadmin_ = new fs::sysadmin();
    cycler_ = new cyclist::cycler(sysadmin_);
}

void engine::load_files()
{
    // Implementation for loading files goes here
}

void engine::run_communications()
{
    // Implementation for running communications goes here
}

void engine::run_dummy()
{
    cycler_->run_dummy();
}