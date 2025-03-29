// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include <iostream>
//#include <cmath>
//#include <limits>
//
//using namespace std;
//
//class Complex {
//private:
//    double Real;
//    double Image;
//
//public:
//    Complex() : Real(0), Image(0) {} // Конструктор по умолчанию
//
//    Complex(double RealPart, double ImagePart) {
//        setRealPart(RealPart);
//        setImagePart(ImagePart);
//    }
//
//    // Геттеры
//    double getRealPart() const {
//        return Real;
//    }
//
//    double getImagePart() const {
//        return Image;
//    }
//
//    // Сеттеры
//    void setRealPart(double RealPart) {
//        this->Real = RealPart;
//    }
//
//    void setImagePart(double ImagePart) {
//        this->Image = ImagePart;
//    }
//
//    // Оператор сложения
//    Complex operator+(const Complex& other) const {
//        return Complex(this->Real + other.Real, this->Image + other.Image);
//    }
//
//    // Оператор вычитания
//    Complex operator-(const Complex& other) const {
//        return Complex(this->Real - other.Real, this->Image - other.Image);
//    }
//
//    // Оператор умножения
//    Complex operator*(const Complex& other) const {
//        return Complex(
//            this->Real * other.Real - this->Image * other.Image,
//            this->Real * other.Image + this->Image * other.Real
//        );
//    }
//
//    // Модуль комплексного числа
//    double Modulus() const {
//        return sqrt(Real * Real + Image * Image);
//    }
//
//    // Перегрузка оператора вывода
//    friend ostream& operator<<(ostream& os, const Complex& c) {
//        os << c.Real << (c.Image >= 0 ? " + " : " - ") << abs(c.Image) << "i";
//        return os;
//    }
//
//    // Перегрузка оператора ввода
//    friend istream& operator>>(istream& is, Complex& c) {
//        double real, image;
//        cout << "Введите действительную часть: ";
//        if (!(is >> real)) {
//            throw runtime_error("Ошибка ввода действительной части.");
//        }
//        cout << "Введите мнимую часть: ";
//        if (!(is >> image)) {
//            throw runtime_error("Ошибка ввода мнимой части.");
//        }
//        c.setRealPart(real);
//        c.setImagePart(image);
//        return is;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    try {
//        Complex c1, c2;
//
//        cout << "Введите первое комплексное число:\n";
//        cin >> c1;
//
//        cout << "Введите второе комплексное число:\n";
//        cin >> c2;
//
//        cout << "Первое число: " << c1 << endl;
//        cout << "Второе число: " << c2 << endl;
//
//        Complex sum = c1 + c2;
//        Complex diff = c1 - c2;
//        Complex prod = c1 * c2;
//
//        cout << "Сумма: " << sum << endl;
//        cout << "Разность: " << diff << endl;
//        cout << "Произведение: " << prod << endl;
//
//        cout << "Модуль первого числа: " << c1.Modulus() << endl;
//        cout << "Модуль второго числа: " << c2.Modulus() << endl;
//
//    }
//    catch (const exception& e) {
//        cerr << "Ошибка: " << e.what() << endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//#include <cmath>
//#include <stdexcept>
//
//using namespace std;
//
//class Complex {
//private:
//    double Real;
//    double Image;
//
//public:
//    Complex() : Real(0), Image(0) {} // Конструктор по умолчанию
//
//    Complex(double RealPart, double ImagePart) {
//        setRealPart(RealPart);
//        setImagePart(ImagePart);
//    }
//
//    // Геттеры
//    double getRealPart() const {
//        return Real;
//    }
//
//    double getImagePart() const {
//        return Image;
//    }
//
//    // Сеттеры
//    void setRealPart(double RealPart) {
//        this->Real = RealPart;
//    }
//
//    void setImagePart(double ImagePart) {
//        this->Image = ImagePart;
//    }
//
//    // Оператор сложения
//    Complex operator+(const Complex& other) const {
//        return Complex(this->Real + other.Real, this->Image + other.Image);
//    }
//
//    // Оператор вычитания
//    Complex operator-(const Complex& other) const {
//        return Complex(this->Real - other.Real, this->Image - other.Image);
//    }
//
//    // Оператор умножения
//    Complex operator*(const Complex& other) const {
//        return Complex(
//            this->Real * other.Real - this->Image * other.Image,
//            this->Real * other.Image + this->Image * other.Real
//        );
//    }
//
//    // Модуль комплексного числа
//    double Modulus() const {
//        return sqrt(Real * Real + Image * Image);
//    }
//
//    // Перегрузка оператора вывода
//    friend ostream& operator<<(ostream& os, const Complex& c) {
//        os << c.Real << (c.Image >= 0 ? " + " : " - ") << abs(c.Image) << "i";
//        return os;
//    }
//
//    // Перегрузка оператора ввода
//    friend istream& operator>>(istream& is, Complex& c) {
//        double real, image;
//        while (true) {
//            cout << "Введите действительную часть: ";
//            if (is >> real) {
//                break;
//            }
//            else {
//                cout << "Ошибка ввода. Пожалуйста, введите число.\n";
//                is.clear(); // Сброс флага ошибки
//                is.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
//            }
//        }
//        while (true) {
//            cout << "Введите мнимую часть: ";
//            if (is >> image) {
//                break;
//            }
//            else {
//                cout << "Ошибка ввода. Пожалуйста, введите число.\n";
//                is.clear(); // Сброс флага ошибки
//                is.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
//            }
//        }
//        c.setRealPart(real);
//        c.setImagePart(image);
//        return is;
//    }
//};
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    try {
//        Complex c1, c2;
//
//        cout << "Введите первое комплексное число:\n";
//        cin >> c1;
//
//        cout << "Введите второе комплексное число:\n";
//        cin >> c2;
//
//        cout << "Первое число: " << c1 << endl;
//        cout << "Второе число: " << c2 << endl;
//
//        Complex sum = c1 + c2;
//        Complex diff = c1 - c2;
//        Complex prod = c1 * c2;
//
//        cout << "Сумма: " << sum << endl;
//        cout << "Разность: " << diff << endl;
//        cout << "Произведение: " << prod << endl;
//
//        cout << "Модуль первого числа: " << c1.Modulus() << endl;
//        cout << "Модуль второго числа: " << c2.Modulus() << endl;
//
//    }
//    catch (const exception& e) {
//        cerr << "Ошибка: " << e.what() << endl;
//    }
//
//    return 0;
//}

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>

using namespace std;

// Класс для обработки исключений
class ComplexException : public exception {
private:
    string message;

public:
    ComplexException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Complex {
private:
    double Real;
    double Image;

public:
    Complex() : Real(0), Image(0) {} // Конструктор по умолчанию

    Complex(double RealPart, double ImagePart) {
        setRealPart(RealPart);
        setImagePart(ImagePart);
    }

    // Геттеры
    double getRealPart() const {
        return Real;
    }

    double getImagePart() const {
        return Image;
    }

    // Сеттеры
    void setRealPart(double RealPart) {
        this->Real = RealPart;
    }

    void setImagePart(double ImagePart) {
        this->Image = ImagePart;
    }

    // Оператор сложения
    Complex operator+(const Complex& other) const {
        return Complex(this->Real + other.Real, this->Image + other.Image);
    }

    // Оператор вычитания
    Complex operator-(const Complex& other) const {
        return Complex(this->Real - other.Real, this->Image - other.Image);
    }

    // Оператор умножения
    Complex operator*(const Complex& other) const {
        return Complex(
            this->Real * other.Real - this->Image * other.Image,
            this->Real * other.Image + this->Image * other.Real
        );
    }

    // Модуль комплексного числа
    double Modulus() const {
        return sqrt(Real * Real + Image * Image);
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.Real << (c.Image >= 0 ? " + " : " - ") << abs(c.Image) << "i";
        return os;
    }

    // Перегрузка оператора ввода
    friend istream& operator>>(istream& is, Complex& c) {
        double real, image;
        while (true) {
            cout << "Введите действительную часть: ";
            if (is >> real) {
                break;
            }
            else {
                is.clear(); // Сброс флага ошибки
                is.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
                throw ComplexException("Ошибка ввода. Пожалуйста, введите число.");
            }
        }
        while (true) {
            cout << "Введите мнимую часть: ";
            if (is >> image) {
                break;
            }
            else {
                is.clear(); // Сброс флага ошибки
                is.ignore(numeric_limits<streamsize>::max(), '\n'); // Очистка буфера
                throw ComplexException("Ошибка ввода. Пожалуйста, введите число.");
            }
        }
        c.setRealPart(real);
        c.setImagePart(image);
        return is;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        Complex c1, c2;

        cout << "Введите первое комплексное число:\n";
        cin >> c1;

        cout << "Введите второе комплексное число:\n";
        cin >> c2;

        cout << "Первое число: " << c1 << endl;
        cout << "Второе число: " << c2 << endl;

        Complex sum = c1 + c2;
        Complex diff = c1 - c2;
        Complex prod = c1 * c2;

        cout << "Сумма: " << sum << endl;
        cout << "Разность: " << diff << endl;
        cout << "Произведение: " << prod << endl;

        cout << "Модуль первого числа: " << c1.Modulus() << endl;
        cout << "Модуль второго числа: " << c2.Modulus() << endl;

    }
    catch (const ComplexException& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Неизвестная ошибка: " << e.what() << endl;
    }

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
