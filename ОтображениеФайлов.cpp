#include <iostream>
#include <fstream>
#include <codecvt>

int main() {
    // Открываем файлы для чтения и записи
    std::ifstream input("input.txt");
    std::wofstream output("output.txt");

    // Проверяем, успешно ли открыли файлы
    if (!input.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения." << std::endl;
        return 1;
    }

    if (!output.is_open()) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return 1;
    }

    // Устанавливаем локаль для преобразования
    std::locale loc(std::locale(), new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>());

    // Устанавливаем локаль для ввода и вывода
    input.imbue(loc);
    output.imbue(loc);

    // Читаем ASCII-файл построчно и записываем в файл в кодировке Unicode
    std::string line;
    while (std::getline(input, line)) {
        output << std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>, wchar_t>{}.from_bytes(line) << std::endl;
    }

    // Закрываем файлы
    input.close();
    output.close();

    std::cout << "Преобразование завершено." << std::endl;

    return 0;
}
