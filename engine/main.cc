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
    stdfs::path path = "player.txt";
    std::string data = "Bobi Mihaylov";
    fs::wfile wf(path);
    wf.write(data.c_str(), data.size());

    fs::rfile rf(path);
    std::string buffer = "";
    rf.read(buffer);

    fmt::println("Read from file: \n\t[ {} ]", buffer);
}

int main()
{
    using namespace std::string_view_literals;

    auto read_player = []()
    {
        cyclist::player data("Georgi Lumperov", 165418761);

        stdfs::path path = "player.txt";
        fs::wfile wf(path);
        wf.write(data.to_string());

        fs::rfile rf(path);
        std::string buffer = "";
        rf.read(buffer);
        cyclist::player p(buffer);
    };
    read_player();
    return 0;
}
