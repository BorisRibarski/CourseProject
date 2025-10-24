#include <fcntl.h>
#include <unistd.h>
#include <fmt/core.h>

#include "fs/wfile.hh"
#include "fs/rfile.hh"

#include "score/team.hh"

#include <filesystem>

namespace stdfs = std::filesystem;

#include <chrono>

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

int main()
{
    score::team team;
    team.set_time1(std::chrono::milliseconds(1200));
    team.set_time2(std::chrono::milliseconds(1500));
    team.set_time3(std::chrono::milliseconds(1100));
    team.set_time4(std::chrono::milliseconds(1300));

    fmt::println("Total time in seconds: {}", team.get_time().count());

    return 0;
}
