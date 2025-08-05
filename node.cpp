#include <iostream>
#include <string>
#include "path_logic.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " [true|false] [true|false] [true|false]" << std::endl;
        return 1;
    }

    bool a = std::string(argv[1]) == "true";
    bool b = std::string(argv[2]) == "true";
    bool c = std::string(argv[3]) == "true";

    std::cout << get_path(a, b, c) << std::endl;

    return 0;
}