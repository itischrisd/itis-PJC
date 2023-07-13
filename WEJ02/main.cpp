#include <iostream>
#include <vector>
#include <algorithm>

auto extract_minmax_to(std::vector<int> inputvec, int &min, int &max) -> void;

auto main() -> int {
    auto const vec = std::vector<int>{2, 1, 5, 4, 3};
    auto first = 0, second = 0;
    extract_minmax_to(vec, first, second);
    std::cout << first << ' ' << second << '\n';
}

auto extract_minmax_to(std::vector<int> inputvec, int &min, int &max) -> void {
    min = std::ranges::min(inputvec);
    max = std::ranges::max(inputvec);
}
