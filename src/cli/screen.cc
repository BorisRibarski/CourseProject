#include "screen.hh"

#include <string>

namespace cli {

void clear_screen() {
#if defined(_WIN32) || defined(_WIN64)
    std::system("cls");
#else
    std::system("clear");
#endif
}

screen::screen() {
}

void screen::print() {
    clear_screen();
    for (auto &line : matrix) {
        printf("%s%s", line.data(), line == matrix.back() ? "" : "\n");
    }
}

const int screen_builder::width = 80;
const std::string screen_builder::line(width, '#');
const std::string screen_builder::empty(0, ' ');
const std::string screen_builder::tab(width / 4, ' ');

screen_builder::screen_builder() {
    using std::operator""s;

    std::string str = "Course Project of Boris Ribarski"s;
    int space_size = (width - str.length()) / 2;
    std::string space(space_size, ' ');
    scr.matrix.emplace_back(line);
    scr.matrix.emplace_back(empty);
    scr.matrix.emplace_back(space + str);
    scr.matrix.emplace_back(empty);
}
screen_builder &&screen_builder::add_row(std::string_view str) {
    scr.matrix.emplace_back(str);
    return std::move(*this);
}
screen_builder &&screen_builder::add_tab_row(std::string_view str) {
    scr.matrix.emplace_back(tab + std::string(str));
    return std::move(*this);
}
screen_builder &&screen_builder::add_row_centered(std::string_view str) {
    int space_size = (width - str.length()) / 2;
    std::string space(space_size, ' ');
    scr.matrix.emplace_back(space + std::string(str));
    return std::move(*this);
}
screen_builder &&screen_builder::add_line() {
    scr.matrix.emplace_back(line);
    return std::move(*this);
}
screen_builder &&screen_builder::add_empty() {
    scr.matrix.emplace_back(empty);
    return std::move(*this);
}
screen_builder &&screen_builder::clear() {
    scr.matrix.clear();
    return std::move(*this);
}
screen screen_builder::build() && {
    scr.matrix.emplace_back(empty);
    scr.matrix.emplace_back(line);
    return screen(std::move(scr));
}
screen screen_builder::clean_build() && {
    return screen(std::move(scr));
}

} // namespace cli