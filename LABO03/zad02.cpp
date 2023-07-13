#include <vector>
#include <iostream>

auto filter_evens_inplace(std::vector<int> & vec) -> void {
    std::erase_if(vec,[](int i) { return i % 2 == 0;});
}

auto filter_evens(std::vector<int> vec) -> std::vector<int> {
    filter_evens_inplace(vec);
    return vec;
}

auto filter_evens_loop_inplace(std::vector<int> & vec) -> void {
    for (auto i = 0; i < vec.size(); i++)
        if (vec[i] % 2 == 0)
            vec.erase(vec.begin() + i);
}

auto filter_evens_loop(std::vector<int> vec) -> std::vector<int> {
    filter_evens_loop_inplace(vec);
    return vec;
}
auto main() -> int {
    auto vec = std::vector<int> {1, 2, 3, 4, 5, 6};
    for (auto & elem : filter_evens(vec))
        std::cout << elem << ' ';
}