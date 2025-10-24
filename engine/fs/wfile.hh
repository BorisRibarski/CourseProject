#pragma once

#include "file_handle.hh"
#include "writable.hh"
#include <filesystem>

namespace stdfs = std::filesystem;

namespace fs
{
    class wfile : public file_handle, writable
    {
    public:
        wfile() = delete;
        wfile(const stdfs::path &path);
        ~wfile() noexcept;
        int write(const void *buf, size_t count);
    };
}