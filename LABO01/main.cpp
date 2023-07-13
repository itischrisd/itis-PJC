#include <iostream>
#include <algorithm>

////zad2:
bool is_palindrome(std::string str);

////zad3:
void box_print(const std::vector<std::string>& vector1);

auto main() -> int {
////zad1:
    std::string foo;
    getline(std::cin, foo);
    std::cout << foo[0] << "\n";
    std::cout << '"' << foo[foo.size()-1] << "\"\n";
    std::cout << foo.size() << "\n";
    std::cout << foo[foo.size()/2] << "\n";
    std::cout << "[" << foo << "]\n";
    std::ranges::reverse(foo);
    std::cout << "[" << foo << "]\n";
    std::ranges::sort(foo);
    std::cout << foo << "\n";

////zad2:
    getline(std::cin, foo);
    std::cout << is_palindrome(foo) << "\n";

////zad3:
    auto words = std::vector<std::string>{"Hello", "PJC", "in", "quite","a", "wideeeeeeee", "frame",};
    box_print(words);
}

////zad2:
bool is_palindrome(std::string str) {
    std::string str_copy = str;
    std::ranges::reverse(str);
    return str == str_copy;
}

////zad3:
void box_print(const std::vector<std::string>& vector1) {
    int line_length = 0;
    for (const auto& word : vector1) {
        if (word.size() > line_length)
            line_length = word.size(); // NOLINT(cppcoreguidelines-narrowing-conversions)
    }
    std::cout << std::string(line_length+2, '*') << '\n';
    for (const auto& word : vector1) {
        std::cout << '*' << word << std::string(line_length-word.size(), ' ') << "*\n";
    }
    std::cout << std::string(line_length+2, '*');
}