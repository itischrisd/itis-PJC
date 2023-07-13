#include <fstream>
#include <iostream>

auto main() -> int {
    auto line = std::string();
    auto count = 1;
    for (auto file = std::fstream("file.txt", std::ios::in); std::getline(file, line); count++);
    std::cout << count;
}