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
    void invert();
    void remove();

    void list_ava();
    void list_non();
    void list_all();

    void exit_screen();

  public:
    void run();
};

} // namespace app