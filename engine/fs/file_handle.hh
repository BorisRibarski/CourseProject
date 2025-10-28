#pragma once

namespace fs
{
    class file_handle
    {
    protected:
        int fd;

    public:
        file_handle() : fd(-1) {}
    };
}