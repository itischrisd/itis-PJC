#include <iostream>

template<typename T>
class binder {
    T *ptr;

public:
    binder(T &val) { ptr = &val; }


    void change_value_to(const T val) { //val mozna przez referencje lub nie, typy dosc proste wiec bez &
        *ptr = val;
    }


    void bind_with(T &i) {
        ptr = &i;
    }
};

auto main() -> int {
    auto i = 10;
    auto s = std::string("Hello");
    auto int_binder = binder<int>(i);
    auto string_binder = binder<std::string>(s);
    std::cout << i << ' ' << s << '\n';
    int_binder.change_value_to(5);
    std::cout << i << ' ' << s << '\n';
    string_binder.change_value_to("There");
    auto i2 = 15;
    int_binder.bind_with(i2);
    std::cout << i << ' ' << s << ' ' << i2 << '\n';
    int_binder.change_value_to(-5);
    std::cout << i << ' ' << s << ' ' << i2 << '\n';
}
