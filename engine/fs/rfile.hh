#pragma once

#include "file_handle.hh"
#include "interfaces/readable.hh"

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
        int read(std::string &buff);
    };
}