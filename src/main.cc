#include <format>
#include <optional>
#include <ranges>
#include <span>
#include <string>
#include <string_view>

#include <vector>

#include "application.hh"
#include "data_carrier.hh"
#include "reader.hh"
#include "screen.hh"
#include "writer.hh"

struct flags {
    bool is_verbose;
    int has_input_file;
    int has_output_file;
};

flags handle_args(int argc, char **argv) {
    flags ret = {};
    using args_type = std::span<char *>;
    args_type args(argv, argc);
    auto arg = args.begin() + 1;

    for (args_type::size_type i = 1; i < args.size(); i++, arg++) {

        using std::operator""sv;

        auto handle_mono = [](std::string_view str) {
            printf("%s\n", str.data());
        };
        auto handle_duo = [](std::string_view str, int i, args_type args) {
            if (args.size() <= static_cast<args_type::size_type>(i + 1)) {
                throw std::invalid_argument("No file defined");
            }
            printf("%s:[%s]\n", str.data(), args[i + 1]);
        };

        auto check_overload = [](flags f) {
            if (f.has_input_file > 1 || f.has_output_file > 1) {
                throw std::invalid_argument("Too many defined files");
            }
        };

        if (*arg == "--verbose"sv || *arg == "-v"sv) {
            handle_mono("Verbose\n");
            ret.is_verbose = true;
        } else if (*arg == "--file"sv || *arg == "-f"sv) {
            handle_duo("Defined io file", i, args);
            ret.has_input_file++;
            ret.has_output_file++;
            check_overload(ret);
            i++;
            arg++;
        } else if (*arg == "--input-file"sv || *arg == "-i"sv) {
            handle_duo("Defined input file", i, args);
            ret.has_input_file++;
            check_overload(ret);
            i++;
            arg++;
        } else if (*arg == "--output-file"sv || *arg == "-o"sv) {
            handle_duo("Defined output file", i, args);
            ret.has_output_file++;
            check_overload(ret);
            i++;
            arg++;
        } else if (*arg == "--help"sv || *arg == "-o"sv) {
            handle_mono("Some stupid help message");
        } else {
            throw std::invalid_argument("Invalid argument");
        }
    }
    return ret;
}

int main(int argc, char **argv) {
    flags f = {};
    try {
        f = handle_args(argc, argv);
    } catch (std::exception &e) {
        printf("%s", e.what());
    }
    using std::operator""s;
    cli::screen screen = cli::screen_builder()
                             .add_row_centered("Ribcho is cooking"s)
                             .build();
    screen.print();
    app::application app; // f goes here
    app.run();

    return 0;
}
void fun() {
    lib::data_carrier car(
        lib::data_carrier_type::Book, "Me", "Myself & I", 2002, true);
    lib::data_carrier car2(
        lib::data_carrier_type::CD_ROM, "Marti", "KABOOM", 2012, false);

    std::vector<std::string> out{car.toLine(), car2.toLine()};
    std::vector<lib::data_carrier> in;

    fio::writer w("duo");
    fio::reader r("duo");
    w.write(out);
    for (auto l : r.read()) {
        in.push_back(lib::data_carrier::fromLine(l));
    }
    for (auto car : in) {
        printf("%s\n", car.toLine().data());
    }
}