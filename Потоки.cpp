#include <iostream>
#include <windows.h>
#include <process.h>

// Пример функции, выполняемой в потоке
unsigned __stdcall ThreadFunc(void* param) {
    int* threadNumber = reinterpret_cast<int*>(param);
    std::cout << "Поток " << *threadNumber << " запущен" << std::endl;
    Sleep(3000); // Подождать 3 секунды
    std::cout << "Поток " << *threadNumber << " завершен" << std::endl;
    _endthreadex(0);
    return 0;
}

int main() {
    // Пример создания потока с макрокомандой _beginthreadex
    unsigned threadID;
    int threadNumber = 1;
    HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadFunc, &threadNumber, 0, &threadID);
    if (hThread == NULL) {
        std::cerr << "Ошибка при создании потока" << std::endl;
        return 1;
    }

    // Пример приостановки потока
    std::cout << "Приостановка потока..." << std::endl;
    SuspendThread(hThread);
    Sleep(2000); // Подождать 2 секунды
    std::cout << "Возобновление потока..." << std::endl;
    ResumeThread(hThread);

    // Пример завершения потока с использованием функции TerminateThread
    std::cout << "Завершение потока..." << std::endl;
    TerminateThread(hThread, 0);
    CloseHandle(hThread);

    return 0;
}
