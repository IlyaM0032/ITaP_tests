//
// Created by ilyam0032 on 21.02.26.
//

#include <iostream>
#include <string>

int read_int() {
    std::string input;
    std::getline(std::cin, input);
    bool success = false;
    int result = 0;

    do {
        try {
            result = std::stoi(input);
            success = true;
        } catch (std::invalid_argument &e) {
            std::cout << "Некорректный ввод, попробуйте ещё раз: ";
            std::getline(std::cin, input);
        }
    } while (!success);

    return result;
}
