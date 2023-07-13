#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

auto get_male_names_from(const std::vector<std::string> &names) -> std::vector<std::string> {
    auto const filter = [](auto const name) { return not name.ends_with('a'); };
    auto result = std::vector<std::string>();
    std::ranges::copy_if(names, std::back_inserter(result), filter);
    auto const comparator = [](auto const s1, auto const s2) {
        if (s1.length() != s2.length())
            return s1.length() < s2.length();
        else
            return s1.compare(s2) < 0;
    };
    std::ranges::sort(result, comparator);
    return result;
}

auto get_evens_from(std::vector<int> numbers) -> std::vector<int> {
    auto const filter = [](int num) { return num % 2 == 0; };
    auto result = std::vector<int>();
    std::ranges::copy_if(numbers, std::back_inserter(result), filter);
    return result;
}

auto main() -> int {
    auto names = std::vector<std::string>{
            "Jaro", "Anna", "Mariusz", "Adrian", "Adriar", "Krzysztofer", "Katarzyna", "Kamil", "Kamila"
    };
    auto male_names = get_male_names_from(names);
    for (const auto &name: male_names)
        std::cout << name + ' ';

    std::cout << '\n';

    auto const numbers = std::vector<int>{2, 1, 3, 6, 7, 9, 8};

    auto result = get_evens_from(numbers);

    for (int i: result)
        std::cout << i << ' ';
}

