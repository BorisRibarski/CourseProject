#include <fcntl.h>
#include <unistd.h>
#include <cstddef>

#include <filesystem>
#include <chrono>
#include <string>
#include <string_view>
#include <vector>

#include <fmt/core.h>

namespace stdfs = std::filesystem;
namespace stdch = std::chrono;

namespace std::chrono
{
    namespace stdch = std::chrono;
    using ms = std::chrono::milliseconds;
}