#include <iostream>
#include <windows.h>
#include <string>

void CreateAndDeleteFile() {
    std::string fileName = "test.txt";

    // Создание файла
    HANDLE hFile = CreateFile(fileName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Ошибка при создании файла" << std::endl;
        return;
    }
    std::cout << "Файл создан: " << fileName << std::endl;

    // Закрытие файла
    CloseHandle(hFile);

    // Удаление файла
    if (!DeleteFile(fileName.c_str())) {
        std::cerr << "Ошибка при удалении файла" << std::endl;
    } else {
        std::cout << "Файл удален: " << fileName << std::endl;
    }
}

void CreateRenameAndDeleteDirectory() {
    std::string dirName = "test_directory";
    std::string newDirName = "renamed_directory";

    // Создание папки
    if (!CreateDirectory(dirName.c_str(), NULL)) {
        std::cerr << "Ошибка при создании папки" << std::endl;
        return;
    }
    std::cout << "Папка создана: " << dirName << std::endl;

    // Переименование папки
    if (!MoveFile(dirName.c_str(), newDirName.c_str())) {
        std::cerr << "Ошибка при переименовании папки" << std::endl;
        return;
    }
    std::cout << "Папка переименована в: " << newDirName << std::endl;

    // Удаление папки
    if (!RemoveDirectory(newDirName.c_str())) {
        std::cerr << "Ошибка при удалении папки" << std::endl;
    } else {
        std::cout << "Папка удалена: " << newDirName << std::endl;
    }
}

void MoveFileToDirectory() {
    std::string fileName = "test.txt";
    std::string dirName = "test_directory";

    // Создание файла
    HANDLE hFile = CreateFile(fileName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Ошибка при создании файла" << std::endl;
        return;
    }
    std::cout << "Файл создан: " << fileName << std::endl;

    // Закрытие файла
    CloseHandle(hFile);

    // Создание папки
    if (!CreateDirectory(dirName.c_str(), NULL)) {
        std::cerr << "Ошибка при создании папки" << std::endl;
        return;
    }
    std::cout << "Папка создана: " << dirName << std::endl;

    // Перемещение файла в папку
    std::string newFilePath = dirName + "\\" + fileName;
    if (!MoveFile(fileName.c_str(), newFilePath.c_str())) {
        std::cerr << "Ошибка при перемещении файла" << std::endl;
        return;
    }
    std::cout << "Файл перемещен в папку: " << newFilePath << std::endl;

    // Удаление файла
    if (!DeleteFile(newFilePath.c_str())) {
        std::cerr << "Ошибка при удалении файла" << std::endl;
    } else {
        std::cout << "Файл удален: " << newFilePath << std::endl;
    }

    // Удаление папки
    if (!RemoveDirectory(dirName.c_str())) {
        std::cerr << "Ошибка при удалении папки" << std::endl;
    } else {
        std::cout << "Папка удалена: " << dirName << std::endl;
    }
}

void GetCurrentDirectory() {
    char buffer[MAX_PATH];
    if (GetCurrentDirectory(MAX_PATH, buffer) == 0) {
        std::cerr << "Ошибка при получении текущей папки" << std::endl;
        return;
    }
    std::cout << "Текущая папка: " << buffer << std::endl;
}

int main() {
    CreateAndDeleteFile();
    CreateRenameAndDeleteDirectory();
    MoveFileToDirectory();
    GetCurrentDirectory();
    return 0;
}
