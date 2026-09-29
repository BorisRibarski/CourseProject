#include <format>
#include <optional>
#include <ranges>
#include <span>
#include <string>
#include <string_view>

#include "application.hh"

void handle_args(int argc, char **argv) {
    using args_type = std::span<char *>;
    args_type args(argv, argc);
    auto arg = args.begin() + 1;
    for (args_type::size_type i = 1; i < args.size(); i++, arg++) {
        using namespace std::literals; // for "text"sv

        auto handle_mono = [](std::string_view str) {
            printf("%s\n", str.data());
        };
        auto handle_duo = [](std::string_view str, int i, args_type args) {
            if (args.size() <= static_cast<args_type::size_type>(i + 1)) {
                throw std::invalid_argument("No file defined");
            }
            printf("%s:[%s]\n", str.data(), args[i + 1]);
        };

        if (*arg == "--verbose"sv || *arg == "-v"sv) {
            handle_mono("Verbose\n");
        } else if (*arg == "--file"sv || *arg == "-f"sv) {
            handle_duo("Defined io file", i, args);
            i++;
            arg++;
        } else if (*arg == "--input-file"sv || *arg == "-i"sv) {
            handle_duo("Defined input file", i, args);
            i++;
            arg++;
        } else if (*arg == "--output-file"sv || *arg == "-o"sv) {
            handle_duo("Defined output file", i, args);
            i++;
            arg++;
        } else if (*arg == "--help"sv || *arg == "-o"sv) {
            handle_mono("Some stupid help message");
        } else {
            printf("%s\n", *arg);
            throw std::invalid_argument("Invalid argument");
        }
    }
}

int main(int argc, char **argv) {
    try {
        handle_args(argc, argv);
    } catch (std::exception &e) {
        printf("%s", e.what());
    }
    app::application app;
    app.run();
    return 0;
}