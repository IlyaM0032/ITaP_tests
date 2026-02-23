// test_1.cpp
// Контрольная работа №1
// Студент группы 4503, Илья М, 2026

#include <iostream>
#include "test_1.h"

void Bus::show() {
    std::cout << "Номер автобуса: " << number
              << " Номер маршрута: " << route_number << " Марка: " << brand
              << " Год начала эксплуатации: " << exploitation_start_year
              << " Пробег: " << kilometrage << " Водитель: " << driver
              << std::endl;
}

void test_1() {
    std::cout << "\n*** test_1 ***\n\n";
}