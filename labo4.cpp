#include <iostream>
#include <string>
#include <windows.h> // Для SetConsoleOutputCP и SetConsoleCP
using namespace std;

struct Zodiak {
    string surnameName;   // Фамилия и имя
    string zodiakSign;    // Знак зодиака
    int birthDate[3];     // Дата рождения: [день, місяць, рік]
};

// Функция для сортировки массива по возрастанию года рождения
void sortByYear(Zodiak zodiacs[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (zodiacs[i].birthDate[2] > zodiacs[j].birthDate[2]) {  // Сравниваем года
                Zodiak temp = zodiacs[i];
                zodiacs[i] = zodiacs[j];
                zodiacs[j] = temp;
            }
        }
    }
}

// Функция для поиска информации о человеке по фамилии
void findPersonBySurname(Zodiak zodiacs[], int size, const string& surname) {
    bool found = false; // Флаг для отслеживания найденной записи
    for (int i = 0; i < size; i++) {
        // Проверка на наличие введенной строки в фамилии
        if (zodiacs[i].surnameName.find(surname) != string::npos) {
            cout << "Прізвище та ім’я: " << zodiacs[i].surnameName
                << ", Знак Зодіаку: " << zodiacs[i].zodiakSign
                << ", Дата народження: " << zodiacs[i].birthDate[0] << "."
                << zodiacs[i].birthDate[1] << "." << zodiacs[i].birthDate[2] << endl;
            found = true; // Запис знайдена
        }
    }
    if (!found) {
        cout << "Запис з прізвищем '" << surname << "' не знайдено.\n";
    }
}

int main() {
    // Установка кодировок для ввода и вывода кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 3;  // Количество записей
    Zodiak zodiacs[size];

    // Ввод данных
    for (int i = 0; i < size; i++) {
        cout << "Введіть дані для людини " << i + 1 << ":\n";
        cout << "Прізвище та ім’я: ";
        cin.ignore();  // Очищаем буфер перед вводом строки
        getline(cin, zodiacs[i].surnameName);
        cout << "Знак Зодіаку: ";
        getline(cin, zodiacs[i].zodiakSign);
        cout << "Дата народження (день, місяць, рік): ";
        cin >> zodiacs[i].birthDate[0] >> zodiacs[i].birthDate[1] >> zodiacs[i].birthDate[2];
        cout << endl;
    }

    // Сортировка по году рождения
    sortByYear(zodiacs, size);

    // Вывод отсортированного списка
    cout << "\nВідсортований список за роком народження:\n";
    for (int i = 0; i < size; i++) {
        cout << "Прізвище та ім’я: " << zodiacs[i].surnameName
            << ", Знак Зодіаку: " << zodiacs[i].zodiakSign
            << ", Дата народження: " << zodiacs[i].birthDate[0] << "."
            << zodiacs[i].birthDate[1] << "." << zodiacs[i].birthDate[2] << endl;
    }

    // Пошук особи за прізвищем
    string searchSurname;
    cout << "\nВведіть прізвище для пошуку: ";
    cin.ignore();
    getline(cin, searchSurname);
    findPersonBySurname(zodiacs, size, searchSurname);

    return 0;
}