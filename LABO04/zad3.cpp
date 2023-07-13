#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

auto most_common_char(const std::string &str) -> char {
    auto common_char = char();
    auto common_count = 0;

    std::for_each(std::begin(str), std::end(str), [&common_char, &common_count, &str](auto const c) {
        auto const count = std::count(std::begin(str), std::end(str), c);
        if (count > common_count) {
            common_count = count;
            common_char = c;
        }
    });
    return common_char;
}

auto main() -> int {
    auto str = std::string();
    std::cin >> str;
    std::cout << most_common_char(str);
}