// utils.cpp
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#include "utils.h"
#include "task_1.h"

#include <iostream>
#include <string>

void print_showables_list(const std::list<std::shared_ptr<Ishowable>>& showables) {
    if (showables.empty()) {
        std::cout << "Список пуст" << std::endl;
    } else {
        for (const std::shared_ptr<Ishowable>& showable : showables) {
            std::cout << showable->show() << std::endl;
        }
    }
}

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

char read_char() {
    std::string input;
    bool success = false;
    char result = 0;
    do {
        std::getline(std::cin, input);
        if (!input.empty() && std::isalpha(input[0])) {
            result = input[0];
            success = true;
        } else {
            std::cout << "Некорректный ввод. Попробуйте ещё раз: ";
        }
    } while (!success);

    return result;
}