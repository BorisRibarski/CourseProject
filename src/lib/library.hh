#pragma once

#include <span>
#include <utility>
#include <vector>

#include "data_carrier.hh"

class library {
  public:
    using vector = std::vector<data_carrier>;
    using span = std::span<data_carrier>;
    using span_pair = std::span<data_carrier>;

  private:
    vector shelf;

  public:
    span get_available();
    span get_non_available();
    span_pair get_all();
};