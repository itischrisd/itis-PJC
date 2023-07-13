#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

auto ordered_by_case(std::vector<std::string> &vec) -> void {
    auto const comparator = [](auto const s1, auto const s2) { return s1.front() < s2.front(); };
    auto result = std::vector<std::string>();
    std::ranges::sort(vec, comparator);
}

auto main() -> int {
    auto words = std::vector<std::string>{
            "ala", "Ma", "Kota", "a", "Kot", "Ma", "ale"
    };
    ordered_by_case(words);
    for (auto const &word: words)
        std::cout << word << ' ';
}