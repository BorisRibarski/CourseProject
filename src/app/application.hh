#pragma once

#include "console.hh"
#include "library.hh"

namespace app {

class application {
  private:
    lib::library lib;
    cli::console terminal;

    void home_menu();
    void entity_menu();
    void list_menu();
    void add_new();
    void exit_screen();

  public:
    void run();
};

} // namespace app