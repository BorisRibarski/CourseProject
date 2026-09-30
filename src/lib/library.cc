#include "library.hh"

#include <algorithm>

namespace lib {

void library::add(int type,
                  std::string author,
                  std::string title,
                  int year) {
    shelf.emplace_back(type, author, title, year);
}
void library::remove(int n) {
    shelf.erase(shelf.begin() + n);
}
void library::change(int n) {
    shelf[n].invert();
}

std::vector<std::string> library::get_available() {
    std::vector<std::string> tmp;
    for (auto &i : shelf) {
        if (i.is_available()) tmp.push_back(i.toString());
    }
    return tmp;
}
std::vector<std::string> library::get_non_available() {
    std::vector<std::string> tmp;
    for (auto &i : shelf) {
        if (not i.is_available()) tmp.push_back(i.toString());
    }
    return tmp;
}
std::vector<std::string> library::get_all() {
    std::vector<std::string> items_str;
    std::transform(shelf.begin(),
                   shelf.end(),
                   std::back_inserter(items_str),
                   [](lib::data_carrier d) { return d.toString(); });
    return items_str;
}
void library::load(span items) {
    for (auto i : items) {
        shelf.emplace_back(i);
    }
}

} // namespace lib