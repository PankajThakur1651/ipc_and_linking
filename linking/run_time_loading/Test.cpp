#include <iostream>
#include <stdlib.h>
#include <dlfcn.h>
#include <filesystem>


int main(int argc, char **argv) {
    if (argc <= 2) {
        std::cout << "Usage: so name, value" << std::endl;
        exit(1);
    }

    auto file_path = std::filesystem::current_path();
    file_path = file_path.string().append("/second_project/") + argv[1];
    if (!std::filesystem::exists(file_path.c_str()))
    {
        std::cerr << "so file path does not exist " << file_path << std::endl;
        exit(1);
    }

    int number = atoi(argv[2]);

    void *handle = dlopen(file_path.c_str(), RTLD_LAZY);
    if (handle == nullptr) {
        std::cerr << "dlopen failure \n";
        exit(1);
    }

    auto fptr = (int (*)(int)) dlsym(handle, "add_one_to_int");
    if (fptr == nullptr) {
        std::cout << "fptr is invalid exiting ..." << std::endl;
        exit(1);
    }

    std::cout << "original Number: " << number << std::endl;
    std::cout << "New Number: " << fptr(number) << std::endl;


    auto fptr_1 = (std::string (*)()) dlsym(handle, "get_library_purpose");
    if (fptr == nullptr) {
        std::cout << "fptr is invalid exiting ..." << std::endl;
        exit(1);
    }
    std::cout << fptr_1() << std::endl;
    dlclose(handle);
}