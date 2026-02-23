// test_1.h
// Контрольная работа №1
// Студент группы 4503, Илья М, 2026

#ifndef ITAP_TESTS_TEST_1_H
#define ITAP_TESTS_TEST_1_H
#include <string>

void test_1();

class Bus {
    std::string number;
    int route_number;
    std::string brand;
    int exploitation_start_year;
    int kilometrage;
    std::string driver;

    public:
    Bus(std::string p_number, int p_route, std::string  p_brand, int p_year, int p_km, std::string p_driver) :
    number(std::move(p_number)), route_number(p_route), brand(std::move(p_brand)), exploitation_start_year(p_year), kilometrage(p_km), driver(std::move(p_driver))
    {}

    std::string get_number() const {return number;}
    int get_route_number() const {return route_number;}
    std::string get_brand() const {return brand;}
    int get_exploitation_start_year() const {return exploitation_start_year;}
    int get_kilometrage() const {return kilometrage;}
    std::string get_driver() const {return driver;}

    void set_number(std::string p_number) {number = std::move(p_number);}
    void set_route_number(int p_route) {route_number = p_route;}
    void set_brand(std::string p_brand) {brand = std::move(p_brand);}
    void set_exploitation_start_year(int p_year) {exploitation_start_year = p_year;}
    void set_kilometrage(int p_km) {kilometrage = p_km;}
    void set_driver(std::string p_driver) {driver = std::move(p_driver);}

    void show();

};
#endif // ITAP_TESTS_TEST_1_H
