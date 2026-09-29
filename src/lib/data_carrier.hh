#pragma once

#include <string>

#include "data_carrier_type.hh"

class data_carrier {
  public:
  private:
    data_carrier_type type;
    std::string author;
    std::string title;
    int release_year;
    bool is_available;
};