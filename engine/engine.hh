#pragma once

#include "cyclist/cycler.hh"
#include "fs/sysadmin.hh"
class owl;

class engine
{
public:
    cyclist::cycler *cycler_;
    fs::sysadmin *sysadmin_;
    owl *owl_;
    engine();
    void load_files();
    void run_communications();
    void run_dummy();
};