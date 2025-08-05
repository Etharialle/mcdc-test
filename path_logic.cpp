#include "path_logic.hpp"

// Implements the function
std::string get_path(bool a, bool b, bool c) {
    if ((a && b) || c) {
        return "path 1";
    } else {
        return "path 2";
    }
}