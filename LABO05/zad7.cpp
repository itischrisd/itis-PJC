#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <filesystem>

auto sendToFile(std::string line) -> void {
    auto vec = std::vector<std::string>();
    std::ranges::copy(line | std::ranges::views::split(' ') | std::ranges::views::transform(
            [](auto const &range) {
                auto str = range | std::ranges::views::common;
                return std::string(str.begin(), str.end());
            }), std::back_inserter(vec));
    auto file = std::fstream(vec[0], std::ios::out);
    for (auto i = 1; i < vec.size(); i++)
        file << vec[i] << '\n';
}

auto main() -> int {
    auto file = std::fstream("file.txt");
    auto input = std::vector<std::string>();
    for (auto line = std::string(); std::getline(file, line); input.push_back(line));
    std::for_each(input.begin(), input.end(), [](auto const &line) { sendToFile(line); });
}