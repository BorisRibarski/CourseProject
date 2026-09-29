#include "application.hh"

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
            // list_menu();
            break;
        case 3:
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
            // change();
            break;
        case 3:
            // remove();
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
}
void application::exit_screen() {
    terminal.show_goodbye();
}
void application::run() {
    home_menu();
    // MAGIC
    exit_screen();
}

} // namespace app