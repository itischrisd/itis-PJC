#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

template <typename T, typename Function>
auto mapped(const std::vector<T> & vec, const Function fun) -> auto {
    auto result = std::vector<std::invoke_result_t<Function, T>>();
    std::ranges::for_each(vec, [&result, fun](T const elem){result.push_back(fun(elem));});
    return result;
}

auto main() -> int {
    auto const strings = std::vector<std::string>{"abc", "defghi", "jk", "lmno"};
    auto const chars = mapped(strings, [](std::string const &s) { return s.front(); });
    auto const sizes = mapped(strings, [](std::string const &s) { return s.size(); });
    for (auto const c: chars) std::cout << c << ' ';
    std::cout << '\n';
    for (auto const s: sizes) std::cout << s << ' ';
}
