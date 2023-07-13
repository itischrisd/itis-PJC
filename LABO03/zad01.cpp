#include <iostream>
#include <vector>
#include <algorithm>

auto exchange_boundaries_swap(std::vector<int> & vec) -> void {
    std::ranges::swap(* std::ranges::min_element(vec),* std::ranges::max_element(vec));
}

auto exchange_boundaries_iter_swap(std::vector<int> & vec) -> void {
    std::ranges::iter_swap(std::ranges::min_element(vec), std::ranges::max_element(vec));
}

auto exchange_boundaries_loop(std::vector<int> & vec) -> void {
    auto mini = 0, maxi = 0;
    auto min = vec[mini], max = vec[maxi];
    for (auto i = 0; i < vec.size(); i++) {
        if (vec[i] < min) {
            mini = i;
            min = vec[i];
        }
        if (vec[i] > max) {
            maxi = i;
            max = vec[i];
        }
    }
    vec[mini] = max;
    vec[maxi] = min;
}

auto exchange_boundaries_loop_pointers(std::vector<int> & vec) -> void {
    auto minp = &vec[0], maxp = &vec[0];
    for (auto & elem : vec) {
        if (elem < *minp)
            minp = &elem;
        if (elem > *maxp)
            maxp = &elem;
    }
    auto temp = *minp;
    *minp = *maxp;
    *maxp = temp;
}

auto main() -> int {
    auto vec = std::vector<int> {1, 2, 3, 4, 5};

    exchange_boundaries_swap(vec); // <-- najpoprawniejsze
//    exchange_boundaries_iter_swap(vec);
//    exchange_boundaries_loop(vec);
//    exchange_boundaries_loop_pointers(vec);

    for (auto & ele :vec)
        std::cout << ele << ' ';
}
