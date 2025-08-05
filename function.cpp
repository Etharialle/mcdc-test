
lets create a simple C++ program.  we will compile with g++ 14.2.  We want to test the mcdc aspect of gcov by the setting the -fcondition-coverage flag when we compile.  We want to test the program using the gtest framework.  And finally use lcov 2.3.1 to generate our test report.  I expect a main.cpp, main_test.cpp, and a main.hpp

I'll help you create a C++ program to test MC/DC (Modified Condition/Decision Coverage) using gcov with the -fcondition-coverage flag. Let me create the three files you requested.


main.hpp
Code 

main.cpp
Code 

main_test.cpp
Code 
Now, let me create a comprehensive build and test script that demonstrates how to compile and run everything with the proper flags:


build_and_test.sh
Code 
Finally, let me create a Makefile for easier compilation:


Makefile
Code 
I've created a complete C++ project for testing MC/DC coverage with the following files:

Files Created:
main.hpp - Header file with function declarations designed for MC/DC testing
main.cpp - Implementation with complex boolean conditions perfect for MC/DC analysis
main_test.cpp - Comprehensive GTest suite with test cases designed to achieve MC/DC coverage
build_and_test.sh - Complete build and test script
Makefile - For easier compilation and testing
Key Features for MC/DC Testing:
Functions with Complex Conditions:
isValidUser() - Tests AND/OR combinations
canProcessTransaction() - Multiple AND conditions
isEligibleForLoan() - Complex OR conditions with nested AND
isAdult() - Simple condition for baseline
Test Cases:
The test suite includes carefully designed test cases that:

Test each condition independently
Ensure each condition can independently affect the outcome
Cover all branches and decision points
Provide comprehensive MC/DC coverage
Usage Instructions:
Option 1: Using the build script
bash
chmod +x build_and_test.sh
./build_and_test.sh
Option 2: Using the Makefile
bash
# Build everything
make all

# Run tests and generate coverage report
make report

# View coverage summary
make summary

# Clean up
make clean
Option 3: Manual compilation
bash
# Compile main program
g++ -std=c++17 -Wall -Wextra -g -O0 -fcondition-coverage -fprofile-arcs -ftest-coverage -o main main.cpp

# Compile tests
g++ -std=c++17 -Wall -Wextra -g -O0 -fcondition-coverage -fprofile-arcs -ftest-coverage -o main_test main_test.cpp main.cpp -lgtest -lgtest_main -lpthread

# Run programs
./main
./main_test

# Generate coverage
gcov -m main.cpp
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_report
What to Expect:
GCov files (*.gcov) showing line-by-line coverage
Condition coverage data thanks to -fcondition-coverage
HTML report with detailed MC/DC metrics
Test results showing all test cases pass
The test cases are specifically designed to ensure that each boolean condition in the complex expressions can independently affect the outcome, which is the key requirement for MC/DC coverage.





root@0a4c268fd532:~/ws/mcdc-test# make all
g++ -std=c++17 -Wall -Wextra -g -O0 -fcondition-coverage -fprofile-arcs -ftest-coverage -o main main.cpp
g++ -std=c++17 -Wall -Wextra -g -O0 -fcondition-coverage -fprofile-arcs -ftest-coverage -o main_test main_test.cpp main.cpp -lgtest -lgtest_main -lpthread
/usr/bin/ld: /tmp/ccHRgmbh.o: in function main':
/root/ws/mcdc-test/main.cpp:26: multiple definition of main'; /tmp/ccsc6Wbn.o:/root/ws/mcdc-test/main_test.cpp:108: first defined here
collect2: error: ld returned 1 exit status
make: *** [Makefile:23: main_test] Error 1

I see the issue! There are two main functions - one in main.cpp and one in main_test.cpp, causing a linking conflict. Let me fix this by updating the files to separate the main application logic from the test logic.


main.cpp
Code 
Now I need to create a separate source file for just the functions without the main function, so we can link properly:


functions.cpp
Code 

main_test.cpp
Code 

main_test.cpp
Code 
Now let me update the Makefile to use the separate function file:


Makefile
Code 
Let me also update the build script to reflect the new file structure:


build_and_test.sh
Code 

Making edits...
 



#include "main.hpp"

bool isValidUser(int age, bool hasLicense, bool hasInsurance) {
    // This condition has multiple parts for MC/DC testing
    return (age >= 18) && (hasLicense || hasInsurance);
}

bool canProcessTransaction(double amount, bool hasAccount, bool hasBalance, bool isVerified) {
    // Complex condition with multiple logical operators
    return (amount > 0.0 && amount <= 10000.0) && 
           (hasAccount && hasBalance) && 
           isVerified;
}

bool isAdult(int age) {
    // Simple condition
    return age >= 18;
}

bool isEligibleForLoan(int creditScore, int income, bool hasCollateral, bool hasGuarantor) {
    // Complex condition with OR and AND operators
    return (creditScore >= 700 && income >= 50000) || 
           (hasCollateral && hasGuarantor);
}
C++ MC/DC Coverage Testing Setup - Claude