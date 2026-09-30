#pragma once

#include "console.hh"
#include "library.hh"
#include "reader.hh"
#include "writer.hh"

namespace app {

class application {
  private:
    lib::library lib;
    cli::console terminal;
    fio::reader reader;
    fio::writer writer;

    void home_menu();
    void entity_menu();
    void lib_menu();
    void list_menu();

    void add_new();
    void invert();
    void remove();

    void save();
    void load();

    void list_ava();
    void list_non();
    void list_all();

    void exit_screen();

  public:
    void run();
    application(std::string import_filename, std::string export_filename);
};

} // namespace app