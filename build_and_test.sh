#!/bin/bash

# Build and test script for MC/DC coverage testing
# Requires: g++ 14.2, gtest, lcov 2.3.1

set -e  # Exit on any error

echo "=== MC/DC Coverage Testing with GCov and LCov ==="
echo

# Clean up previous runs
echo "Cleaning up previous build artifacts..."
rm -f *.gcda *.gcno *.o main main_test
rm -rf coverage_report
echo "Clean up complete."
echo

# Compilation flags for MC/DC coverage
COVERAGE_FLAGS="-fcondition-coverage -fprofile-arcs -ftest-coverage"
COMPILE_FLAGS="-std=c++17 -Wall -Wextra -g -O0"

echo "=== Building main executable ==="
g++ $COMPILE_FLAGS $COVERAGE_FLAGS -o main main.cpp
echo "Main executable built successfully."
echo

echo "=== Building test executable ==="
g++ $COMPILE_FLAGS $COVERAGE_FLAGS -o main_test main_test.cpp main.cpp -lgtest -lgtest_main -lpthread
echo "Test executable built successfully."
echo

echo "=== Running main executable ==="
./main
echo "Main execution complete."
echo

echo "=== Running tests ==="
./main_test
echo "Tests complete."
echo

echo "=== Generating coverage data ==="
# Generate gcov files
gcov -m main.cpp
echo "GCov data generated."
echo

echo "=== Coverage files generated: ==="
ls -la *.gcov *.gcda *.gcno
echo

echo "=== Generating LCov report ==="
# Create coverage report directory
mkdir -p coverage_report

# Generate lcov info file with condition coverage
lcov --capture --directory . --output-file coverage_report/coverage.info --rc derive_function_end_line=0

# Generate HTML report
genhtml coverage_report/coverage.info --output-directory coverage_report --rc derive_function_end_line=0

echo "LCov HTML report generated in coverage_report/ directory."
echo

echo "=== Coverage Summary ==="
lcov --summary coverage_report/coverage.info

echo
echo "=== Instructions ==="
echo "1. Open coverage_report/index.html in a web browser to view detailed coverage report"
echo "2. Look for condition coverage information in the detailed reports"
echo "3. The -fcondition-coverage flag enables MC/DC coverage tracking"
echo "4. Check .gcov files for line-by-line coverage details"
echo
echo "=== MC/DC Analysis ==="
echo "To analyze MC/DC coverage effectively:"
echo "- Each condition in complex boolean expressions should be tested"
echo "- Each condition should independently affect the outcome"
echo "- Look for 'Conditions' section in the HTML report"
echo "- Verify that changing each condition changes the result"