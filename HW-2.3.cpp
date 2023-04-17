#include <Windows.h>
#include "Header.h"
using std::cin;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    cout << "Введите количество записей: ";
    cin >> size;
    cin.ignore();
    Worker* workersList = new Worker[size];
    cout << "Введите информацию об альбомах\n";
    for (int i = 0; i < size; ++i)
    {
        string buffer;
        int intBuffer;
        cout << "Запись №" << i + 1 << "\n";
        cout << "Фамилия: ";
        cin.ignore();
        getline(cin, buffer);
        workersList[i].surname = buffer;

        cout << "Должность: ";
        getline(cin, buffer);
        workersList[i].position = buffer;

        cout << "Дата подписания контракта (ДД ММ ГГГГ): ";
        getline(cin, buffer);
        vector<int> bufferVector = parseDateString(buffer);
        workersList[i].contractSignDate.day = bufferVector[0];
        workersList[i].contractSignDate.month = bufferVector[1];
        workersList[i].contractSignDate.year = bufferVector[2];

        cout << "Срок действия контракта (количество дней): ";
        cin >> intBuffer;
        workersList[i].contractDuration = intBuffer;

        cout << "Оклад: ";
        cin >> intBuffer;
        workersList[i].salary = intBuffer;
    }

    cout << "\nСведения о работниках, срок действия контракта которых истекает в течении 5 дней:\n";
    for (int i = 0; i < size; ++i)
    {
        printIf(workersList[i]);
        cout << "=========\n";
    }
        

    delete[] workersList;
}


