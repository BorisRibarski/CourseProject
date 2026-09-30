#pragma once

#include <fstream>
#include <vector>

#include "handler.hh"

namespace fio {

class writer : handler {
  private:
    std::ofstream myfile;

  public:
    writer(std::string);
    void write(std::vector<std::string>);
};

} // namespace fio
