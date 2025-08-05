#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "path_logic.hpp"
#include <string>

TEST_CASE("Testing path logic") {
    // We now directly call the function and check its return value.
    // This is much cleaner and more efficient than executing a separate program.
    CHECK(get_path(true,  true,  true)  == "path 1");
    CHECK(get_path(true,  true,  false) == "path 1");
    CHECK(get_path(true,  false, true)  == "path 1");
    CHECK(get_path(true,  false, false) == "path 2");
    CHECK(get_path(false, true,  true)  == "path 1");
    CHECK(get_path(false, true,  false) == "path 2");
    CHECK(get_path(false, false, true)  == "path 1");
    CHECK(get_path(false, false, false) == "path 2");
}