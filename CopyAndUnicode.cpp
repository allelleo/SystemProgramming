#include <iostream>
#include <windows.h>
#include <vector>

// Функция для копирования файлов на стандартное устройство вывода
void CopyFilesToStdout(const std::vector<std::string>& fileNames) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdout == INVALID_HANDLE_VALUE) {
        std::cerr << "Ошибка при получении дескриптора стандартного устройства вывода." << std::endl;
        return;
    }

    for (const auto& fileName : fileNames) {
        HANDLE hFile = CreateFile(fileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == INVALID_HANDLE_VALUE) {
            std::cerr << "Не удалось открыть файл " << fileName << std::endl;
            continue;
        }

        DWORD bytesRead = 0;
        const DWORD bufferSize = 4096;
        CHAR buffer[bufferSize];

        while (ReadFile(hFile, buffer, bufferSize, &bytesRead, NULL) && bytesRead > 0) {
            DWORD bytesWritten;
            WriteFile(hStdout, buffer, bytesRead, &bytesWritten, NULL);
        }

        CloseHandle(hFile);
    }
}

// Функция для преобразования символов из ASCII в Unicode
void ConvertAsciiToUnicode(const std::string& asciiString) {
    std::wstring unicodeString;

    for (char c : asciiString) {
        unicodeString += static_cast<wchar_t>(c);
    }

    std::wcout << L"Преобразованная строка (Unicode): " << unicodeString << std::endl;
}

int main() {
    // Пример использования функции для копирования файлов на стандартное устройство вывода
    std::vector<std::string> filesToCopy = {"file1.txt", "file2.txt"};
    CopyFilesToStdout(filesToCopy);

    // Пример использования функции для преобразования символов из ASCII в Unicode
    std::string asciiString = "Hello, World!";
    ConvertAsciiToUnicode(asciiString);

    return 0;
}
