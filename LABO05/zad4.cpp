#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <ranges>
#include <numeric>

auto main() -> int {
    auto words = std::vector<std::string>();
    auto numbers = std::vector<int>();
    auto word = std::string();

    for (auto file = std::fstream("file.txt"); file >> word; words.push_back(word));

    std::ranges::copy(
            words
            | std::views::filter([](auto const s) { return std::all_of(s.begin(), s.end(), ::isdigit);; })
            | std::views::transform([](auto const word) { return std::stoi(word); }),
            std::back_inserter(numbers));

    auto counters = std::unordered_map<int, int>();
    std::ranges::for_each(numbers, [&counters](auto const number) { counters[number]++; });
    std::cout << '\n'
              << std::ranges::max_element(counters, [](auto const a, auto const b) { return a.second < b.second; })->first
              << ' ' << std::accumulate(numbers.begin(), numbers.end(), 0);
}
