// utils.cpp
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#include "utils.h"

#ifdef _WIN32
#define timegm _mkgmtime
#endif

#include <chrono>
#include <ctime>
#include <iomanip>
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

time_t read_time() {
    std::string input;
    bool success = false;
    time_t result = 0;
    std::tm result_tm{};
    do {
        std::getline(std::cin, input);
        std::istringstream input_stream {input};
        input_stream >> std::get_time(&result_tm, DATE_FORMAT);

        if (input_stream.fail()) {
            std::cout << "Некорректный ввод. Попробуйте ещё раз: ";
        } else {
            const std::tm result_tm_copy = result_tm;
            result = timegm(&result_tm);
            if (
                result_tm.tm_year != result_tm_copy.tm_year ||
                result_tm.tm_mon != result_tm_copy.tm_mon ||
                result_tm.tm_mday != result_tm_copy.tm_mday ||
                result_tm.tm_hour != result_tm_copy.tm_hour ||
                result_tm.tm_min != result_tm_copy.tm_min
                ) {
                std::cout << "Некорректный ввод. Попробуйте ещё раз: ";
            } else {
                success = true;
            }

        }

    } while (!success);
    return result;
}

std::string time_t_to_string(const time_t t) {
    std::stringstream result;
    std::tm tm;
#ifdef _WIN32
    gmtime_s(&tm, &t);
#else
    gmtime_r(&t, &tm);
#endif
    result << std::put_time(&tm, "%c");
    return result.str();
}