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

  public: // getters and setters
    data_carrier_type get_type() const {
        return type;
    }
    std::string get_author() const {
        return author;
    }
    std::string get_title() const {
        return title;
    }
    int get_release_year() const {
        return release_year;
    }
    bool is_available() const {
        return available;
    }
    void set_type(data_carrier_type v) {
        type = v;
    }
    void set_author(std::string v) {
        author = v;
    }
    void set_title(std::string v) {
        title = v;
    }
    void set_release_year(int v) {
        release_year = v;
    }

  private:
    data_carrier_type int_to_type(int i);
};

} // namespace lib