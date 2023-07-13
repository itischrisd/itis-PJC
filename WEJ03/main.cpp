#include <iostream>
#include <vector>
#include <algorithm>


///zad1
auto erase_value(std::vector<int> & vec, const int ind) -> void {
    auto const val_to_del = vec[ind];

    //moje
    std::erase_if(vec, [val_to_del](auto const i) { return i == val_to_del; });

    //FK
//    auto const [begin, end] = std::ranges::remove(vec, val_to_del);
//    vec.erase(begin, end);
}

///zad2
enum ordering {
    required,
    not_required
};


auto contains(std::vector<std::string> source, std::vector<std::string> subset, const ordering & order) -> bool {
    bool result = true;
    if (order == ordering::not_required) {
        std::ranges::for_each(subset, [&source, &result](auto const & elem) {
            result = result && (std::ranges::find(source.begin(), source.end(), elem) != source.end());
            std::erase_if(source, [&elem](auto const source_elem){return source_elem == elem;});
        });
    } else {
        std::ranges::for_each(subset, [&source, &result](auto const & elem) {
            result = result && (std::ranges::find(source.begin(), source.end(), elem) != source.end() && (*source.begin() == elem));
            std::erase_if(source, [&elem](auto const source_elem){return source_elem == elem;});
        });
    }
    return result;
}


auto main() -> int {
    ///zad1
    auto vec = std::vector<int>{1, 2, 3, 1, 2, 3, 1, 2, 3};
    erase_value(vec, 2);
    for (auto const i: vec) { std::cout << i << ' ';}

    std::cout << '\n';

    ///zad2
    auto const source = std::vector<std::string> {
        "C++", "may", "seem", "complicated",
        "but",
        "yeah", "it", "kind", "of", "is"};

    auto const subset1 = std::vector<std::string>{"C++", "may", "seem"};
    auto const subset2 = std::vector<std::string>{"C++", "but", "complicated"};
    auto const subset3 = std::vector<std::string>{"C++", "is", "easy"};
    auto const subset4 = std::vector<std::string>{"C++", "C++"};
    auto const subset5 = std::vector<std::string>{"C++", "seem", "yeah"};
    std::cout << contains(source, subset1, ordering::required) << '\n'
              << contains(source, subset1, ordering::not_required) << '\n'
              << contains(source, subset2, ordering::required) << '\n'
              << contains(source, subset2, ordering::not_required) << '\n'
              << contains(source, subset3, ordering::required) << '\n'
              << contains(source, subset3, ordering::not_required) << '\n'
              << contains(source, subset4, ordering::required) << '\n'
              << contains(source, subset4, ordering::not_required) << '\n'
              << contains(source, subset5, ordering::required) << '\n'
              << contains(source, subset5, ordering::not_required);
}
