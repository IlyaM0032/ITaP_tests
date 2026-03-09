// main.cpp
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#include "console_interface.h"
#ifdef _WIN32
#include <Windows.h>
#endif


int main() {
#ifdef _WIN32
    system("chcp 65001");
    system("cls");
#endif

    main_menu();

    return 0;
}