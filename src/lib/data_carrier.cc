#include "data_carrier.hh"

#include <charconv>
#include <format>
#include <ranges>
#include <utility>

namespace lib {

void data_carrier::invert() {
    available = !available;
}
data_carrier::data_carrier(data_carrier_type type_,
                           std::string author_,
                           std::string title_,
                           int release_year_,
                           bool available_)
    : type(type_), author(author_), title(title_),
      release_year(release_year_), available(available_) {
}
data_carrier::data_carrier(int type_,
                           std::string author_,
                           std::string title_,
                           int release_year_)
    : type(int_to_type(type_)), author(author_), title(title_),
      release_year(release_year_), available(true) {
}
std::string data_carrier::toString() {
    return std::format("{} {} {} {} {}",
                       std::to_underlying(type),
                       author,
                       title,
                       release_year,
                       available);
}
std::string data_carrier::toLine() {
    return std::format("[{};{};{};{};{}]",
                       std::to_underlying(type),
                       author,
                       title,
                       release_year,
                       available);
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

data_carrier_type data_carrier::int_to_type(int i) {
    switch (i) {
    case 0:
        return data_carrier_type::Book;
    case 1:
        return data_carrier_type::Magazine;
    case 2:
        return data_carrier_type::AudioCd;
    case 3:
        return data_carrier_type::CD_ROM;
    case 4:
        return data_carrier_type::Audio_Cassette;
    case 5:
        return data_carrier_type::Video_Cassette;
    default:
        return data_carrier_type::Error;
    }
}

} // namespace lib