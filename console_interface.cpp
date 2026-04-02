// console_interface.cpp
// Консольный интерфейс программы
// Студент группы 4503, Илья М, 2026

#include "console_interface.h"

#include "task_1.h"
#include "task_2.h"
#include "utils.h"

#include <iostream>
#include <list>

void main_menu() {
    bool continue_cycle = true;
    do {
        std::cout << std::endl;
        std::cout << "1) Выбрать контрольную работу 1" << std::endl;
        std::cout << "2) Выбрать контрольную работу 2" << std::endl;
        // std::cout << "3) Выбрать контрольную работу 3" << std::endl;
        std::cout << "0) Выход" << std::endl;
        std::cout << std::endl;
        std::cout << "Выберите соответствующий пункт меню: ";

        bool input_again = false;
        do {
            input_again = false;
            switch (read_int()) {
            case OPTION_TEST_1:
                task_1_menu();
                break;

            case OPTION_TEST_2:
                task_2_menu();
                break;

            case OPTION_EXIT:
                continue_cycle = false;
                break;

            default:
                std::cout << "Нет такого пункта меню. Попробуйте ещё раз: ";
                input_again = true;
            }
        } while (input_again);
    } while (continue_cycle);
}

void task_1_menu() {
    std::list<Bus> buses;
    std::list<Bus> got_buses;


    Bus sample_bus;
    sample_bus.set_number(SAMPLE_BUS_NUMBER);
    sample_bus.set_route_number(SAMPLE_BUS_ROUTE);
    sample_bus.set_brand(SAMPLE_BUS_BRAND);
    sample_bus.set_exploitation_start_year(SAMPLE_BUS_YEAR);
    sample_bus.set_kilometrage(SAMPLE_BUS_KM);
    sample_bus.set_driver(SAMPLE_BUS_DRIVER);
    buses.push_back(sample_bus);
    bool continue_cycle = true;
    do {
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

        bool input_again = false;
        do {
            int selected_route = 0;
            input_again = false;
            switch (read_int()) {
            case OPTION_BUSES_BY_ROUTE:
                std::cout << "Введите номер маршрута (натуральное число): ";
                selected_route = read_natural();
                got_buses = get_buses_by_route(buses, selected_route);
                std::cout << "Успешно! Вывести полученный список можно выбрав пункт 4" << std::endl;
                break;

            case OPTION_BUSES_OVER_10_YEARS:
                got_buses = get_buses_over_10_years(buses);
                std::cout << "Успешно! Вывести полученный список можно выбрав пункт 4" << std::endl;
                break;

            case OPTION_BUSES_OVER_10K_KM:
                got_buses = get_buses_over_10k_km(buses);
                std::cout << "Успешно! Вывести полученный список можно выбрав пункт 4" << std::endl;
                break;

            case OPTION_PRINT_LIST:
                print_buses(got_buses);
                break;

            case OPTION_PRINT_ALL:
                print_buses(buses);
                break;

            case OPTION_ADD_BUS:
                add_bus(buses);
                break;

            case OPTION_EMPTY_BUS_LIST:
                remove_buses(buses);
                break;

            case OPTION_EXIT:
                continue_cycle = false;
                break;

            default:
                std::cout << "Нет такого пункта меню. Попробуйте ещё раз: ";
                input_again = true;
            }
        } while (input_again);
    } while (continue_cycle);
}

void print_buses(const std::list<Bus>& buses) {
    if (buses.empty()) {
        std::cout << "Список пуст" << std::endl;
    } else {
        for (const Bus& i : buses) {std::cout << i.show() << std::endl;}
    }
}
void add_bus(std::list<Bus>& buses) {

    Bus bus_to_add;

    bool success = false;

    std::cout << "Введите номер автобуса в формате \"A111AA\" (латинскими символами, совпадающими с кириллицей): ";
    do {
        std::string number;
        std::getline(std::cin, number);
        success = bus_to_add.set_number(number);
        if (!success) std::cout << "Введенное значение \"" << number << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите номер маршрута (натуральное число): ";
    do {
        int route = read_int();
        success = bus_to_add.set_route_number(route);
        if (!success) std::cout << "Введенное значение \"" << route << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите марку автобуса: ";
    do {
        std::string brand;
        std::getline(std::cin, brand);
        success = bus_to_add.set_brand(brand);
        if (!success) std::cout << "Введенное значение \"" << brand << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите год начала эксплуатации автобуса (положительное целое число): ";
    do {
        int year = read_int();
        success = bus_to_add.set_exploitation_start_year(year);
        if (!success) std::cout << "Введенное значение \"" << year << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите пробег автобуса (вещественное положительное число): ";
    do {
        double kilometrage = read_double();
        success = bus_to_add.set_kilometrage(kilometrage);
        if (!success) std::cout << "Введенное значение \"" << kilometrage << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите фамилию и инициалы водителя автобуса в формате Фамилия A. Б. (латинскими символами): ";
    do {
        std::string driver;
        std::getline(std::cin, driver);
        success = bus_to_add.set_driver(driver);
        if (!success) std::cout << "Введенное значение \"" << driver << "\" не соответствует формату. Попробуйте ещё раз: ";
    } while (!success);


    buses.push_back(bus_to_add);
}
void remove_buses(std::list<Bus>& buses) {
    buses.clear();
    print_buses(buses);
}

void task_2_menu() {
    std::list<std::shared_ptr<Product>> products;
    std::list<std::shared_ptr<Product_On_Storage>> products_on_storage;


    bool continue_cycle = true;
    do {
        std::cout << std::endl;
        std::cout << "1) Добавить в список товар" << std::endl;
        std::cout << "2) Добавить в списки товар, находящийся на складе" << std::endl;
        std::cout << "3) Вывести список всех товаров" << std::endl;
        std::cout << "4) Вывести список всех товаров, находящихся на складе" << std::endl;
        std::cout << "5) Очистить списки" << std::endl;
        std::cout << "0) Выход" << std::endl;

        std::cout << std::endl;
        std::cout << "Выберите соответствующий пункт меню: ";


        bool input_again = false;
        do {
            input_again = false;
            switch (read_int()) {
            case OPTION_ADD_REGULAR_PRODUCT:
                add_regular_product(products);
                break;

            case OPTION_ADD_PRODUCT_ON_STORAGE:
                add_product_on_storage(products, products_on_storage);
                break;

            case OPTION_PRINT_PRODUCTS_LIST:
                print_showables_list(products);
                break;

            case OPTION_PRINT_PRODUCTS_ON_STORAGE_LIST:
                print_showables_list(products_on_storage);
                break;

            case OPTION_CLEAR_LISTS:
                products.clear();
                products_on_storage.clear();
                break;


            case OPTION_EXIT:
                continue_cycle = false;
                break;

            default:
                std::cout << "Нет такого пункта меню. Попробуйте ещё раз: ";
                input_again = true;
            }
        } while (input_again);
    } while (continue_cycle);
}

void add_regular_product(std::list<std::shared_ptr<Product>>& products) {
    const std::shared_ptr<Product> product_to_add = std::make_shared<Product>();

    bool success = false;

    std::cout << "Введите название товара (на латинице): ";
    do {
        std::string name;
        std::getline(std::cin, name);
        success = product_to_add->set_name(name);
        if (!success) std::cout << "Введенное значение \"" << name << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите количество товара: ";
    do {
        const double quantity = read_double();
        success = product_to_add->set_quantity(quantity);
        if (!success) std::cout << "Введенное значение \"" << quantity << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите цену за единицу товара: ";
    do {
        const double unit_price = read_double();
        success = product_to_add->set_unit_price(unit_price);
        if (!success) std::cout << "Введенное значение \"" << unit_price << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите производителя товара (на латинице): ";
    do {
        std::string manufacturer;
        std::getline(std::cin, manufacturer);
        success = product_to_add->set_manufacturer(manufacturer);
        if (!success) std::cout << "Введенное значение \"" << manufacturer << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    products.push_back(product_to_add);
}
void add_product_on_storage(std::list<std::shared_ptr<Product>>& products, std::list<std::shared_ptr<Product_On_Storage>>& products_on_storage) {
    const std::shared_ptr<Product_On_Storage> product_to_add = std::make_shared<Product_On_Storage>();

    bool success = false;
    std::cout << "Введите название товара (на латинице): ";
    do {
        std::string name;
        std::getline(std::cin, name);
        success = product_to_add->set_name(name);
        if (!success) std::cout << "Введенное значение \"" << name << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите количество товара: ";
    do {
        const double quantity = read_double();
        success = product_to_add->set_quantity(quantity);
        if (!success) std::cout << "Введенное значение \"" << quantity << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите цену за единицу товара: ";
    do {
        const double unit_price = read_double();
        success = product_to_add->set_unit_price(unit_price);
        if (!success) std::cout << "Введенное значение \"" << unit_price << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите производителя товара (на латинице): ";
    do {
        std::string manufacturer;
        std::getline(std::cin, manufacturer);
        success = product_to_add->set_manufacturer(manufacturer);
        if (!success) std::cout << "Введенное значение \"" << manufacturer << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);



    std::cout << "Укажите местоположение товара на складе" << std::endl;
    std::cout << "Введите сектор (один заглавный символ латиницы): ";
    do {
        const char sector = read_char();
        success = product_to_add->set_storage_sector(sector);
        if (!success) std::cout << "Введенное значение \"" << sector << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите номер ряда (натуральное число): ";
    do {
        const int row = read_natural();
        success = product_to_add->set_storage_row(row);
        if (!success) std::cout << "Введенное значение \"" << row << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите номер стеллажа (натуральное число): ";
    do {
        const int shelf = read_natural();
        success = product_to_add->set_storage_shelf(shelf);
        if (!success) std::cout << "Введенное значение \"" << shelf << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите уровень стеллажа (натуральное число): ";
    do {
        const int layer = read_natural();
        success = product_to_add->set_storage_layer(layer);
        if (!success) std::cout << "Введенное значение \"" << layer << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    std::cout << "Введите дату поступления товара на склад (в формате \"31.12.1999 23:59\"): ";
    do {
        const time_t arrival_date = read_time();
        success = product_to_add->set_arrival_date(arrival_date);
        if (!success) std::cout << "Введенное значение \"" << arrival_date << "\" не соответствует требованиям. Попробуйте ещё раз: ";
    } while (!success);

    products.push_back(product_to_add);
    products_on_storage.push_back(product_to_add);
}