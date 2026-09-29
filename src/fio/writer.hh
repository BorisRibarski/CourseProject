#pragma once

#include <fstream>
#include <span>

#include "handler.hh"

namespace fio {

class writer : handler {
  private:
    std::ofstream myfile;

  public:
    writer(std::string);
    void write(std::span<std::string>);
};

} // namespace fio
