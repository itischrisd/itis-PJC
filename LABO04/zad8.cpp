#include <iostream>
#include <vector>
#include <ranges>

template<typename T>
auto chunk(T iter1, const T iter2, const int size) -> std::vector<std::vector<typename T::value_type>> {
    auto result = std::vector<std::vector<std::iter_value_t<T>>>();
    auto chunk = std::vector<std::iter_value_t<T>>();

    if (iter2 < iter1)
        return result;

    std::for_each(iter1, iter2, [&chunk, &result, size](auto const &element) {
        chunk.push_back(element);
        if (chunk.size() == size) {
            result.push_back(chunk);
            chunk.clear();
        }
    });

    if (chunk.size() != 0)
        result.push_back(chunk);

    return result;
}

template<typename T>
auto print(const T &container) -> void {
    for (const auto &element: container) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

auto main() -> int {
    auto const v1 = std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto const v2 = std::vector<std::string>{"a", "b", "c", "d", "e", "f"};
    auto const v1by3 = chunk(v1.begin(), v1.end(), 3);
    auto const v1by2 = chunk(v1.begin(), v1.end(), 2);
    auto const v2by5 = chunk(v2.begin(), v2.end(), 5);
    auto const v2by1 = chunk(v2.begin(), v2.end(), 1);
    for (auto const &vec: v1by3) print(vec);
    std::cout << '\n';
    for (auto const &vec: v1by2) print(vec);
    std::cout << '\n';
    for (auto const &vec: v2by5) print(vec);
    std::cout << '\n';
    for (auto const &vec: v2by1) print(vec);

}