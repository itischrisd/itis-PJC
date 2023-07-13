#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

auto main() -> int {
	auto filename = std::string();
    std::cin >> filename;
    auto count = 0;
    for (auto const & entry : std::filesystem::recursive_directory_iterator("D:\\", std::filesystem::directory_options::skip_permission_denied))
        if (entry.path().filename().string() == filename) count++;
    std::cout << '\n' << "Ilosc plikow o nazwie " << filename << " na dysku C: to " << count;
}