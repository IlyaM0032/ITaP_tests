// utils.cpp
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#include "utils.h"

#include <iostream>
#include <string>
#include "test_1.h"

int read_int() {
    std::string input;
    bool success = false;
    int result = 0;

    do {
        try {
            std::getline(std::cin, input);
            result = std::stoi(input);
            success = true;
        } catch (std::invalid_argument &e) {
            std::cout << "Некорректный ввод. Попробуйте ещё раз: ";
        }
    } while (!success);

    return result;
}

void tests_menu() {
    while (true) {
        std::string input;
        int decision = 0;

        std::cout << "1) Выбрать контрольную работу 1" << std::endl;
        // std::cout << "2) Выбрать контрольную работу 2" << std::endl;
        // std::cout << "3) Выбрать контрольную работу 3" << std::endl;
        std::cout << "0) Выход" << std::endl;
        std::cout << "Выберите соответствующий пункт меню: ";

        bool completed = false;
        while (!completed) {
            decision = read_int();
            switch (decision) {
            case OPTION_TEST_1:
                test_1();
                completed = true;
                break;
            case OPTION_EXIT:
                return;
            default:
                std::cout << "Нет такого пункта меню. Попробуйте ещё раз: ";
            }
        }
    }

}