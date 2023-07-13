#include <fstream>
#include <iostream>

auto main() -> int {
    auto line = std::string();
    auto sum = 0;
    for (auto file = std::fstream("file.txt"); std::getline(file, line); sum += stoi(line));
    std::cout << sum;
}
