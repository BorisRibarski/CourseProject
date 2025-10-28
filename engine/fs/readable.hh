#pragma once

namespace fs
{
    class readable
    {
    public:
        virtual int read(void *buf, size_t count) = 0;
    };
}