#include "writer.hh"

namespace fio {

writer::writer(std::string filename) : handler(filename) {
}

void writer::write(std::span<std::string> lines) {
    myfile.open(filename);
    for (auto line : lines) {
        myfile << line << std::endl;
    }
    myfile.close();
}

} // namespace fio