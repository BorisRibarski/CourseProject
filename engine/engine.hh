#pragma once

#include "cyclist/cycler.hh"
#include "fs/sysadmin.hh"
#include "com/owl.hh"

class engine
{
private:
    cyclist::cycler *cycler_;
    fs::sysadmin *sysadmin_;
    com::owl *owl_;

public:
    engine();
    ~engine();
    void load_files();
    void run_communications();
    void run_dummy();
};