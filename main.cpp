#include "utils.h"
#include <iostream>

int main() {

    while (true) {
        int input = 0;
        std::cout << "Enter int value: ";
        input = read_int();
        std::cout << "Red: " << input << std::endl;
    }

    return 0;
}