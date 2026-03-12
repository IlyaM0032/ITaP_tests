// task_1.h
// Контрольная работа №1
// Студент группы 4503, Илья М, 2026

#ifndef ITAP_TESTS_TASK_1_H
#define ITAP_TESTS_TASK_1_H
#include <regex>
#include <string>
#include <list>

#define YEARS_THRESHOLD 10
#define KILOMETERS_THRESHOLD 10000

#define SECONDS_PER_YEAR (60*60*24*365)
#define EPOCH_START 1970

#define SAMPLE_BUS_NUMBER "B522OY"
#define SAMPLE_BUS_ROUTE 68
#define SAMPLE_BUS_BRAND "Volgabus"
#define SAMPLE_BUS_YEAR 2025
#define SAMPLE_BUS_KM 4321
#define SAMPLE_BUS_DRIVER "Yakovlev I. A."


class Bus {
    std::string number;
    int route_number;
    std::string brand;
    int exploitation_start_year;
    double kilometrage;
    std::string driver;
    const std::regex number_pattern = std::regex("^[ABEKMHOPCTYX]\\d{3}[ABEKMHOPCTYX]{2}$");
    const std::regex driver_pattern = std::regex("^[A-Z][a-z]* [A-Z]\\. [A-Z]\\.$");

    public:
    Bus() :
    route_number(0), exploitation_start_year(0), kilometrage(0)
    {}

    std::string get_number() const {return number;}
    int get_route_number() const {return route_number;}
    std::string get_brand() const {return brand;}
    int get_exploitation_start_year() const {return exploitation_start_year;}
    double get_kilometrage() const {return kilometrage;}
    std::string get_driver() const {return driver;}

    bool set_number(std::string p_number);
    bool set_route_number(int p_route);
    bool set_brand(std::string p_brand);
    bool set_exploitation_start_year(int p_year);
    bool set_kilometrage(double p_km);
    bool set_driver(std::string p_driver);

    std::string show() const;

};

std::list<Bus> get_buses_by_route(const std::list<Bus>& buses, int route);
std::list<Bus> get_buses_over_10_years(const std::list<Bus>& buses);
std::list<Bus> get_buses_over_10k_km(const std::list<Bus>& buses);

const int CURRENT_YEAR = static_cast<int> (EPOCH_START+ std::time(nullptr) / SECONDS_PER_YEAR);

#endif // ITAP_TESTS_TASK_1_H
