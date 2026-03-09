// task_1.cpp
// Контрольная работа №1
// Студент группы 4503, Илья М, 2026

#include "task_1.h"
#include <list>
#include <regex>
#include <ctime>

std::string Bus::show() const {
    std::string result_string =
        "Номер автобуса: " + get_number() +
        " Номер маршрута: " + std::to_string(get_route_number()) +
        " Марка: \"" + get_brand() +
        "\" Год начала эксплуатации: " + std::to_string(exploitation_start_year) +
        " Пробег: " + std::to_string(kilometrage) +
        " Водитель: \"" + get_driver();
    return result_string;
}

bool Bus::set_number(std::string p_number) {
    if (std::regex_match(p_number, number_pattern)) {
        number = std::move(p_number);
        return true;
    }
    return false;
}
bool Bus::set_route_number(int p_route) {
    if (p_route > 0) {
        route_number = p_route;
        return true;
    };
    return false;
}
bool Bus::set_brand(std::string p_brand) {
    if (!p_brand.empty()) {
        brand = std::move(p_brand);
        return true;
    }
    return false;
}
bool Bus::set_exploitation_start_year(int p_year) {
    if (p_year >= 0) {
        exploitation_start_year = p_year;
        return true;
    };
    return false;
}
bool Bus::set_kilometrage(double p_km) {
    if (p_km >= 0) {
        kilometrage = p_km;
        return true;
    };
    return false;
}
bool Bus::set_driver(std::string p_driver) {
    if (std::regex_match(p_driver, driver_pattern)) {
        driver = std::move(p_driver);
        return true;
    }
    return false;
}

std::list<Bus> get_buses_by_route(const std::list<Bus>& buses, int route) {
    std::list<Bus> buses_by_route;
    for (const Bus& i : buses) {
        if (i.get_route_number() == route) buses_by_route.push_back(i);
    }
    return buses_by_route;
}
std::list<Bus> get_buses_over_10_years(const std::list<Bus>& buses) {
    std::list<Bus> buses_over_10_years;
    for (const Bus& i : buses) {
        if (i.get_exploitation_start_year() < (CURRENT_YEAR - YEARS_THRESHOLD)) buses_over_10_years.push_back(i);
    }
    return buses_over_10_years;
}
std::list<Bus> get_buses_over_10k_km(const std::list<Bus>& buses) {
    std::list<Bus> buses_over_10k_km;
    for (const Bus& i : buses) {
        if (i.get_kilometrage() > KILOMETERS_THRESHOLD) buses_over_10k_km.push_back(i);
    }
    return buses_over_10k_km;
}
