#include <iostream>
#include <vector>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

////zad1:
auto swap(auto & l1, auto & l2) -> void;

////zad2:
auto filter_evens(std::vector<int> liczby) -> std::vector<int>;
auto filter_evens_inplace(std::vector<int> & liczby) -> void;

////zad3:
////na szablonach
template<typename T>
auto get_typename(T item) -> std::string;
template<typename T>
auto log_access(T & item) -> T &;
////na przeciazeniach
//auto log_access(int&) -> int&;
//auto log_access(std::string&) -> std::string&;
//auto log_access(std::vector<int>&) -> std::vector<int>&;

auto main() -> int {

    ////zad1:
//    auto a = 7;
//    auto b = 17;
//    std::cout << "Przed: a = " << a << ", b = " << b << '\n';
//    swap(a,b);
//    std::cout << "Po: a = " << a << ", b = " << b << '\n';

    ////zad2
//    auto liczby1 = std::vector<int> {1, 2, 3, 4, 5, 6};
//    auto liczby2 = std::vector<int> {1, 2, 3, 4, 5, 6};
//
//    for (auto liczba : liczby1)
//        std::cout << liczba << ' ';
//    std::cout << '\n';
//    for (auto liczba : liczby2)
//        std::cout << liczba << ' ';
//    std::cout << '\n';
//
//    auto liczby3 = filter_evens(liczby1);
//    filter_evens_inplace(liczby2);
//
//    for (auto liczba : liczby1)
//        std::cout << liczba << ' ';
//    std::cout << '\n';
//    for (auto liczba : liczby2)
//        std::cout << liczba << ' ';
//    std::cout << '\n';
//    for (auto liczba : liczby3)
//        std::cout << liczba << ' ';
//    std::cout << '\n';

    ////zad3
    auto i = int();
    auto s = std::string();
    auto v = std::vector<int>();
    log_access(i);
    log_access(s);
    log_access(v);
    log_access(i) = 10;
    auto i2 = log_access(i);
    std::cout << (i == i2) << '\n';
    auto& iref = log_access(i);
    iref = 12;
    std::cout << (i == i2) << '\n';
    s += "Hello There";
    std::cout << log_access(s).size() << '\n';
    v = {2, 1, 3, 7};
    std::cout << log_access(v)[1] << '\n';

}

////zad1:
auto swap(auto & l1, auto & l2) -> void {
    auto temp = l1;
    l1 = l2;
    l2 = temp;
}

////zad2:
auto filter_evens(std::vector<int> liczby) -> std::vector<int> {
    filter_evens_inplace(liczby);
    return liczby;
}
auto filter_evens_inplace(std::vector<int> & liczby) -> void {
    std::erase_if(liczby, [](int i) { return i % 2 == 0;});
}

////zad3:
////na szablonach:
template <typename T>
std::string get_typename(T item) {
    if (typeid(int) == typeid(item))
        return "int";
    else if (typeid(std::string) == typeid(item))
        return "string";
    else if (typeid(std::vector<int>) == typeid(item))
        return "vector";
    else
        return "unknown type";
}
template <typename T>
T & log_access(T & item) {
    std::cout << "using " << get_typename(item) << '\n';
    return item;
}
////na przeciazeniach:
//auto log_access(int & item) -> int& {
//    std::cout << "using int" << '\n';
//    return item;
//}
//auto log_access(std::string & item) -> std::string& {
//    std::cout << "using string" << '\n';
//    return item;
//}
//auto log_access(std::vector<int> & item) -> std::vector<int>& {
//    std::cout << "using vector" << '\n';
//    return item;
//}