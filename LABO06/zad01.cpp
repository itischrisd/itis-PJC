#include <iostream>

auto swap(int *a, int *b) -> void {
    int temp = *a;
    *a = *b;
    *b = temp;
}

auto main() -> int {
    auto a = 1, b = 2;
    std::cout << "a = " << a << ", ptr a = " << &a << '\n';
    std::cout << "b = " << b << ", ptr b = " << &b << '\n';
    swap(&a, &b);
    std::cout << "a = " << a << ", ptr a = " << &a << '\n';
    std::cout << "b = " << b << ", ptr b = " << &b << '\n';
}
