// main.cpp
// Общий файл контрольных работ
// Студент группы 4503, Илья М, 2026

#include "utils.h"

#ifdef _MSC_VER
#include <windows.h>
#endif

int main() {
    #ifdef _MSC_VER
    SetConsoleOutputCP(CP_UTF8);
    #endif

    tests_menu();

    return 0;
}