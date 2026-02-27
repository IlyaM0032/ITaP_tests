// test_1.cpp
// Контрольная работа №1
// Студент группы 4503, Илья М, 2026

#include <iostream>
#include <list>
#include "test_1.h"
#include "utils.h"

void Bus::show() const {
    std::cout << "Номер автобуса: " << number
              << " Номер маршрута: " << route_number << " Марка: " << brand
              << " Год начала эксплуатации: " << exploitation_start_year
              << " Пробег: " << kilometrage << " Водитель: " << driver
              << std::endl;
}

void test_1() {
    std::cout << "\n***Первая контрольная работа***\n";
    test_1_menu();
}

std::list<Bus> get_buses_by_route(const std::list<Bus>& buses) {
    std::list<Bus> buses_by_route;

    for (const Bus& i : buses) {
        if (i.get_route_number() == 68) buses_by_route.push_back(i);
    }

    return buses_by_route;
}
std::list<Bus> get_buses_over_10_years(const std::list<Bus>& buses) {
    std::list<Bus> buses_over_10_years;

    for (const Bus& i : buses) {
        if (i.get_exploitation_start_year() > (CURRENT_YEAR - 10)) buses_over_10_years.push_back(i);
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
    std::cout << "В разработке" << std::endl; // TODO: Разработать
    // std::cout << "Введите номер автобуса в формате A111AA: ";
    // std::cout << "Введите номер маршрута (натуральное число): ";
    // std::cout << "Введите марку автобуса: ";
    // std::cout << "Введите год начала эксплуатации автобуса: ";
    // std::cout << "Введите пробег автобуса: ";
    // std::cout << "Введите фамилию и инициалы водителя автобуса в формате Фамилия A. Б. : ";
    // buses.emplace_back();
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
        std::cout << "1) Получить список автобусов заданного маршрута" << std::endl;
        std::cout << "2) Получить список автобусов, эксплуатирующиеся более 10-ти лет" << std::endl;
        std::cout << "3) Получить список автобусов с пробегом более 10 000 км" << std::endl;
        std::cout << "4) Вывести полученный список" << std::endl;
        std::cout << "5) Вывести список всех автобусов" << std::endl;
        // std::cout << "6) Добавить автобус" << std::endl;
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
                got_buses = get_buses_by_route(buses);
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

            case OPTION_EXIT:
                return;

            default:
                std::cout << "Нет такого пункта меню. Попробуйте ещё раз: ";
            }
        }
    }
}