#include <iostream>
#include <vector>
#include <algorithm>

auto get_names_from(const std::vector<std::string> &names) -> std::vector<std::string> {
    auto const filter = [](auto const name) { return std::isupper(name.front()); };
    auto const comparator = [](auto const s1, auto const s2) {
        if (s1.length() != s2.length())
            return s1.length() < s2.length();
        else
            return s1.compare(s2) < 0;
    };
    auto result = std::vector<std::string>();
    std::ranges::copy_if(names, std::back_inserter(result), filter);
    std::ranges::sort(result, comparator);
    return result;
}

auto main() -> int {
    auto const words = std::vector<std::string>{
            "ala", "Ma", "Kota", "a", "Kot", "Mi", "ale",
            "Jaro", "Anna", "Mariusz", "Adrian", "Adriar", "Krzysztofer", "Katarzyna", "Kamil", "Kamila"
    };
    for (auto const &word: get_names_from(words))
        std::cout << word << ' ';
}