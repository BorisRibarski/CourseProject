#pragma once

#include <string_view>
#include <vector>

namespace cli {

class screen {
  private:
    std::vector<std::string> matrix;

  private:
    screen();

    friend class screen_builder;

  public:
    void print();
};

class screen_builder {
  private:
    screen scr;
    static const int width;
    static const std::string line;
    static const std::string empty;
    static const std::string tab;

  public:
    screen_builder();
    screen_builder &&add_row(std::string_view);
    screen_builder &&add_tab_row(std::string_view);
    screen_builder &&add_row_centered(std::string_view);
    screen_builder &&add_line();
    screen_builder &&add_empty();
    screen_builder &&clear();
    screen build() &&;
    screen clean_build() &&;
};
} // namespace cli