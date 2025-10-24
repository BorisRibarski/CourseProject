#pragma once

#include <cstddef>

namespace fs
{
    class writable
    {
    public:
        virtual int write(const void *buf, size_t count) = 0;
    };
}