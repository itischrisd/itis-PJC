#include <vector>
#include <algorithm>
#include <iostream>


auto erase_between_minmax(std::vector<double> & vec) -> void {
    if (std::ranges::min_element(vec) < std::ranges::max_element(vec))
        vec.erase(std::ranges::min_element(vec) + 1, std::ranges::max_element(vec));
    else if (std::ranges::min_element(vec) > std::ranges::max_element(vec))
        vec.erase(std::ranges::max_element(vec) + 1, std::ranges::min_element(vec));
}

auto erase_between_minmax_loop(std::vector<double> & vec) -> void {
    auto min_i = 0, max_i = 0;
    auto min = vec[min_i], max = vec[max_i];
    for (auto i = 0; i < vec.size(); i++) {
        if (vec[i] < min) {
            min_i = i;
            min = vec[i];
        }
        if (vec[i] > max) {
            max_i = i;
            max = vec[i];
        }
    }
    if (min_i < max_i)
        for (auto i = 1; i < (max_i - min_i); i++)
            vec.erase(vec.begin() + min_i + 1);
    else if (min_i > max_i)
        for (auto i = 1; i < (min_i - max_i); i++)
            vec.erase(vec.begin() + max_i + 1);
}

auto main() -> int {
    auto vec = std::vector<double> {1, 2, 3, 4, 5, 2, 1, 2, 3};
    erase_between_minmax(vec);
    for (auto & elem : vec)
        std::cout << elem << ' ';
}