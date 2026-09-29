#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "handler.hh"

namespace fio {

class reader : handler {
  private:
    std::ifstream myfile;

  public:
    reader(std::string);
    std::vector<std::string> read();
};

} // namespace fio
