#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        return 1;
    }

    bool a = std::string(argv[1]) == "true";
    bool b = std::string(argv[2]) == "true";
    bool c = std::string(argv[3]) == "true";

    if ((a && b) || c) {
        std::cout << "path 1" << std::endl;
    } else {
        std::cout << "path 2" << std::endl;
    }

    return 0;
}