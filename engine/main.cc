#include <fcntl.h>
#include <unistd.h>
#include <fmt/core.h>

#include "fs/wfile.hh"
#include "fs/rfile.hh"

#include "timing/team_calc.hh"

#include <filesystem>

namespace stdfs = std::filesystem;

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
    if (0)
    {
        fs_fun();
    }

    timing::team_calc tc;
    int total = tc.calc(std::chrono::seconds(120), std::chrono::seconds(150));
    fmt::println("Total time in seconds: {}", total);

    return 0;
}
