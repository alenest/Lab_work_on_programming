// LABA4_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <stdexcept>

class Coordinates {
private:
    int x; // координата X
    int y; // координата Y

public:
    // Конструктор по умолчанию
    Coordinates() = default;

    // Конструктор с параметрами
    Coordinates(int x_, int y_) {
        setX(x_);
        setY(y_);
    }

    // Деструктор
    ~Coordinates() {
        // Нет динамической памяти для освобождения
    }

    // Геттеры
    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    // Сеттеры с обработкой исключений
    void setX(int x_) {
        if (x_ < -1000 || x_ > 1000) {
            throw std::invalid_argument("Координата X должна быть в диапазоне (-1000; 1000).");
        }
        x = x_;
    }

    void setY(int y_) {
        if (y_ < -1000 || y_ > 1000) {
            throw std::invalid_argument("Координата Y должна быть в диапазоне (-1000; 1000).");
        }
        y = y_;
    }

    // Метод для отображения координат
    void display() const {
        std::cout << "Координаты: (" << x << ", " << y << ")\n";
    }

    // Префиксный оператор ++ как функция-член
    Coordinates& operator++() {
        ++(x);
        ++(y);
        return *this;
    }

    // Постфиксный оператор ++
    Coordinates operator++(int) {
        Coordinates temp = *this; // сохраняем текущее состояние
        ++(x);
        ++(y);
        return temp; // возвращаем старое состояние
    }

    // Префиксный оператор -- как дружественная функция
    friend Coordinates& operator--(Coordinates& coord);

    // Постфиксный оператор -- как дружественная функция
    friend Coordinates operator--(Coordinates& coord, int);

    // Оператор - для изменения знака
    Coordinates operator-() const {
        return Coordinates(-(x), -(y));
    }
};

Coordinates& operator--(Coordinates& coord) {
    --(coord.x);
    --(coord.y);
    return coord;
}

Coordinates operator--(Coordinates& coord, int) {
    Coordinates temp = coord; // сохраняем текущее состояние
    --(coord.x);
    --(coord.y);
    return temp; // возвращаем старое состояние
}

void clearInputBuffer() {
    std::cin.clear(); // сбрасываем флаг ошибки
    while (std::cin.get() != '\n'); // очищаем буфер ввода до конца строки
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("color F0");

    int x, y;

    // Ввод координаты X с обработкой исключений
    while (true) {
        try {
            std::cout << "Введите координату X: ";
            std::cin >> x;
            if (std::cin.fail()) {
                throw std::invalid_argument("Некорректный ввод. Пожалуйста, введите целое число.");
            }
            clearInputBuffer(); // очищаем буфер ввода
            break; // выходим из цикла, если ввод успешен
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
            clearInputBuffer(); // очищаем буфер ввода
        }
    }

    // Ввод координаты Y с обработкой исключений
    while (true) {
        try {
            std::cout << "Введите координату Y: ";
            std::cin >> y;
            if (std::cin.fail()) {
                throw std::invalid_argument("Некорректный ввод. Пожалуйста, введите целое число.");
            }
            clearInputBuffer(); // очищаем буфер ввода
            break; // выходим из цикла, если ввод успешен
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Ошибка: " << e.what() << std::endl;
            clearInputBuffer(); // очищаем буфер ввода
        }
    }

    // Создаем объект с введенными координатами
    Coordinates* coord = nullptr;
    try {
        coord = new Coordinates(x, y);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "Исходные ";
    coord->display();

    // Префиксный инкремент
    ++(*coord);
    std::cout << "После префиксного инкремента ";
    coord->display();

    // Постфиксный инкремент
    Coordinates oldCoord = (*coord)++;
    std::cout << "После постфиксного инкремента (старое значение: ";
    oldCoord.display();
    std::cout << "Новое значение: ";
    coord->display();

    // Префиксный декремент
    --(*coord);
    std::cout << "После префиксного декремента ";
    coord->display();

    // Постфиксный декремент
    oldCoord = (*coord)--;
    std::cout << "После постфиксного декремента (старое значение: ";
    oldCoord.display();
    std::cout << "Новое значение: ";
    coord->display();

    // Изменение знака координат
    Coordinates negated = -(*coord);
    std::cout << "После изменения знака ";
    negated.display();

    delete coord; // Освобождение памяти
    return 0;
}






//#include <iostream>
//#include <windows.h>
//
//class Coordinates {
//private:
//    double x; // координата X
//    double y; // координата Y
//
//public:
//    // Конструктор по умолчанию
//    Coordinates() = default;
//
//    // конструктор с параметрами
//    Coordinates(double x_, double y_) 
//    {
//        this->x = x_;
//        this->y = y_;
//    }
//
//    //// Деструктор
//    //~Coordinates() {
//    //    delete x;
//    //    delete y;
//    //}
//
//    // Метод для отображения координат
//    void display() {
//        std::cout << "Координаты: (" << x << ", " << y << ")\n";
//    }
//
//    // Префиксный оператор ++ как функция-член
//    Coordinates& operator++() {
//        ++(x);
//        ++(y);
//        return *this;
//    }
//
//    // Постфиксный оператор ++
//    Coordinates operator++(int) {
//        //Coordinates temp = *this; // сохраняем текущее состояние
//        ++(x);
//        ++(y);
//        return *this; // возвращаем старое состояние
//    }
//
//    // Префиксный оператор -- как дружественная функция
//    friend Coordinates& operator--(Coordinates& coord);
//
//    // Постфиксный оператор -- как дружественная функция
//    friend Coordinates operator--(Coordinates& coord, int);
//
//    // Оператор - для изменения знака
//    Coordinates operator-() {
//        return Coordinates(-(x), -(y));
//    }
//};
//
//Coordinates& operator--(Coordinates& coord)
//{
//    --(coord.x);
//    --(coord.y);
//    return coord;
//}
//
//Coordinates operator--(Coordinates& coord, int)
//{
//    Coordinates temp = coord; // сохраняем текущее состояние
//    --(coord.x);
//    --(coord.y);
//    return temp; // возвращаем старое состояние
//}
//
//int main() {
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//    system("color F0");
//    Coordinates* coord = new Coordinates(5, 10); // Создаем объект с координатами (5, 10)
//
//    std::cout << "Исходные ";
//    coord->display();
//
//    ++(*coord); // Префиксный инкремент
//    std::cout << "После префиксного инкремента ";
//    coord->display();
//
//    (*coord)++; // Постфиксный инкремент
//    //coord->display();
//    std::cout << "После постфиксного инкремента ";
//    coord->display();
//
//    --(*coord); // Префиксный декремент (дружественная функция)
//    std::cout << "После префиксного декремента ";
//    coord->display();
//
//    (*coord)--; // Постфиксный декремент (дружественная функция)
//    //coord->display();
//    std::cout << "После постфиксного декремента ";
//    coord->display();
//
//    // Изменение знака координат
//    Coordinates negated = -(*coord); // Изменение знака
//    std::cout << "После изменения знака ";
//    negated.display();
//
//    delete coord; // Освобождение памяти
//    return 0;
//}

//// Постфиксный оператор ++
//Coordinates operator++(int) {
//    Coordinates temp = *this; // сохраняем текущее состояние
//    //++(*this);
//    std::cout << "Координаты: (" << *x << ", " << *y << ")\n";
//    ++(*x);
//    ++(*y);
//    std::cout << "Координаты: (" << *x << ", " << *y << ")\n";
//    return temp; // возвращаем старое состояние
//}

/*t_coordinates operator++ (int)
{
    t_coordinates temp = *this;
    ++* this;
    return temp;
};
*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
