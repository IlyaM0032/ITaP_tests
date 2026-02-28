// utils.cpp
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#include "utils.h"
#include "test_1.h"

#include <iostream>
#include <string>


int read_int() {
    std::wstring input;
    bool success = false;
    int result = 0;

    do {
        try {
            std::getline(std::wcin, input);
            result = std::stoi(input);
            success = true;
        } catch (std::invalid_argument &e) {
            std::wcout << L"Некорректный ввод. Попробуйте ещё раз: ";
        }
    } while (!success);

    return result;
}

int read_natural() {
    int result = 0;
    do {
        result = read_int();
        if (result > 0) return result;
        std::wcout << L"Полученное число не натуральное. Попробуйте ещё раз: ";
    } while (true);
}

void tests_menu() {
    while (true) {
        std::wstring input;
        int decision = 0;

        std::wcout << std::endl;
        std::wcout << L"1) Выбрать контрольную работу 1" << std::endl;
        // std::wcout << L"2) Выбрать контрольную работу 2" << std::endl;
        // std::wcout << L"3) Выбрать контрольную работу 3" << std::endl;
        std::wcout << L"0) Выход" << std::endl;
        std::wcout << std::endl;

        std::wcout << L"Выберите соответствующий пункт меню: ";

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
                std::wcout << L"Нет такого пункта меню. Попробуйте ещё раз: ";
            }
        }
    }

}