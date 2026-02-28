// test_1.h
// Контрольная работа №1
// Студент группы 4503, Илья М, 2026

#ifndef ITAP_TESTS_TEST_1_H
#define ITAP_TESTS_TEST_1_H
#include <string>

#define CURRENT_YEAR 2026

#define SAMPLE_BUS_NUMBER L"В522ОУ"
#define SAMPLE_BUS_ROUTE 68
#define SAMPLE_BUS_BRAND L"Volgabus"
#define SAMPLE_BUS_YEAR 2025
#define SAMPLE_BUS_KM 4321
#define SAMPLE_BUS_DRIVER L"Яковлев И. А."

void test_1();
void test_1_menu();



enum test_1_menu_options {
    OPTION_BUSES_BY_ROUTE = 1,
    OPTION_BUSES_OVER_10_YEARS = 2,
    OPTION_BUSES_OVER_10K_KM = 3,
    OPTION_PRINT_LIST = 4,
    OPTION_PRINT_ALL = 5,
    OPTION_ADD_BUS = 6,
};

class Bus {
    std::wstring number;
    int route_number;
    std::wstring brand;
    int exploitation_start_year;
    int kilometrage;
    std::wstring driver;

    public:
    Bus(std::wstring p_number, int p_route, std::wstring  p_brand, int p_year, int p_km, std::wstring p_driver) :
    number(std::move(p_number)), route_number(p_route), brand(std::move(p_brand)), exploitation_start_year(p_year), kilometrage(p_km), driver(std::move(p_driver))
    {}

    std::wstring get_number() const {return number;}
    int get_route_number() const {return route_number;}
    std::wstring get_brand() const {return brand;}
    int get_exploitation_start_year() const {return exploitation_start_year;}
    int get_kilometrage() const {return kilometrage;}
    std::wstring get_driver() const {return driver;}

    void set_number(std::wstring p_number) {number = std::move(p_number);}
    void set_route_number(int p_route) {route_number = p_route;}
    void set_brand(std::wstring p_brand) {brand = std::move(p_brand);}
    void set_exploitation_start_year(int p_year) {exploitation_start_year = p_year;}
    void set_kilometrage(int p_km) {kilometrage = p_km;}
    void set_driver(std::wstring p_driver) {driver = std::move(p_driver);}

    void show() const;

};
#endif // ITAP_TESTS_TEST_1_H
