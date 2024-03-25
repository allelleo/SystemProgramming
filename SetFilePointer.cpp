#include <iostream>
#include <windows.h>

int main() {
    // Открываем файл
    HANDLE hFile = CreateFile("example.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return 1;
    }

    // Получаем текущую позицию указателя файла
    DWORD dwMoveMethod = FILE_BEGIN; // Начиная с начала файла
    LONG lDistanceToMove = 10; // Перемещение на 10 байт
    DWORD dwNewFilePointer = SetFilePointer(hFile, lDistanceToMove, NULL, dwMoveMethod);

    if (dwNewFilePointer == INVALID_SET_FILE_POINTER) {
        DWORD dwError = GetLastError();
        std::cerr << "Ошибка при перемещении указателя файла: " << dwError << std::endl;
        CloseHandle(hFile);
        return 1;
    }

    std::cout << "Указатель файла успешно перемещен на " << dwNewFilePointer << " байт" << std::endl;

    // Закрываем файл
    CloseHandle(hFile);

    return 0;
}
