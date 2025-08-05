# Makefile for MC/DC Coverage Testing

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -O0
COVERAGE_FLAGS = -fcondition-coverage -fprofile-arcs -ftest-coverage
LDFLAGS = -lgtest -lgtest_main -lpthread

SOURCES = main.cpp functions.cpp
TEST_SOURCES = main_test.cpp functions.cpp
HEADERS = main.hpp

TARGET = main
TEST_TARGET = main_test

.PHONY: all clean test coverage report

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) -o $@ $(SOURCES)

$(TEST_TARGET): $(TEST_SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(COVERAGE_FLAGS) -o $@ $(TEST_SOURCES) $(LDFLAGS)

test: $(TEST_TARGET)
	@echo "Running tests..."
	./$(TEST_TARGET)

run: $(TARGET)
	@echo "Running main program..."
	./$(TARGET)

coverage: test run
	@echo "Generating coverage data..."
	gcov -m functions.cpp

report: coverage
	@echo "Generating HTML coverage report..."
	mkdir -p coverage_report
	lcov --capture --directory . --output-file coverage_report/coverage.info --rc derive_function_end_line=0
	genhtml coverage_report/coverage.info --output-directory coverage_report --rc derive_function_end_line=0
	@echo "Coverage report generated in coverage_report/index.html"

summary: coverage
	@echo "Coverage summary:"
	lcov --capture --directory . --output-file temp_coverage.info --rc derive_function_end_line=0
	lcov --summary temp_coverage.info
	rm -f temp_coverage.info

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.gcda *.gcno *.gcov *.o temp_coverage.info
	rm -rf coverage_report

help:
	@echo "Available targets:"
	@echo "  all      - Build both main and test executables"
	@echo "  test     - Run the test suite"
	@echo "  run      - Run the main program"
	@echo "  coverage - Generate coverage data"
	@echo "  report   - Generate HTML coverage report"
	@echo "  summary  - Show coverage summary"
	@echo "  clean    - Remove all generated files"
	@echo "  help     - Show this help message"