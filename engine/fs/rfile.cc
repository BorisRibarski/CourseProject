#include "precompiled.hh"

#include "rfile.hh"

namespace fs
{
    rfile::rfile(const stdfs::path &path)
    {
        const int flags = O_RDONLY;

        this->fd = open(path.c_str(), flags);
    }
    rfile::~rfile()
    {
        if (this->fd != -1)
        {
            close(this->fd);
        }
    }
    int rfile::read(void *buf, size_t count)
    {
        return ::read(this->fd, buf, count);
    }
    int rfile::read(std::string &buff)
    {
        char buffer[256] = {};
        int res = this->read(buffer, 256);
        buff = buffer;
        return res;
    }
}