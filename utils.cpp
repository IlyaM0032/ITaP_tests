// utils.cpp
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#include "utils.h"
#include "task_1.h"

#include <iostream>
#include <string>


int read_int() {
    std::string input;
    bool success = false;
    int result = 0;

    do {
        try {
            std::getline(std::cin, input);
            result = std::stoi(input);
            success = true;
        } catch (std::invalid_argument &) {
            std::cout << "Некорректный ввод. Попробуйте ещё раз: ";
        }
    } while (!success);

    return result;
}

double read_double() {
    std::string input;
    bool success = false;
    double result = 0;

    do {
        try {
            std::getline(std::cin, input);
            result = std::stod(input);
            success = true;
        } catch (std::invalid_argument &) {
            std::cout << "Некорректный ввод. Попробуйте ещё раз: ";
        }
    } while (!success);

    return result;
}

int read_natural() {
    int result = 0;
    bool valid = false;
    do {
        result = read_int();
        valid = (result > 0);
        if (!valid) std::cout << "Полученное число не натуральное. Попробуйте ещё раз: ";
    } while (!valid);
    return result;
}
