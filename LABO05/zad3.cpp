#include <fstream>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

auto main() -> int {
    auto line = std::string();
    auto vector = std::vector<int>();
    for (auto file = std::fstream("file.txt", std::ios::in); std::getline(file, line); vector.push_back(stoi(line)));

    auto counters = std::unordered_map<int, int>();
    std::ranges::for_each(vector, [&counters](auto const number) { counters[number]++; });
    std::cout << std::ranges::max_element(counters, [](auto const a, auto const b) { return a.second < b.second; })->first;
}