#pragma once

#include <fstream>

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

class handler {
  protected:
    std::ofstream myfile;
};

} // namespace fio