#include "reader.hh"

namespace fio {

reader::reader(std::string filename) : handler(filename) {
}

std::vector<std::string> reader::read() {
    std::vector<std::string> lines;
    myfile.open(filename);

    if (!myfile.is_open()) {
        printf("Error");
    }

    std::string line;
    while (std::getline(myfile, line)) {
        lines.push_back(line);
    }
    myfile.close();
    return lines;
}

} // namespace fio