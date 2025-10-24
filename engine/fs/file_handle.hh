#pragma once

#include <string>
#include <unistd.h>
#include <array>

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