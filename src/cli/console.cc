#include "console.hh"

#include <iostream>
#include <screen.hh>

namespace cli {

void console::show_home() {
    screen_builder()
        .add_tab_row("1. Entity Management")
        .add_tab_row("2. List view")
        .add_tab_row("3. Exit")
        .build()
        .print();
}
void console::show_entity_mgmt() {
    screen_builder()
        .add_tab_row("1. Add new")
        .add_tab_row("2. Remove")
        .add_tab_row("3. Get/Return")
        .add_tab_row("4. Exit")
        .build()
        .print();
}
void console::show_goodbye() {
    screen_builder()
        .clear()
        // clang-format off
        .add_row("################################################################################")
        .add_row("                                                                                ")
        .add_row("                   GGGG   OOOO   OOOO  DDD   BBBB  Y   Y EEEEE                  ")
        .add_row("                  G      O    O O    O D  D  B   B  Y Y  E                      ")
        .add_row("                  G  GG  O    O O    O D   D BBBB    Y   EEEE                   ")
        .add_row("                  G   G  O    O O    O D  D  B   B   Y   E                      ")
        .add_row("                   GGGG   OOOO   OOOO  DDD   BBBB    Y   EEEEE                  ")
        .add_row("                                                                                ")
        .add_row("################################################################################")
        // clang-format on
        .clean_build()
        .print();
}
std::string console::question(std::string_view view) {
    using std::operator""sv;
    screen_builder().add_tab_row(view).build().print();
    std::string line;
    std::cin >> line;
    return line;
}
int console::get_answer() {
    try {
        std::string line;
        std::cin >> line;
        return std::stoi(line);
    } catch (std::exception &) {
        return -1;
    }
}
bool console::is_working() {
    return working;
}
void console::quit() {
    working = false;
}

} // namespace cli