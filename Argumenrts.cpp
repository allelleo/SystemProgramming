#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

// Функция для вывода названия программы и списка аргументов
void PrintProgramInfo(int argc, char* argv[]) {
    std::cout << "Название программы: " << argv[0] << std::endl;
    std::cout << "Список аргументов:" << std::endl;
    for (int i = 1; i < argc; ++i) {
        std::cout << "Аргумент " << i << ": " << argv[i] << std::endl;
    }
}

// Функция для установки стандартного устройства вывода согласно опции -s
void SetStdoutErrorHandler(bool silent) {
    if (silent) {
        HANDLE hNull = CreateFile("NUL", GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        SetStdHandle(STD_OUTPUT_HANDLE, hNull);
    }
}

int main(int argc, char* argv[]) {
    // Проверяем наличие опции -s
    bool silentMode = false;
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-s") {
            silentMode = true;
            break;
        }
    }

    // Устанавливаем стандартное устройство вывода в соответствии с опцией -s
    SetStdoutErrorHandler(silentMode);

    // Выводим название программы и список аргументов
    PrintProgramInfo(argc, argv);

    return 0;
}
