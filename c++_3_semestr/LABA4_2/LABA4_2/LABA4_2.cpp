// LABA4_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdexcept>
#include <windows.h>
#include <limits>

class LongInteger {
private:
    long value; // Значение целого числа

public:
    // Конструктор по умолчанию
    LongInteger() : value(0) {}

    // Конструктор с параметром
    LongInteger(long value) : value(value) {}

    // Оператор вычитания
    LongInteger operator-(const LongInteger& other) {
        return LongInteger(this->value - other.value);
    }

    // Дружественный оператор сложения
    friend LongInteger operator+(const LongInteger& lhs, const LongInteger& rhs);

    // Оператор присвоения
    LongInteger& operator=(const LongInteger& other) {
        if (this != &other) {
            this->value = other.value;
        }
        return *this;
    }

    // Операторы сравнения
    bool operator==(const LongInteger& other) {
        return this->value == other.value;
    }

    bool operator!=(const LongInteger& other) {
        return this->value != other.value;
    }

    bool operator<(const LongInteger& other) {
        return this->value < other.value;
    }

    bool operator>(const LongInteger& other) {
        return this->value > other.value;
    }

    bool operator<=(const LongInteger& other) {
        return this->value <= other.value;
    }

    bool operator>=(const LongInteger& other) {
        return this->value >= other.value;
    }

    // Метод для отображения значения
    void display() const {
        std::cout << "Значение: " << value << std::endl;
    }
};

LongInteger operator+(const LongInteger& lhs, const LongInteger& rhs) {
    return LongInteger(lhs.value + rhs.value);
}

bool isValidInput(long value) {
    return value >= -2147483648 && value <= 2147483647; // Проверка на допустимый диапазон для long
}

void clearInputBuffer() {
    std::cin.clear(); // сбрасываем флаг ошибки
    while (std::cin.get() != '\n'); // очищаем буфер ввода до конца строки
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("color F0");
    LongInteger num1, num2; // Объекты для целых чисел
    int choice;

    do {
        std::cout << "Выберите операцию:\n";
        std::cout << "1. Создать число (по умолчанию 0)\n";
        std::cout << "2. Создать число (ввести значение)\n";
        std::cout << "3. Вычесть число\n";
        std::cout << "4. Сложить числа\n";
        std::cout << "5. Сравнить числа\n";
        std::cout << "6. Отобразить число\n";
        std::cout << "7. Поменять знак\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор? ";

        std::cin >> choice;

        if (std::cin.fail()) { // Проверка на некорректный ввод выбора
            std::cout << "Ошибка: некорректный ввод. Пожалуйста, введите целое число." << std::endl;
            clearInputBuffer(); // Очищаем буфер ввода
            continue; // Возврат в начало цикла
        }

        switch (choice) {
        case 1: {
            num1 = LongInteger(); // Создание числа по умолчанию
            std::cout << "Число создано: ";
            num1.display();
            break;
        }
        case 2: {
            long value;
            std::cout << "Введите значение: ";
            std::cin >> value;

            if (std::cin.fail() || !isValidInput(value)) {
                std::cout << "Ошибка: введенное число слишком велико или некорректно." << std::endl;
                clearInputBuffer(); // Очищаем буфер ввода
                break; // Возврат в меню
            }

            num1 = LongInteger(value); // Создание числа с пользовательским значением
            std::cout << "Число создано: ";
            num1.display();
            break;
        }
        case 3: {
            long value;
            std::cout << "Введите значение для вычитания: ";
            std::cin >> value;

            if (std::cin.fail() || !isValidInput(value)) {
                std::cout << "Ошибка: введенное число слишком велико или некорректно." << std::endl;
                clearInputBuffer(); // Очищаем буфер ввода
                break; // Возврат в меню
            }

            num2 = LongInteger(value);
            LongInteger result = num1 - num2; // Вычитание
            std::cout << "Результат вычитания: ";
            result.display();
            break;
        }
        case 4: {
            long value;
            std::cout << "Введите значение для сложения: ";
            std::cin >> value;

            if (std::cin.fail() || !isValidInput(value)) {
                std::cout << "Ошибка: введенное число слишком велико или некорректно." << std::endl;
                clearInputBuffer(); // Очищаем буфер ввода
                break; // Возврат в меню
            }

            num2 = LongInteger(value);
            LongInteger result = num1 + num2; // Сложение
            std::cout << "Результат сложения: ";
            result.display();
            break;
        }
        case 5: {
            long value;
            std::cout << "Введите значение для сравнения: ";
            std::cin >> value;

            if (std::cin.fail() || !isValidInput(value)) {
                std::cout << "Ошибка: введенное число слишком велико или некорректно." << std::endl;
                clearInputBuffer(); // Очищаем буфер ввода
                break; // Возврат в меню
            }

            num2 = LongInteger(value);
            std::cout << "num1 " << (num1 == num2 ? "равно" : "не равно") << " num2 (==)" << std::endl;
            std::cout << "num1 " << (num1 < num2 ? "меньше" : "не меньше") << " num2 (<)" << std::endl;
            std::cout << "num1 " << (num1 > num2 ? "больше" : "не больше") << " num2 (>)" << std::endl;
            std::cout << "num1 " << (num1 >= num2 ? "не меньше" : "больше") << " num2 (>=)" << std::endl;
            std::cout << "num1 " << (num1 <= num2 ? "не больше" : "меньше") << " num2 (<=)" << std::endl;
            break;
        }
        case 6: {
            std::cout << "Текущее значение num1: ";
            num1.display();
            break;
        }
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
        }
    } while (choice != 0);

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
