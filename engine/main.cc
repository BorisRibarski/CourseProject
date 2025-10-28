#include "precompiled.hh"

#include "fs/wfile.hh"
#include "fs/rfile.hh"
#include "cyclist/player.hh"

#include "score/team.hh"
#include "score/solo.hh"

#include "cyclist/team.hh"

#include "engine.hh"

void fs_fun()
{
    stdfs::path path = "example.txt";

    fs::wfile wf(path);
    std::string data = "This is a test string.";
    wf.write(data.c_str(), data.size());

    fs::rfile rf(path);
    char buffer[256] = {0};
    rf.read(buffer, sizeof(buffer) - 1);

    fmt::println("Read from file: \n\t[ {} ]", buffer);
}

void score_fun()
{
    score::team team;
    team.set_time1(stdch::ms(1000));
    team.set_time2(stdch::ms(2000));
    team.set_time3(stdch::ms(1500));
    team.set_time4(stdch::ms(2500));

    fmt::println("Total time in milliseconds: {}", team.get_time().count());
}

void cyclist_fun()
{
    using namespace std::string_view_literals;
    cyclist::player player("John Doe"sv);
    fmt::println("{}", player.get_name());
    cyclist::team t("Levski"sv);
    fmt::println("Team name: {}", t.get_name());
}

int main()
{
    engine engine;
    engine.run_dummy();
    // load files and entities
    // run communications
    return 0;
}
