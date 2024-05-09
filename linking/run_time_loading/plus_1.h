#ifndef PLUS_1_H__
#define PLUS_1_H__

#include <iostream>

extern "C" {
std::string get_library_purpose();
int add_one_to_int(int x);
}
#endif