#include "wfile.hh"
#include <string>
#include <fcntl.h>
#include <unistd.h>

namespace fs
{
    wfile::wfile(const stdfs::path &path)
    {
        const int flags = O_WRONLY | O_CREAT | O_TRUNC;

        this->fd = open(path.c_str(), flags);
    }
    wfile::~wfile()
    {
        if (this->fd != -1)
        {
            close(this->fd);
        }
    }
    int wfile::write(const void *buf, size_t count)
    {
        return ::write(this->fd, buf, count);
    }
}