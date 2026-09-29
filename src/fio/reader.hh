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

class reader : handler {
  private:
  public:
    std::span<std::string> read();
};

} // namespace fio
