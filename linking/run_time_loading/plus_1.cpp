#include <string>
#include "plus_1.h"

int add_one_to_int(int x);

extern "C" std::string get_library_purpose() {
    return std::string("lib purpose : add 1 to passed number");
}

extern "C" int add_one_to_int(int x) {
    return x + 1;
}