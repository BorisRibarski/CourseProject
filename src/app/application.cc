#include "application.hh"

#include <format>
#include <stdexcept>
#include <stdio.h>

namespace app {

int parse_int(std::string &view) {
    try {
        return std::stoi(view);
    } catch (std::exception &) {
        return -1;
    }
}

void application::home_menu() {
    while (true) {
        terminal.show_home();
        switch (terminal.get_answer()) {
        case 1:
            entity_menu();
            break;
        case 2:
            list_menu();
            break;
        case 3:
            lib_menu();
            break;
        case 4:
            return;
        default:
            break;
        }
    }
}
void application::entity_menu() {
    while (true) {
        terminal.show_entity_mgmt();
        switch (terminal.get_answer()) {
        case 1:
            add_new();
            break;
        case 2:
            invert();
            break;
        case 3:
            remove();
            break;
        case 4:
            return;
        default:
            break;
        }
    }
}
void application::lib_menu() {
    while (true) {
        terminal.show_lib_mgmt();
        switch (terminal.get_answer()) {
        case 1:
            load();
            return;
        case 2:
            save();
            return;
        case 3:
            return;
        default:
            break;
        }
    }
}
void application::list_menu() {
    while (true) {
        terminal.show_list_menu();
        switch (terminal.get_answer()) {
        case 1:
            list_ava();
            break;
        case 2:
            list_non();
            break;
        case 3:
            list_all();
            break;
        case 4:
            return;
        default:
            break;
        }
    }
}
void application::add_new() {
    std::string type_str = terminal.question("Type");
    int type = parse_int(type_str);
    std::string author = terminal.question("Author");
    std::string title = terminal.question("Title");
    std::string year_str = terminal.question("Release year");
    int year = parse_int(year_str);
    lib.add(type, author, title, year);
    auto l = lib.get_all();
    printf("Count:%ld", l.size());
}
void application::invert() {
    std::string n_str = terminal.question("Number");
    int n = parse_int(n_str);
    lib.change(n);
}
void application::remove() {
    std::string n_str = terminal.question("Number");
    int n = parse_int(n_str);
    lib.remove(n);
}

void application::load() {
    auto res = reader.read();
    lib.load(res);
}
void application::save() {
    writer.write(lib.save());
}

void application::list_ava() {
    auto list = lib.get_available();
    int i = 0;
    do {
        terminal.show_list(list);

        i = terminal.get_answer();
    } while (i != 1);
}
void application::list_non() {
    auto list = lib.get_non_available();
    int i = 0;
    do {
        terminal.show_list(list);

        i = terminal.get_answer();
    } while (i != 1);
}
void application::list_all() {
    auto list = lib.get_all();
    int i = 0;
    do {
        terminal.show_list(list);

        i = terminal.get_answer();
    } while (i != 1);
}
void application::exit_screen() {
    terminal.show_goodbye();
}
void application::run() {
    home_menu();
    // MAGIC
    exit_screen();
}
application::application(std::string import_filename,
                         std::string export_filename)
    : reader(import_filename), writer(export_filename) {
}

} // namespace app