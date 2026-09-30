#pragma once

#include <string>

#include "data_carrier_type.hh"

namespace lib {

class data_carrier {
  public:
    data_carrier(data_carrier_type, std::string, std::string, int, bool);
    data_carrier(int, std::string, std::string, int);

  private:
    data_carrier_type type;
    std::string author;
    std::string title;
    int release_year;
    bool available;

  public:
    void invert();
    std::string toString();
    std::string toLine();
    static data_carrier fromLine(std::string);

  private:
    data_carrier_type int_to_type(int i);
};

} // namespace lib