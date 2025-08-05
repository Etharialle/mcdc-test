#include "main.hpp"

int complex_decision(bool a, bool b, bool c) {
    // This is the line we want to test for MCDC.
    // Gcov with -fcondition-coverage will analyze this expression.
    if ((a && b) || c) {
        return 100;
    } else {
        return 200;
    }
}

// A simple main function so we can compile it as a standalone executable if needed.
int main() {
    std::cout << "Running main executable." << std::endl;
    std::cout << "Test case (true, true, true): " << complex_decision(true, true, true) << std::endl;
    return 0;
}