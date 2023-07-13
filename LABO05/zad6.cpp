#include <fstream>
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <set>

auto main() -> int {
    auto file = std::fstream("file.txt");
    auto input = std::string();

    std::getline(std::cin, input);
    auto path = input.substr(0, input.find(' '));
    auto boundaries = std::vector<int>();

    std::ranges::copy(
            input
            | std::ranges::views::split(' ')
            | std::ranges::views::drop(1)
            | std::ranges::views::transform(
            [](auto const &range) {
                auto str = range | std::ranges::views::common;
                return std::stoi(std::string(str.begin(), str.end()));
            }), std::back_inserter(boundaries));

    auto lines = std::set<int>();
}