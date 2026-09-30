#include <format>
#include <optional>
#include <ranges>
#include <span>
#include <string>
#include <string_view>

#include <vector>

#include "application.hh"

struct flags {
    bool is_verbose;
    int has_input_file;
    int has_output_file;
};

struct files {
    std::optional<std::string> import_file;
    std::optional<std::string> export_file;
};

files handle_args(int argc, char **argv) {
    flags check = {};
    files paths = {};

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
            check.is_verbose = true;
        } else if (*arg == "--file"sv || *arg == "-f"sv) {
            handle_duo("Defined io file", i, args);
            check.has_input_file++;
            check.has_output_file++;
            check_overload(check);
            paths.import_file = *(arg + 1);
            paths.export_file = *(arg + 1);
            i++;
            arg++;
        } else if (*arg == "--input-file"sv || *arg == "-i"sv) {
            handle_duo("Defined input file", i, args);
            check.has_input_file++;
            check_overload(check);
            paths.import_file = *(arg + 1);
            i++;
            arg++;
        } else if (*arg == "--output-file"sv || *arg == "-o"sv) {
            handle_duo("Defined output file", i, args);
            check.has_output_file++;
            check_overload(check);
            paths.export_file = *(arg + 1);
            i++;
            arg++;
        } else if (*arg == "--help"sv || *arg == "-o"sv) {
            handle_mono("Some stupid help message");
        } else {
            throw std::invalid_argument("Invalid argument");
        }
    }
    return paths;
}

int main(int argc, char **argv) {
    files f = {};
    try {
        f = handle_args(argc, argv);
    } catch (std::exception &e) {
        printf("%s", e.what());
    }
    if (not f.import_file.has_value()) {
        f.import_file = "data/import";
    }
    if (not f.export_file.has_value()) {
        f.export_file = "data/export";
    }
    app::application app(*f.import_file, *f.export_file); // f goes here
    app.run();

    return 0;
}