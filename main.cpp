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

// Only compile this main function if we are not building for tests.
// The test executable will have its own main from the gtest_main library.
#ifndef EXCLUDE_MAIN_FOR_TESTING

int main() {
    std::cout << "Running main executable." << std::endl;
    std::cout << "Test case (true, true, true): " << complex_decision(true, true, true) << std::endl;
    return 0;
}

#endif // EXCLUDE_MAIN_FOR_TESTING