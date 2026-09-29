#pragma once

#include <span>

#include "handler.hh"

namespace fio {

class writer : handler {
  private:
  public:
    writer(std::string);
    void write(std::span<std::string>);
};

} // namespace fio
