// console_interface.h
// Консольный интерфейс программы
// Студент группы 4503, Илья М, 2026

#ifndef ITAP_TESTS_MAIN_MENU_H
#define ITAP_TESTS_MAIN_MENU_H
#include "task_1.h"
#include "task_2.h"

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

enum test_2_menu_options {
    OPTION_ADD_REGULAR_PRODUCT = 1,
    OPTION_ADD_PRODUCT_ON_STORAGE = 2,
    OPTION_PRINT_PRODUCTS_LIST = 3,
    OPTION_PRINT_PRODUCTS_ON_STORAGE_LIST = 4,
    OPTION_CLEAR_LISTS = 5,

};
void main_menu();

void task_1_menu();
void print_buses(const std::list<Bus> & buses);
void add_bus(std::list<Bus>& buses);
void remove_buses(std::list<Bus>& buses);

void task_2_menu();
void add_regular_product(std::list<std::shared_ptr<Product>>& products);
void add_product_on_storage(std::list<std::shared_ptr<Product>>& products, std::list<std::shared_ptr<Product_On_Storage>>& products_on_storage);

#endif // ITAP_TESTS_MAIN_MENU_H
