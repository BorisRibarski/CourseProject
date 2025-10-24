#include "rfile.hh"
#include <string>
#include <fcntl.h>
#include <unistd.h>

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
}