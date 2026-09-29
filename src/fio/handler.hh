#pragma once

#include <string>

namespace fio {

class handler {
  protected:
    std::string filename;
    handler(std::string filename_) : filename(filename_) {
    }
};

} // namespace fio