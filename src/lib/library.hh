#pragma once

#include <span>
#include <utility>
#include <vector>

#include "data_carrier.hh"

namespace lib {

class library {
  public:
    using vector = std::vector<data_carrier>;
    using span = std::span<data_carrier>;

  private:
    vector shelf;

  public:
    void add(int, std::string, std::string, int);
    void remove(int);
    void change(int);
    std::vector<std::string> get_available();
    std::vector<std::string> get_non_available();
    std::vector<std::string> get_all();
    void load(span items);
};

} // namespace lib