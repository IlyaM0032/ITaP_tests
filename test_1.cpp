// test_1.cpp
// Контрольная работа №1
// Студент группы 4503, Илья М, 2026

#include <iostream>
#include <list>
#include <regex>
#include "test_1.h"
#include "utils.h"

void Bus::show() const {
    std::cout << "Номер автобуса: " << number
              << " Номер маршрута: " << route_number
              << " Марка: \"" << brand
              << "\" Год начала эксплуатации: " << exploitation_start_year
              << " Пробег: " << kilometrage
              << " Водитель: \"" << driver << "\""
              << std::endl;
}

void test_1() {
    std::cout << "\n***Первая контрольная работа***\n";
    test_1_menu();
}

std::list<Bus> get_buses_by_route(const std::list<Bus>& buses) {
    std::list<Bus> buses_by_route;
    std::cout << "Введите номер маршрута (натуральное число): ";
    int route = read_natural();

    for (const Bus& i : buses) {
        if (i.get_route_number() == route) buses_by_route.push_back(i);
    }

    return buses_by_route;
}
std::list<Bus> get_buses_over_10_years(const std::list<Bus>& buses) {
    std::list<Bus> buses_over_10_years;

    for (const Bus& i : buses) {
        if (i.get_exploitation_start_year() < (CURRENT_YEAR - 10)) buses_over_10_years.push_back(i);
    }

    return buses_over_10_years;
}
std::list<Bus> get_buses_over_10k_km(const std::list<Bus>& buses) {
    std::list<Bus> buses_over_10k_km;

    for (const Bus& i : buses) {
        if (i.get_kilometrage() > 10000) buses_over_10k_km.push_back(i);
    }

    return buses_over_10k_km;
}

void print_buses(const std::list<Bus>& buses) {
    if (buses.empty()) {
        std::cout << "Список пуст" << std::endl;
    } else {
        for (const Bus& i : buses) {i.show();}
    }
}

void add_bus(std::list<Bus>& buses) {
    bool valid = false;

    std::string number;
    std::cout << "Введите номер автобуса в формате \"A111AA\" (латинскими символами): ";
    const std::regex number_pattern("^[ABEKMHOPCTYX]\\d{3}[ABEKMHOPCTYX]{2}$");
    do {
        std::getline(std::cin, number);
        valid = std::regex_match(number, number_pattern);
        if (!valid) std::cout << "Введенное значение \"" << number << "\" не соответствует формату. Попробуйте ещё раз: ";
    } while (!valid);


    std::cout << "Введите номер маршрута (натуральное число): ";
    int route = read_natural();


    std::string brand;
    std::cout << "Введите марку автобуса: ";
    std::getline(std::cin, brand);


    std::cout << "Введите год начала эксплуатации автобуса (натуральное число): ";
    int year = read_natural();


    std::cout << "Введите пробег автобуса (натуральное число): ";
    int kilometrage = read_natural();


    std::string driver;
    std::cout << "Введите фамилию и инициалы водителя автобуса в формате Фамилия A. Б. (латинскими символами): ";
    std::regex driver_pattern("^[A-Z][a-z]* [A-Z]\\. [A-Z]\\.$");
    do {
        std::getline(std::cin, driver);
        valid = std::regex_match(driver, driver_pattern);
        if (!valid) std::cout << "Введенное значение \"" << driver << "\" не соответствует формату. Попробуйте ещё раз: ";
    } while (!valid);


    buses.emplace_back(number, route, brand, year, kilometrage, driver);
}

void remove_buses(std::list<Bus>& buses) {
    buses.clear();
    print_buses(buses);
}

void test_1_menu() {
    std::list<Bus> buses;
    std::list<Bus> got_buses;


    buses.emplace_back(
        SAMPLE_BUS_NUMBER,
        SAMPLE_BUS_ROUTE,
        SAMPLE_BUS_BRAND,
        SAMPLE_BUS_YEAR,
        SAMPLE_BUS_KM,
        SAMPLE_BUS_DRIVER
        );

    while (true) {
        std::string input;
        int decision = 0;

        std::cout << std::endl;
        std::cout << "1) Получить список автобусов для заданного номера маршрута" << std::endl;
        std::cout << "2) Получить список автобусов, которые эксплуатируются больше 10 лет" << std::endl;
        std::cout << "3) Получить список автобусов, пробег у которых больше 10 000 км" << std::endl;
        std::cout << "4) Вывести полученный список" << std::endl;
        std::cout << "5) Вывести список всех автобусов" << std::endl;
        std::cout << "6) Добавить автобус" << std::endl;
        std::cout << "7) Удалить все автобусы из списка" << std::endl;
        std::cout << "0) Вернуться в меню выбора контрольных работ" << std::endl;
        std::cout << std::endl;

        std::cout << "Выберите соответствующий пункт меню: ";

        bool completed = false;
        while (!completed) {
            decision = read_int();
            switch (decision) {
            case OPTION_BUSES_BY_ROUTE:
                got_buses = get_buses_by_route(buses);
                std::cout << "Успешно! Вывести полученный список можно выбрав пункт 4" << std::endl;
                completed = true;
                break;

            case OPTION_BUSES_OVER_10_YEARS:
                got_buses = get_buses_over_10_years(buses);
                std::cout << "Успешно! Вывести полученный список можно выбрав пункт 4" << std::endl;
                completed = true;
                break;

            case OPTION_BUSES_OVER_10K_KM:
                got_buses = get_buses_over_10k_km(buses);
                std::cout << "Успешно! Вывести полученный список можно выбрав пункт 4" << std::endl;
                completed = true;
                break;

            case OPTION_PRINT_LIST:
                print_buses(got_buses);

                completed = true;
                break;

            case OPTION_PRINT_ALL:
                print_buses(buses);

                completed = true;
                break;

            case OPTION_ADD_BUS:
                add_bus(buses);

                completed = true;
                break;

            case OPTION_EMPTY_BUS_LIST:
                remove_buses(buses);

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