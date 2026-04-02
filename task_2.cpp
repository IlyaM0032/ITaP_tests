// task_2.cpp
// Контрольная работа №2
// Студент группы 4503, Илья М, 2026

#include "task_2.h"

bool Product::set_name(std::string p_name) {
    if (!p_name.empty()) {
        name = std::move(p_name);
        return true;
    }
    return false;
}
bool Product::set_quantity(const double p_quantity) {
    if (p_quantity > 0) {
        quantity = p_quantity;
        return true;
    }
    return false;
}
bool Product::set_manufacturer(std::string p_manufacturer) {
    if (!p_manufacturer.empty()) {
        manufacturer = std::move(p_manufacturer);
        return true;
    }
    return false;
}
bool Product::set_unit_price(const double p_unit_price) {
    if (p_unit_price > 0) {
        unit_price = p_unit_price;
        return true;
    }
    return false;
}
std::string Product::show() const {
    std::string return_string =
        "Наименование: " + name +
        ", Производитель: " + manufacturer +
        ", Количество: " + std::to_string(quantity) +
        ", Цена за единицу: " + std::to_string(unit_price) +
        ", Общая цена: " + std::to_string(get_total_price());
    return return_string;
}


bool Product_On_Storage::set_storage_sector(const char p_storage_sector) {
    if (std::isalpha(p_storage_sector) && std::isupper(p_storage_sector)) {
        storage_place.sector = p_storage_sector;
        return true;
    }
    return false;
}
bool Product_On_Storage::set_storage_row(const int p_storage_row) {
    if (p_storage_row > 0) {
        storage_place.row = p_storage_row;
        return true;
    }
    return false;
}
bool Product_On_Storage::set_storage_shelf(const int p_storage_shelf) {
    if (p_storage_shelf > 0) {
        storage_place.shelf = p_storage_shelf;
        return true;
    }
    return false;
}
bool Product_On_Storage::set_storage_layer(const int p_storage_layer) {
    if (p_storage_layer > 0) {
        storage_place.layer = p_storage_layer;
        return true;
    }
    return false;
}
bool Product_On_Storage::set_arrival_date(const time_t p_arrival_date) {
    if (p_arrival_date > 0) {
        arrival_date = p_arrival_date;
        return true;
    }
    return false;
}

std::string Product_On_Storage::show() const {

    std::string return_string =
        Product::show() +
        ", Место на складе: " + storage_place.sector + '-' + std::to_string(storage_place.row) + '-' + std::to_string(storage_place.shelf) + '-' + std::to_string(storage_place.layer) +
        ", Дата прибытия: " + time_t_to_string(arrival_date);
    return return_string;
}