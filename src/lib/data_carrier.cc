#include "data_carrier.hh"

#include <charconv>
#include <format>
#include <ranges>
#include <utility>

namespace lib {

data_carrier::data_carrier(data_carrier_type type_,
                           std::string author_,
                           std::string title_,
                           int release_year_,
                           bool is_available_)
    : type(type_), author(author_), title(title_),
      release_year(release_year_), is_available(is_available_) {
}
std::string data_carrier::toLine() {
    return std::format("[{};{};{};{};{}]",
                       std::to_underlying(type),
                       author,
                       title,
                       release_year,
                       is_available);
}

data_carrier data_carrier::fromLine(std::string line) {
    line = line.substr(1, line.length() - 2);
    using std::operator""sv;
    auto params = std::views::split(line, ";"sv);

    auto it = params.begin();

    auto next_sv = [&it]() {
        auto subrange = *it++;
        return std::string_view(subrange.begin(), subrange.end());
    };

    int type_int = 0;
    auto type_sv = next_sv();
    std::from_chars(
        type_sv.data(), type_sv.data() + type_sv.size(), type_int);

    std::string author_str{next_sv()};
    std::string title_str{next_sv()};

    int year = 0;
    auto year_sv = next_sv();
    std::from_chars(year_sv.data(), year_sv.data() + year_sv.size(), year);

    auto avail_sv = next_sv();
    bool available = (avail_sv == "true");

    return data_carrier(static_cast<data_carrier_type>(type_int),
                        std::move(author_str),
                        std::move(title_str),
                        year,
                        available);
}

} // namespace lib