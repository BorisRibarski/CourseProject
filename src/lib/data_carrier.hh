#pragma once

#include <string>

#include "data_carrier_type.hh"

namespace lib {

class data_carrier {
  public:
    data_carrier(data_carrier_type, std::string, std::string, int, bool);

  private:
    data_carrier_type type;
    std::string author;
    std::string title;
    int release_year;
    bool is_available;

  public:
    std::string toLine();
    static data_carrier fromLine(std::string);
};

} // namespace lib