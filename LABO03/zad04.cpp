#include <vector>
#include <iostream>
#include <algorithm>

template <typename T>
auto erase_n_biggest(std::vector<T> vec, int n) -> std::vector<T> {
    if (n > vec.size())
        return std::vector<T>();
    for(auto i = 0; i < n; i++)
        vec.erase(std::ranges::max_element(vec));
    return vec;
}

auto main() -> int {
    auto vec = std::vector<int> {1, 2, 3, 4, 6, 5, 9};
    for (auto & elem : erase_n_biggest(vec, 2))
        std::cout << elem << ' ';

    std::cout << '\n';

    auto vec2 = std::vector<char> {'A', 'Z', 'C', 'B', 'X'};
    for (auto & elem : erase_n_biggest(vec2, 3))
        std::cout << elem << ' ';
}