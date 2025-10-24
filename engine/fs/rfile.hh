#pragma once

#include "fs/file_handle.hh"
#include "fs/readable.hh"
#include <filesystem>

namespace stdfs = std::filesystem;

namespace fs
{
    class rfile : public file_handle, readable
    {
    public:
        rfile() = delete;
        rfile(const stdfs::path &path);
        ~rfile() noexcept;
        int read(void *buf, size_t count);
    };
}