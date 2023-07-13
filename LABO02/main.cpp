#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

template <typename T>
T read () {
    T x;
    std::cin >> x;
    return x;
}

////zad1
auto zad1() -> void;
auto add_element(std::vector<int> vector) -> void;

////zad2
auto przywitanie() -> void;
auto zgadywanie() -> void;
auto weryfikacja() -> void;
auto isPrime(auto number) -> bool;

////zad3
auto count_chars(const std::vector<char> & wektor, const char & znak) -> int;
auto count_chars(const std::string & lancuch, const char & znak) -> int;

////zad4
auto modify(std::vector<int> wektor, const std::string& polecenie) -> std::vector<int>;

auto main() -> int {

    ////zad1:
//    zad1();

    ////zad2:
    przywitanie();
//    zgadywanie();
//    weryfikacja();

    ////zad3:
//    auto wektor = std::vector<char> {'A', 'l', 'a', ' ', 'm', 'a', ' ', 'k', 'o', 't', 'a'};
//    auto lancuch = std::string {"Tola ma kota tez ale malego"};
//    char znak = 'a';
//    std::cout << count_chars(wektor, znak) << '\n';
//    std::cout << count_chars(lancuch, znak) << '\n';

    ////zad4:
//    auto intwektor = std::vector<int> {1, 2, 3, 4, 5, 6};
//    for (auto element : modify(intwektor, read<std::string>()))
//        std::cout << element << ' ';
}

////zad1:
auto zad1() -> void {
    auto ints = std::vector<int>();
    std::cout << ints.size() << '\n';
    add_element(ints);
    std::cout << ints.size() << '\n';
}

auto add_element(std::vector<int> vector) -> void {
    vector.push_back(10);
}

////zad2:
auto przywitanie() -> void {
    std::string name;
    std::cout << "Input your name:";
    std::cin >> name;
    if (std::ranges::equal(name + '\0',"Einstein"))
        std::cout << "I know you!";
    else
        std::cout << "Greetings.";
}

auto zgadywanie() -> void {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 99);
    auto number_to_guess = distrib(gen);
    auto guessed_number = -1;

    while (guessed_number != number_to_guess) {
        std::cout << "Guess a number:";
        std::cin >> guessed_number;
        if (guessed_number > number_to_guess)
            std::cout << "Too big. Try lower.\n";
        if (guessed_number < number_to_guess)
            std::cout << "Too small. Try higher.\n";
    }
    std::cout << "Congratulations!";
}

auto weryfikacja() -> void {
    std::cout << "Please input the numbers.\n" << "Type in a negative number to stop.\n";
    auto numbersToCheckForPrimality = std::vector<int>();
    for (
            auto number = read<int>();
            number >= 0;
            number = read<int>()
            ) {
        numbersToCheckForPrimality.push_back(number);
    }
    for (int number : numbersToCheckForPrimality) {
        if (isPrime(number)) {
            std::cout << number << " is prime.\n";
        } else {
            std::cout << number << " is not prime.\n";
        }
    }

}

auto isPrime(auto number) -> bool {
    if (number < 2) return true;
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) return false;
    }
    return true;
}

////zad3:
auto count_chars(const std::vector<char> & wektor, const char & znak) -> int {
    std::cout << "Wywolano przez wektor.\n";
    auto wynik = 0;
    for (auto element : wektor) {
        if (znak == element) wynik++;
    }
    return wynik;
}

auto count_chars(const std::string & lancuch, const char & znak) -> int {
    std::cout << "Wywolano przez lancuch.\n";
    auto wynik = 0;
    for (auto element : lancuch)
        if (znak == element) wynik++;
    return wynik;
}

////zad4:
auto modify(std::vector<int> wektor, const std::string& polecenie = "reverse") -> std::vector<int> {
    if (polecenie == "append") {
        wektor.push_back(123);
    } else if (polecenie == "truncate") {
        wektor.pop_back();
        wektor.erase(wektor.begin());
    } else if (polecenie == "reverse") {
        std::ranges::reverse(wektor);
    } else {
        std::cout << "Not a valid command.\n";
    }
    return wektor;
}
