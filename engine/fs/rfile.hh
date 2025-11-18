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
        template <size_t N>
        int read(std::array<char, N> &buf)
        {
            return this->read(buf.data(), N);
        }
        int read(void *buf, size_t count);
    };
}