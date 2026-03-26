// utils.h
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#ifndef UTILS_H
#define UTILS_H
#include <list>
#include <memory>
#include <string>

class Ishowable {
    public:
    virtual ~Ishowable() = default;
    [[nodiscard]] virtual std::string show() const = 0;
};

void print_showables_list(std::list<std::shared_ptr<Ishowable>>& showables);

int read_int();
double read_double();
int read_natural();
char read_char();

#endif //UTILS_H
