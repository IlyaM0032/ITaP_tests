// task_2.h
// Контрольная работа №2
// Студент группы 4503, Илья М, 202

#ifndef ITAP_TESTS_TASK_2_H
#define ITAP_TESTS_TASK_2_H
#include "utils.h"

#include <string>

#define TM_YEAR_OFFSET 1900
#define TM_MONTH_OFFSET 1

enum submatches_indexes {
    entire_string_index = 0,
    day_index = 1,
    month_index = 2,
    year_index = 3,
    hour_index = 4,
    minute_index = 5,
};

enum date_limits {
    day_min = 1,
    day_max = 31,
    month_min = 1,
    month_max = 12,
    year_min = 1970,
    year_max = 3000,
    hour_min = 0,
    hour_max = 23,
    minute_min = 0,
    minute_max = 59,
};

struct storage_place_s {
    char sector;
    int row;
    int shelf;
    int layer;
    storage_place_s(const char p_sector, const int p_row, const int p_shelf, const int p_layer):
    sector(p_sector), row(p_row), shelf(p_shelf), layer(p_layer)  {}
};

class Product : public IShowable {
    std::string name;
    double quantity;
    std::string manufacturer;
    double unit_price;

    public:
    Product() : quantity(0), unit_price(0) {}
    ~Product() override = default;

    [[nodiscard]] std::string get_name() const {return name;}
    [[nodiscard]] double get_quantity() const {return quantity;}
    [[nodiscard]] std::string get_manufacturer() const {return manufacturer;}
    [[nodiscard]] double get_unit_price() const {return unit_price;}
    [[nodiscard]] double get_total_price() const {return quantity * unit_price;}

    [[nodiscard]] bool set_name(std::string p_name);
    [[nodiscard]] bool set_quantity(double p_quantity);
    [[nodiscard]] bool set_manufacturer(std::string p_manufacturer);
    [[nodiscard]] bool set_unit_price(double p_unit_price);

    [[nodiscard]] std::string show() const override;
};

class Product_On_Storage : public Product {
    storage_place_s storage_place;
    time_t arrival_date;

    public:
    Product_On_Storage() :
    storage_place('\0', 0, 0, 0), arrival_date(0) {}
    ~Product_On_Storage() override = default;

    [[nodiscard]] char get_storage_sector() const {return storage_place.sector;}
    [[nodiscard]] int get_storage_row() const {return storage_place.row;}
    [[nodiscard]] int get_storage_shelf() const {return storage_place.shelf;}
    [[nodiscard]] int get_storage_layer() const {return storage_place.layer;}
    [[nodiscard]] time_t get_arrival_date() const {return arrival_date;}

    [[nodiscard]] bool set_storage_sector(char p_storage_sector);
    [[nodiscard]] bool set_storage_row(int p_storage_row);
    [[nodiscard]] bool set_storage_shelf(int p_storage_shelf);
    [[nodiscard]] bool set_storage_layer(int p_storage_layer);
    [[nodiscard]] bool set_arrival_date(time_t p_arrival_date);


    [[nodiscard]] std::string show() const override;
};

#endif // ITAP_TESTS_TASK_2_H
