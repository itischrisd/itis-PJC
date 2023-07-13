#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
    auto numbers = std::vector<int>{10, 11, 12, 20, 21, 22, 30, 31, 33};
    auto const comparator = [](auto const n1, auto const n2) { return (n1 % 10) < (n2 % 10); };
    std::ranges::sort(numbers, comparator);
    for (auto const &number: numbers)
        std::cout << number << ' ';
}