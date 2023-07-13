#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

auto transformSlower(const std::string & filename) -> void {
    auto maxnumber = double();
    auto file_in = std::fstream(filename);
    auto file_out = std::fstream("out_slower.txt", std::ios::app | std::ios::out);
    for (auto line = std::string(); std::getline(file_in, line);)
        if (std::stod(line) > maxnumber) maxnumber = std::stod(line);
    file_in = std::fstream(filename);
    for (auto line = std::string(); std::getline(file_in, line); file_out << std::stod(line) / maxnumber << '\n');
    //this is better when file is larger than memory
}

auto transformFaster(const std::string & filename) -> void {
    auto numbers = std::vector<double>();
    auto file_in = std::fstream(filename);
    auto file_out = std::fstream("out_faster.txt", std::ios::app);
    for (auto line = std::string(); std::getline(file_in, line); numbers.push_back(std::stod(line)));
    auto max = *std::ranges::max_element(numbers, [](auto const a, auto const b) { return a < b; });
    std::ranges::transform(numbers, numbers.begin(), [max](auto const number) { return number / max; });
    for (auto const number: numbers)
        file_out << number << '\n';
    //this is better when file is smaller than memory
}

auto main() -> int {
    auto filename = std::string("file.txt");
    transformFaster(filename);
    transformSlower(filename);
}