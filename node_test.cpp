#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>
#include <array>
#include <cstdio>
#include <memory>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

TEST_CASE("Testing all conditions") {
    SUBCASE("a=true, b=true, c=true") {
        std::string output = exec("./node true true true");
        CHECK(output == "path 1\n");
    }
    SUBCASE("a=true, b=true, c=false") {
        std::string output = exec("./node true true false");
        CHECK(output == "path 1\n");
    }
    SUBCASE("a=true, b=false, c=true") {
        std::string output = exec("./node true false true");
        CHECK(output == "path 1\n");
    }
    SUBCASE("a=true, b=false, c=false") {
        std::string output = exec("./node true false false");
        CHECK(output == "path 2\n");
    }
    SUBCASE("a=false, b=true, c=true") {
        std::string output = exec("./node false true true");
        CHECK(output == "path 1\n");
    }
    SUBCASE("a=false, b=true, c=false") {
        std::string output = exec("./node false true false");
        CHECK(output == "path 2\n");
    }
    SUBCASE("a=false, b=false, c=true") {
        std::string output = exec("./node false false true");
        CHECK(output == "path 1\n");
    }
    SUBCASE("a=false, b=false, c=false") {
        std::string output = exec("./node false false false");
        CHECK(output == "path 2\n");
    }
}