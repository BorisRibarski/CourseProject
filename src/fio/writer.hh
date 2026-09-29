#pragma once

#include <span>
#include <string>

#include "handler.hh"

/* example
int main() {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}
*/

namespace fio {

class writer : handler {
  private:
  public:
    void write(std::span<std::string>);
};

} // namespace fio
