#include <iostream>

template <typename T>
auto swap(T *ptr1, T *ptr2) -> void {
    T temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

auto main() -> int {
    auto a = 1, b = 2;
    std::cout << "a = " << a << ", ptr a = " << &a << '\n';
    std::cout << "b = " << b << ", ptr b = " << &b << '\n';
    swap(&a, &b);
    std::cout << "a = " << a << ", ptr a = " << &a << '\n';
    std::cout << "b = " << b << ", ptr b = " << &b << '\n';

    auto c = 1.5, d = 2.7;
    std::cout << "c = " << c << ", ptr c = " << &c << '\n';
    std::cout << "d = " << d << ", ptr d = " << &d << '\n';
    swap(&c, &d);
    std::cout << "c = " << c << ", ptr c = " << &c << '\n';
    std::cout << "d = " << d << ", ptr d = " << &d << '\n';

    auto e = "Ala", f = "kot";
    std::cout << "e = " << e << ", ptr e = " << &e << '\n';
    std::cout << "f = " << f << ", ptr f = " << &f << '\n';
    swap(&e, &f);
    std::cout << "e = " << e << ", ptr e = " << &e << '\n';
    std::cout << "f = " << f << ", ptr f = " << &f << '\n';
}