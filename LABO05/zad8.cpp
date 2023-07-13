#include <fstream>
#include <filesystem>
#include <iostream>
#include <ranges>

auto main() -> int {
    auto directory = std::string();
    std::cout << "Enter directory:" << '\n';
    std::cin >> directory;
    auto words = std::vector<std::string>();
    auto word = std::string();
    for (auto const &entry: std::filesystem::directory_iterator(directory))
        if (entry.path().filename().string().ends_with(".txt")) for (auto file = std::fstream(entry.path(), std::ios::in); file >> word; words.push_back(word));

    auto counters = std::unordered_map<std::string, int>();
    std::ranges::for_each(words, [&counters](auto const number) { counters[number]++; });
    std::cout << std::ranges::max_element(counters, [](auto const a, auto const b) { return a.second < b.second; })->first;
}