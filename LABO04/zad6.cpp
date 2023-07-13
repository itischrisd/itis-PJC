#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

auto filtered(const std::vector<std::string> &words, const std::vector<std::string> &forbid) -> std::vector<std::string> {
    auto const filter = [&forbid](auto const word) {
        return std::ranges::find(forbid, word) == std::end(forbid);
    };
    auto result = std::vector<std::string>();
    std::ranges::copy_if(words, std::back_inserter(result), filter);
    return result;
}

auto main() -> int {
    auto const words = std::vector<std::string> {
            "kwiatek", "ananas", "dupa", "zeszyt", "dupa", "tiananmen"
    };
    auto const forbidden = std::vector<std::string>{
            "dupa", "tiananmen"
    };

    for (auto const &word: filtered(words, forbidden))
        std::cout << word << ' ';
}