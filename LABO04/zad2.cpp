#include <vector>
#include <iostream>
#include <algorithm>

auto main() -> int {
    //get 10 numbers from user to vector
    auto numbers = std::vector<int>();
    auto result = std::vector<int>();
    auto number = int();
    for (auto i = 0; i < 10; ++i) {
        std::cin >> number;
        numbers.push_back(number);
    }
    //filter unique numbers from vector
    std::ranges::sort(numbers);
    const auto [first, last] = std::ranges::unique(numbers);
    numbers.erase(first, numbers.end());
    for (int i: numbers)
        std::cout << i << ' ';
}