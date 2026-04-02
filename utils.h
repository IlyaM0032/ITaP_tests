// utils.h
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#ifndef UTILS_H
#define UTILS_H
#include <list>
#include <memory>
#include <string>
#include <iostream>

class IShowable {
    public:
    virtual ~IShowable() = default;
    [[nodiscard]] virtual std::string show() const = 0;
};

template <typename T> void print_showables_list(const std::list<std::shared_ptr<T>>& list) {
    if (list.empty()) {
        std::cout << "Список пуст" << std::endl;
    } else {
        for (const std::shared_ptr<T>& item : list) {
            std::cout << item->show() << std::endl;
        }
    }
}
int read_int();
double read_double();
int read_natural();
char read_char();

#endif //UTILS_H
