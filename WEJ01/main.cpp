#include <iostream>
#include <algorithm>

auto main() -> int {
    auto input1 = std::vector<int>(5);
    auto input2 = std::vector<int>(5);

    for (auto & cell : input1) {
        auto number = 0;
        std::cin >> number;
        cell = number;
    }

    for (auto & cell : input2) {
        auto number = 0;
        std::cin >> number;
        cell = number;
    }

    std::ranges::sort(input1);
    std::ranges::sort(input2);

    if (input1 == input2)
        std::cout << "Sa takie same";
    else
        std::cout << "Nie sa takie same";
}
