#include <iostream>
#include <memory>
#include <vector>

template <typename T>
auto deep_copy(std::vector<std::unique_ptr<T>> const &v) -> std::vector<std::unique_ptr<T>> {
    std::vector<std::unique_ptr<T>> result;
    for (auto const &ptr : v) {
        result.push_back(std::make_unique<T>(*ptr));
    }
    return result;
}

auto main() -> int {
//    int a = 2, b = 4, c = 6;
    auto v = std::vector<std::unique_ptr<int>>{};
    v.push_back(std::make_unique<int>(2));
    v.push_back(std::make_unique<int>(4));
    v.push_back(std::make_unique<int>(6));
    auto v2 = deep_copy(v);
    v2.at(1).get()[0] = 5;
    for (auto const &ptr : v2) {
        std::cout << *ptr << '\n';
    }
}