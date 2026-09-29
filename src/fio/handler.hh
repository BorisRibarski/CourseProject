#pragma once

#include <fstream>
#include <string>

namespace fio {

class handler {
  protected:
    std::ofstream myfile;
    std::string filename;
    handler(std::string filename_) : filename(filename_) {
    }
};

} // namespace fio