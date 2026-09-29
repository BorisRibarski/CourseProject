#pragma once

#include <span>
#include <string>

#include "handler.hh"

namespace fio {

class reader : handler {
  private:
  public:
    std::span<std::string> read();
};

} // namespace fio
