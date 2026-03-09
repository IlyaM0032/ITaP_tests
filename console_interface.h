//
// Created by ilyam0032 on 10.03.2026.
//

#ifndef ITAP_TESTS_MAIN_MENU_H
#define ITAP_TESTS_MAIN_MENU_H
#include "task_1.h"

enum main_menu_options {
    OPTION_EXIT = 0,
    OPTION_TEST_1 = 1,
    OPTION_TEST_2 = 2,
    OPTION_TEST_3 = 3
};

enum test_1_menu_options {
    OPTION_BUSES_BY_ROUTE = 1,
    OPTION_BUSES_OVER_10_YEARS = 2,
    OPTION_BUSES_OVER_10K_KM = 3,
    OPTION_PRINT_LIST = 4,
    OPTION_PRINT_ALL = 5,
    OPTION_ADD_BUS = 6,
    OPTION_EMPTY_BUS_LIST = 7,
};
void main_menu();

void task_1_menu();
void print_buses(const std::list<Bus> & buses);
void add_bus(std::list<Bus>& buses);
void remove_buses(std::list<Bus>& buses);


#endif // ITAP_TESTS_MAIN_MENU_H
