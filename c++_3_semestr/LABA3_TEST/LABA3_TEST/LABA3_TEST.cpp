// LABA3_TEST.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// 
// 
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <windows.h>

class Date {
private:
    int* year;   // Указатель на целое число, представляющее год
    int* month;  // Указатель на целое число, представляющее месяц
    int* day;    // Указатель на целое число, представляющее день

    // Метод для валидации даты
    void validateDate(int year, int month, int day) {
        if (year < 1) throw std::invalid_argument("Год должен быть положительным.");
        if (year > 9999) throw std::invalid_argument("Год должен быть меньше 9999.");
        if (month < 1 || month > 12) throw std::invalid_argument("Месяц должен быть от 1 до 12.");
        if (day < 1 || day > daysInMonth(year, month)) throw std::invalid_argument("Недопустимый день для данного месяца.");
    }

    // Метод для получения количества дней в месяце
    int daysInMonth(int year, int month) {
        if (month == 2) {
            return (isLeapYear(year)) ? 29 : 28; // Февраль
        }
        return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31; // Апрель, Июнь, Сентябрь, Ноябрь
    }

    // Метод для проверки високосного года
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

public:
    // Конструктор без параметров, инициализирующий дату на 20 декабря 2005 года
    Date() {
        year = new int(2005);
        month = new int(12);
        day = new int(20);
    }

    // Конструктор с параметрами для установки даты
    Date(int year, int month, int day) {
        validateDate(year, month, day); // Валидация даты
        this->year = new int(year);
        this->month = new int(month);
        this->day = new int(day);
    }

    // Метод для установки года
    void setYear(int year) {
        validateDate(year, *month, *day);
        *(this->year) = year;
    }

    // Метод для установки месяца
    void setMonth(int month) {
        validateDate(*year, month, *day);
        *(this->month) = month;
    }

    // Метод для установки дня
    void setDay(int day) {
        validateDate(*year, *month, day);
        *(this->day) = day;
    }

    // Метод для получения года
    int getYear() { return *year; }

    // Метод для получения месяца
    int getMonth() { return *month; }

    // Метод для получения дня
    int getDay() { return *day; }

    // Метод для добавления дней
    void addDays(int days) {

        if (days >= 0) {
            // Добавление дней
            for (int i = 0; i < days; ++i) {
                (*day)++;
                if (*day > daysInMonth(*year, *month)) {
                    *day = 1;
                    (*month)++;
                    if (*month > 12) {
                        *month = 1;
                        (*year)++;
                    }
                }
            }
        }
        else {
            // Вычитание дней
            for (int i = 0; i < -days; ++i) {
                (*day)--;
                if (*day < 1) {
                    (*month)--;
                    if (*month < 1) {
                        *month = 12;
                        (*year)--;
                    }
                    *day = daysInMonth(*year, *month); // Устанавливаем день на последний день предыдущего месяца
                }
            }
        }
        if (*year < 1)
        {
            std::cout << "Изменить дату на заданное число дней невозможно, так как год выйдет неположительным. Дата останется прежней." << std::endl;
            addDays(-1 * days);
        }
    }

    // Метод для добавления месяцев
    void addMonths(int months) {
        *month += months;

        // Обработка переполнения для положительных месяцев
        while (*month > 12) {
            *month -= 12;
            (*year)++;
        }

        // Обработка переполнения для отрицательных месяцев
        while (*month < 1) {
            *month += 12;
            (*year)--;
        }
        if (*year < 1)
        {
            std::cout << "Изменить дату на заданное число месяцев невозможно, так как год выйдет неположительным. Дата останется прежней." << std::endl;
            addMonths(-1 * months);
        }
    }

    // Метод для добавления лет
    void addYears(int years) {

        *year += years;
        if (*day > daysInMonth(*year, *month)) {
            *day = daysInMonth(*year, *month);
        }
        if (*year < 1)
        {
            std::cout << "Изменить дату на заданное число лет невозможно, так как год выйдет неположительным. Дата останется прежней." << std::endl;
            addYears(-1 * years);
        }
    }

    // Метод для отображения даты в формате "дд.мм.гггг"
    void display() {
        std::cout << *day << "." << *month << "." << *year << std::endl;
    }

    // Деструктор для освобождения памяти
    ~Date() {
        delete year;
        delete month;
        delete day;
    }
};

    class Weekday : public Date {
    public:
        // Конструктор, который принимает дату и вызывает конструктор родительского класса
        Weekday(int year, int month, int day) : Date(year, month, day) {}

        // Метод, который возвращает день недели для заданной даты
        std::string getWeekday() {
            // Алгоритм Зеллера для вычисления дня недели
            int y = getYear();
            int m = getMonth();
            int d = getDay();

            // Если месяц январь или февраль, то рассматриваем его как 13 или 14 предыдущего года
            if (m < 3) {
                m += 12;
                y--;
            }

            int k = y % 100; // Последние две цифры года
            int j = y / 100; // Первые две цифры года

            // Формула Зеллера
            int h = (d + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) - (2 * j)) % 7;

            // Преобразуем результат в день недели
            // h = 0 - суббота, 1 - воскресенье, 2 - понедельник, ..., 6 - пятница
            switch (h) {
            case 0: return "Суббота";
            case 1: return "Воскресенье";
            case 2: return "Понедельник";
            case 3: return "Вторник";
            case 4: return "Среда";
            case 5: return "Четверг";
            case 6: return "Пятница";
            default: return ""; // Не должно быть
            }
        }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("color F0");  // консоль белого цвета

    Date* date = nullptr; // Указатель на объект даты
    int choice;

    do {
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "Выберите операцию:\n";
        std::cout << "1. Создать дату (по умолчанию 20.12.2005)\n";
        std::cout << "2. Создать дату (ввести год, месяц, день)\n";
        std::cout << "3. Установить год\n";
        std::cout << "4. Установить месяц\n";
        std::cout << "5. Установить день\n";
        std::cout << "6. Добавить дни\n";
        std::cout << "7. Добавить месяцы\n";
        std::cout << "8. Добавить годы\n";
        std::cout << "9. Отобразить дату\n";
        std::cout << "10. Получить день недели\n";
        //std::cout << "11. Вывести дату (через геттеры)\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор? ";

        std::cin >> choice;

        switch (choice) {
        case 1: {
            date = new Date(); // Создание даты по умолчанию
            std::cout << "Дата создана: ";
            date->display();
            break;
        }
        case 2: {
            try {
                int year, month, day;
                std::cout << "Введите год (1;9999) : ";
               // std::cin >> year;
                if (!(std:: cin >> year) || std::cin.get() != '\n') { // если ошибка ввода - ввели не целое число или в потоке ввода остались символы (кроме \n)
                    //std::cout << "Надо ввести целое число!\n" << std::endl; // вывести сообщение
                    std::cout << "Некорретный ввод!\n" << std::endl; // вывести сообщение
                    std::cin.clear(); // сбросить ошибку ввода, -> cin.fail() = 0 (cin.fail() = 1, т.к. в числовую переменную записываются символы)
                    while (std::cin.get() != '\n'); // очистить поток - считать все символы, пока не считается последний (т.е. \n)
                    break;
                }

                std::cout << "Введите месяц: ";
                //std::cin >> month;
                if (!(std::cin >> month) || std::cin.get() != '\n') { // если ошибка ввода - ввели не целое число или в потоке ввода остались символы (кроме \n)
                    //std::cout << "Надо ввести целое число!\n" << std::endl; // вывести сообщение
                    std::cout << "Некорретный ввод!\n" << std::endl; // вывести сообщение
                    std::cin.clear(); // сбросить ошибку ввода, -> cin.fail() = 0 (cin.fail() = 1, т.к. в числовую переменную записываются символы)
                    while (std::cin.get() != '\n'); // очистить поток - считать все символы, пока не считается последний (т.е. \n)
                    break;
                }

                std::cout << "Введите день: ";
                //std::cin >> day;
                if (!(std::cin >> day) || std::cin.get() != '\n') { // если ошибка ввода - ввели не целое число или в потоке ввода остались символы (кроме \n)
                    //std::cout << "Надо ввести целое число!\n" << std::endl; // вывести сообщение
                    std::cout << "Некорретный ввод!\n" << std::endl; // вывести сообщение
                    std::cin.clear(); // сбросить ошибку ввода, -> cin.fail() = 0 (cin.fail() = 1, т.к. в числовую переменную записываются символы)
                    while (std::cin.get() != '\n'); // очистить поток - считать все символы, пока не считается последний (т.е. \n)
                    break;
                }
                date = new Date(year, month, day); // Создание даты с пользовательскими параметрами
                std::cout << "Дата создана: ";
                date->display();
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Ошибка: " << e.what() << std::endl;
            }
            break;
        }
        case 3: {
            if (date) {
                int year;
                std::cout << "Введите год (1;9999) : ";
                //std::cin >> year;
                if (!(std::cin >> year) || std::cin.get() != '\n') { // если ошибка ввода - ввели не целое число или в потоке ввода остались символы (кроме \n)
                    //std::cout << "Надо ввести целое число!\n" << std::endl; // вывести сообщение
                    std::cout << "Некорретный ввод!\n" << std::endl; // вывести сообщение
                    std::cin.clear(); // сбросить ошибку ввода, -> cin.fail() = 0 (cin.fail() = 1, т.к. в числовую переменную записываются символы)
                    while (std::cin.get() != '\n'); // очистить поток - считать все символы, пока не считается последний (т.е. \n)
                    break;
                }
                try {
                    date->setYear(year);
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Ошибка: " << e.what() << std::endl;
                }
            }
            else {
                std::cout << "Сначала создайте дату!" << std::endl;
            }
            break;
        }
        case 4: {
            if (date) {
                int month;
                std::cout << "Введите месяц: ";
                //std::cin >> month;
                if (!(std::cin >> month) || std::cin.get() != '\n') { // если ошибка ввода - ввели не целое число или в потоке ввода остались символы (кроме \n)
                    //std::cout << "Надо ввести целое число!\n" << std::endl; // вывести сообщение
                    std::cout << "Некорретный ввод!\n" << std::endl; // вывести сообщение
                    std::cin.clear(); // сбросить ошибку ввода, -> cin.fail() = 0 (cin.fail() = 1, т.к. в числовую переменную записываются символы)
                    while (std::cin.get() != '\n'); // очистить поток - считать все символы, пока не считается последний (т.е. \n)
                    break;
                }
                try {
                    date->setMonth(month);
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Ошибка: " << e.what() << std::endl;
                }
            }
            else {
                std::cout << "Сначала создайте дату!" << std::endl;
            }
            break;
        }
        case 5: {
            if (date) {
                int day;
                std::cout << "Введите день: ";
                //std::cin >> day;
                if (!(std::cin >> day) || std::cin.get() != '\n') { // если ошибка ввода - ввели не целое число или в потоке ввода остались символы (кроме \n)
                    //std::cout << "Надо ввести целое число!\n" << std::endl; // вывести сообщение
                    std::cout << "Некорретный ввод!\n" << std::endl; // вывести сообщение
                    std::cin.clear(); // сбросить ошибку ввода, -> cin.fail() = 0 (cin.fail() = 1, т.к. в числовую переменную записываются символы)
                    while (std::cin.get() != '\n'); // очистить поток - считать все символы, пока не считается последний (т.е. \n)
                    break;
                }
                try {
                    date->setDay(day);
                }
                catch (const std::invalid_argument& e) {
                    std::cout << "Ошибка: " << e.what() << std::endl;
                }
            }
            else {
                std::cout << "Сначала создайте дату!" << std::endl;
            }
            break;
        }
        case 6: {
            if (date) {
                int daysToAdd;
                std::cout << "Введите количество дней для добавления: ";
                //std::cin >> daysToAdd;
                if (!(std::cin >> daysToAdd) || std::cin.get() != '\n') { // если ошибка ввода - ввели не целое число или в потоке ввода остались символы (кроме \n)
                    //std::cout << "Надо ввести целое число!\n" << std::endl; // вывести сообщение
                    std::cout << "Некорретный ввод!\n" << std::endl; // вывести сообщение
                    std::cin.clear(); // сбросить ошибку ввода, -> cin.fail() = 0 (cin.fail() = 1, т.к. в числовую переменную записываются символы)
                    while (std::cin.get() != '\n'); // очистить поток - считать все символы, пока не считается последний (т.е. \n)
                    break;
                }
                date->addDays(daysToAdd);
                std::cout << "Новая дата: ";
                date->display();
            }
            else {
                std::cout << "Сначала создайте дату!" << std::endl;
            }
            break;
        }
        case 7: {
            if (date) {
                int monthsToAdd;
                std::cout << "Введите количество месяцев для добавления: ";
                //std::cin >> monthsToAdd;
                if (!(std::cin >> monthsToAdd) || std::cin.get() != '\n') { // если ошибка ввода - ввели не целое число или в потоке ввода остались символы (кроме \n)
                    //std::cout << "Надо ввести целое число!\n" << std::endl; // вывести сообщение
                    std::cout << "Некорретный ввод!\n" << std::endl; // вывести сообщение
                    std::cin.clear(); // сбросить ошибку ввода, -> cin.fail() = 0 (cin.fail() = 1, т.к. в числовую переменную записываются символы)
                    while (std::cin.get() != '\n'); // очистить поток - считать все символы, пока не считается последний (т.е. \n)
                    break;
                }
                date->addMonths(monthsToAdd);
                std::cout << "Новая дата: ";
                date->display();
            }
            else {
                std::cout << "Сначала создайте дату!" << std::endl;
            }
            break;
        }
        case 8: {
            if (date) {
                int yearsToAdd;
                std::cout << "Введите количество лет для добавления: ";
                //std::cin >> yearsToAdd;
                if (!(std::cin >> yearsToAdd) || std::cin.get() != '\n') { // если ошибка ввода - ввели не целое число или в потоке ввода остались символы (кроме \n)
                    //std::cout << "Надо ввести целое число!\n" << std::endl; // вывести сообщение
                    std::cout << "Некорретный ввод!\n" << std::endl; // вывести сообщение
                    std::cin.clear(); // сбросить ошибку ввода, -> cin.fail() = 0 (cin.fail() = 1, т.к. в числовую переменную записываются символы)
                    while (std::cin.get() != '\n'); // очистить поток - считать все символы, пока не считается последний (т.е. \n)
                    break;
                }
                date->addYears(yearsToAdd);
                std::cout << "Новая дата: ";
                date->display();
            }
            else {
                std::cout << "Сначала создайте дату!" << std::endl;
            }
            break;
        }
        case 9: {
            if (date) {
                std::cout << "Текущая дата: ";
                date->display();
            }
            else {
                std::cout << "Сначала создайте дату!" << std::endl;
            }
            break;
        }
        case 10: {
            if (date) {
                Weekday weekdayDate(date->getYear(), date->getMonth(), date->getDay());
                std::cout << "День недели: " << weekdayDate.getWeekday() << std::endl;
            }
            else {
                std::cout << "Сначала создайте дату!" << std::endl;
            }
            break;
        }
        case 11: {
            if (date) {
                std::cout << date->getDay() <<"." << date->getMonth() << "." << date->getYear() << std::endl;
            }
            else {
                std::cout << "Сначала создайте дату!" << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    
    } while (choice != 0);

    delete date; // Освобождение памяти
    return 0;
}


// 
//#include <iostream>
//#include <stdexcept>
//#include <string>
//#include <cmath>
//#include <windows.h>
//
//class Date {
//private:
//    int* year;   // Указатель на целое число, представляющее год
//    int* month;  // Указатель на целое число, представляющее месяц
//    int* day;    // Указатель на целое число, представляющее день
//
//    // Метод для валидации даты
//    void validateDate(int year, int month, int day) {
//        if (year < 1) throw std::invalid_argument("Год должен быть положительным.");
//        if (month < 1 || month > 12) throw std::invalid_argument("Месяц должен быть от 1 до 12.");
//        if (day < 1 || day > daysInMonth(year, month)) throw std::invalid_argument("Недопустимый день для данного месяца.");
//    }
//
//    // Метод для получения количества дней в месяце
//    int daysInMonth(int year, int month) {
//        if (month == 2) {
//            return (isLeapYear(year)) ? 29 : 28; // Февраль
//        }
//        return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31; // Апрель, Июнь, Сентябрь, Ноябрь
//    }
//
//    // Метод для проверки високосного года
//    bool isLeapYear(int year) {
//        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//    }
//
//public:
//    // Конструктор без параметров, инициализирующий дату на 20 декабря 2005 года
//    Date() {
//        year = new int(2005);
//        month = new int(12);
//        day = new int(20);
//    }
//
//    // Конструктор с параметрами для установки даты
//    Date(int year, int month, int day) {
//        this->year = new int(year);
//        this->month = new int(month);
//        this->day = new int(day);
//        validateDate(year, month, day); // Валидация даты
//    }
//
//    // Метод для установки года
//    void setYear(int year) {
//        validateDate(year, *month, *day);
//        *(this->year) = year;
//    }
//
//    // Метод для установки месяца
//    void setMonth(int month) {
//        validateDate(*year, month, *day);
//        *(this->month) = month;
//    }
//
//    // Метод для установки дня
//    void setDay(int day) {
//        validateDate(*year, *month, day);
//        *(this->day) = day;
//    }
//
//    // Метод для получения года
//    int getYear() { return *year; }
//
//    // Метод для получения месяца
//    int getMonth() { return *month; }
//
//    // Метод для получения дня
//    int getDay() { return *day; }
//
//    // Метод для добавления дней
//    void addDays(int days) {
//        for (int i = 0; i < days; ++i) {
//            (*day)++;
//            if (*day > daysInMonth(*year, *month)) {
//                *day = 1;
//                (*month)++;
//                if (*month > 12) {
//                    *month = 1;
//                    (*year)++;
//                }
//            }
//        }
//    }
//
//    // Метод для добавления месяцев
//    void addMonths(int months) {
//        *month += months;
//        while (*month > 12) {
//            *month -= 12;
//            (*year)++;
//        }
//        if (*day > daysInMonth(*year, *month)) {
//            *day = daysInMonth(*year, *month);
//        }
//    }
//
//    // Метод для добавления лет
//    void addYears(int years) {
//        *year += years;
//        if (*day > daysInMonth(*year, *month)) {
//            *day = daysInMonth(*year, *month);
//        }
//    }
//
//    // Метод для отображения даты в формате "дд.мм.гггг"
//    void display() {
//        std::cout << *day << "." << *month << "." << *year << std::endl;
//    }
//
//    // Деструктор для освобождения памяти
//    ~Date() {
//        delete year;
//        delete month;
//        delete day;
//    }
//};
//class Weekday : public Date {
//public:
//    // Конструктор, который принимает дату и вызывает конструктор родительского класса
//    Weekday(int year, int month, int day) : Date(year, month, day) {}
//
//    // Метод, который возвращает день недели для заданной даты
//    std::string getWeekday() {
//        // Алгоритм Зеллера для вычисления дня недели
//        int y = getYear();
//        int m = getMonth();
//        int d = getDay();
//
//        // Если месяц январь или февраль, то рассматриваем его как 13 или 14 предыдущего года
//        if (m < 3) {
//            m += 12;
//            y--;
//        }
//
//        int k = y % 100; // Последние две цифры года
//        int j = y / 100; // Первые две цифры года
//
//        // Формула Зеллера
//        int h = (d + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) - (2 * j)) % 7;
//
//        // Преобразуем результат в день недели
//        // h = 0 - суббота, 1 - воскресенье, 2 - понедельник, ..., 6 - пятница
//        switch (h) {
//        case 0: return "Суббота";
//        case 1: return "Воскресенье";
//        case 2: return "Понедельник";
//        case 3: return "Вторник";
//        case 4: return "Среда";
//        case 5: return "Четверг";
//        case 6: return "Пятница";
//        default: return ""; // Не должно быть
//        }
//    }
//};
//
//int main() {
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//
//    Date* date = nullptr; // Указатель на объект даты
//    int choice;
//
//    do {
//        std::cout << "----------------------------------------------------------------" << std::endl;
//        std::cout << "Выберите операцию:\n";
//        std::cout << "1. Создать дату (по умолчанию 20.12.2005)\n";
//        std::cout << "2. Установить год\n";
//        std::cout << "3. Установить месяц\n";
//        std::cout << "4. Установить день\n";
//        std::cout << "5. Добавить дни\n";
//        std::cout << "6. Добавить месяцы\n";
//        std::cout << "7. Добавить годы\n";
//        std::cout << "8. Отобразить дату\n";
//        std::cout << "9. Получить день недели\n";
//        std::cout << "0. Выход\n";
//        std::cout << "Ваш выбор? ";
//
//        std::cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            date = new Date(); // Создание даты по умолчанию
//            std::cout << "Дата создана: ";
//            date->display();
//            break;
//        }
//        case 2: {
//            if (date) {
//                int year;
//                std::cout << "Введите год: ";
//                std::cin >> year;
//                date->setYear(year);
//            }
//            else {
//                std::cout << "Сначала создайте дату!" << std::endl;
//            }
//            break;
//        }
//        case 3: {
//            if (date) {
//                int month;
//                std::cout << "Введите месяц: ";
//                std::cin >> month;
//                date->setMonth(month);
//            }
//            else {
//                std::cout << "Сначала создайте дату!" << std::endl;
//            }
//            break;
//        }
//        case 4: {
//            if (date) {
//                int day;
//                std::cout << "Введите день: ";
//                std::cin >> day;
//                date->setDay(day);
//            }
//            else {
//                std::cout << "Сначала создайте дату!" << std::endl;
//            }
//            break;
//        }
//        case 5: {
//            if (date) {
//                int days;
//                std::cout << "Введите количество дней для добавления: ";
//                std::cin >> days;
//                date->addDays(days);
//            }
//            else {
//                std::cout << "Сначала создайте дату!" << std::endl;
//            }
//            break;
//        }
//        case 6: {
//            if (date) {
//                int months;
//                std::cout << "Введите количество месяцев для добавления: ";
//                std::cin >> months;
//                date->addMonths(months);
//            }
//            else {
//                std::cout << "Сначала создайте дату!" << std::endl;
//            }
//            break;
//        }
//        case 7: {
//            if (date) {
//                int years;
//                std::cout << "Введите количество лет для добавления: ";
//                std::cin >> years;
//                date->addYears(years);
//            }
//            else {
//                std::cout << "Сначала создайте дату!" << std::endl;
//            }
//            break;
//        }
//        case 8: {
//            if (date) {
//                std::cout << "Текущая дата: ";
//                date->display();
//            }
//            else {
//                std::cout << "Сначала создайте дату!" << std::endl;
//            }
//            break;
//        }
//        case 9: {
//            if (date) {
//                Weekday weekday(date->getYear(), date->getMonth(), date->getDay());
//                std::cout << "День недели: " << weekday.getWeekday() << std::endl;
//            }
//            else {
//                std::cout << "Сначала создайте дату!" << std::endl;
//            }
//            break;
//        }
//        case 0: {
//            std::cout << "Выход из программы." << std::endl;
//            break;
//        }
//        default: {
//            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
//            break;
//        }
//        }
//    } while (choice != 0);
//
//    delete date; // Освобождение памяти
//    return 0;
//}

//
//
//#include <iostream>
//#include <stdexcept>
//#include <string>
//#include <cmath>
//#include <windows.h>
//
//class Date {
//private:
//    int* year;   // Указатель на целое число, представляющее год
//    int* month;  // Указатель на целое число, представляющее месяц
//    int* day;    // Указатель на целое число, представляющее день
//
//    // Метод для валидации даты
//    void validateDate(int year, int month, int day) {
//        if (year < 1) throw std::invalid_argument("Год должен быть положительным.");
//        if (month < 1 || month > 12) throw std::invalid_argument("Месяц должен быть от 1 до 12.");
//        if (day < 1 || day > daysInMonth(year, month)) throw std::invalid_argument("Недопустимый день для данного месяца.");
//    }
//
//    // Метод для получения количества дней в месяце
//    int daysInMonth(int year, int month) {
//        if (month == 2) {
//            return (isLeapYear(year)) ? 29 : 28; // Февраль
//        }
//        return (month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31; // Апрель, Июнь, Сентябрь, Ноябрь
//    }
//
//    // Метод для проверки високосного года
//    bool isLeapYear(int year) {
//        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
//    }
//
//public:
//    // Конструктор без параметров, инициализирующий дату на 1 января 2000 года
//    Date() {
//        year = new int(2000);
//        month = new int(1);
//        day = new int(1);
//    }
//
//    // Конструктор с параметрами для установки даты
//    Date(int year, int month, int day) {
//        this->year = new int(year);
//        this->month = new int(month);
//        this->day = new int(day);
//        validateDate(year, month, day); // Валидация даты
//    }
//
//    // Метод для установки года
//    void setYear(int year) {
//        validateDate(year, *month, *day);
//        *(this->year) = year;
//    }
//
//    // Метод для установки месяца
//    void setMonth(int month) {
//        validateDate(*year, month, *day);
//        *(this->month) = month;
//    }
//
//    // Метод для установки дня
//    void setDay(int day) {
//        validateDate(*year, *month, day);
//        *(this->day) = day;
//    }
//
//    // Метод для получения года
//    int getYear() { return *year; }
//
//    // Метод для получения месяца
//    int getMonth() { return *month; }
//
//    // Метод для получения дня
//    int getDay() { return *day; }
//
//    // Метод для добавления дней
//    void addDays(int days) {
//        for (int i = 0; i < days; ++i) {
//            (*day)++;
//            if (*day > daysInMonth(*year, *month)) {
//                *day = 1;
//                (*month)++;
//                if (*month > 12) {
//                    *month = 1;
//                    (*year)++;
//                }
//            }
//        }
//    }
//
//    // Метод для добавления месяцев
//    void addMonths(int months) {
//        *month += months;
//        while (*month > 12) {
//            *month -= 12;
//            (*year)++;
//        }
//        if (*day > daysInMonth(*year, *month)) {
//            *day = daysInMonth(*year, *month);
//        }
//    }
//
//    // Метод для добавления лет
//    void addYears(int years) {
//        *year += years;
//        if (*day > daysInMonth(*year, *month)) {
//            *day = daysInMonth(*year, *month);
//        }
//    }
//
//    // Метод для отображения даты в формате "дд.мм.гггг"
//    void display() {
//        std::cout << *day << "." << *month << "." << *year << std::endl;
//    }
//
//    // Деструктор для освобождения памяти
//    ~Date() {
//        delete year;
//        delete month;
//        delete day;
//    }
//};
//
//class Weekday : public Date {
//public:
//    // Конструктор, который принимает дату и вызывает конструктор родительского класса
//    Weekday(int year, int month, int day) : Date(year, month, day) {}
//
//    // Метод, который возвращает день недели для заданной даты
//    std::string getWeekday() {
//        // Алгоритм Зеллера для вычисления дня недели
//        int y = getYear();
//        int m = getMonth();
//        int d = getDay();
//
//        // Если месяц январь или февраль, то рассматриваем его как 13 или 14 предыдущего года
//        if (m < 3) {
//            m += 12;
//            y--;
//        }
//
//        int k = y % 100; // Последние две цифры года
//        int j = y / 100; // Первые две цифры года
//
//        // Формула Зеллера
//        int h = (d + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) - (2 * j)) % 7;
//
//        // Преобразуем результат в день недели
//        // h = 0 - суббота, 1 - воскресенье, 2 - понедельник, ..., 6 - пятница
//        switch (h) {
//        case 0: return "Суббота";
//        case 1: return "Воскресенье";
//        case 2: return "Понедельник";
//        case 3: return "Вторник";
//        case 4: return "Среда";
//        case 5: return "Четверг";
//        case 6: return "Пятница";
//        default: return ""; // Не должно быть
//        }
//    }
//};
//
//int main() {
//
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//    /*int year, month, day;
//
//
//    std::cout << "Введите год: ";
//    std::cin >> year;
//    std::cout << "Введите месяц: ";
//    std::cin >> month;
//    std::cout << "Введите день: ";
//    std::cin >> day;
//
//    Weekday date(year, month, day);
//
//    std::cout << "Выберите операцию:\n";
//    std::cout << "1. Получить день недели\n";
//    std::cout << "2. Выход\n";
//
//    int choice;
//    std::cin >> choice;
//
//    switch (choice) {
//    case 1:
//        std::cout << "День недели: " << date.getWeekday() << std::endl;
//        break;
//    case 2:
//        std::cout << "Выход из программы." << std::endl;
//        break;
//    default:
//        std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
//    }*/
//
//
//    return 0;
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
