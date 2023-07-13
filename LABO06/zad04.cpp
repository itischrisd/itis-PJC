#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

template<typename T>
auto sorted_view(std::vector<std::unique_ptr<T>> const &vec, auto comp) -> std::vector<T *> {
    std::vector<T *> result;
    for (auto const &ptr: vec) {
        result.push_back(ptr.get());
    }
    std::ranges::sort(result, comp, [](auto const &ptr) { return *ptr; });
    return result;
}

template<typename T>
auto print_vector_of_pointers(std::vector<T> const &vec) -> void {
    for (auto const &ptr: vec) {
        std::cout << *ptr << ' ';
    }
    std::cout << '\n';
}

auto main() -> int {
    auto pointers = std::vector<std::unique_ptr<std::string>>();
    pointers.push_back(std::make_unique<std::string>("abc"));
    pointers.push_back(std::make_unique<std::string>("d"));
    pointers.push_back(std::make_unique<std::string>("g"));
    pointers.push_back(std::make_unique<std::string>("ef"));
    print_vector_of_pointers(pointers);
    auto const alphabetical = sorted_view(
            pointers,
            [](std::string const &left, std::string const &right) {
                return left < right;
            }
    );
    auto const by_length = sorted_view(
            pointers,
            [](std::string const &left, std::string const &right) {
                return left.size() < right.size();
            }
    );
    print_vector_of_pointers(alphabetical);
    print_vector_of_pointers(by_length);
    print_vector_of_pointers(pointers);
}