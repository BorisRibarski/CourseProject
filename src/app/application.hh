#pragma once

#include "library.hh"

namespace app {

class application {
  private:
    lib::library lib;

  public:
    void run();
};

} // namespace app