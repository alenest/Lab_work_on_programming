#include <iostream>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <algorithm>

using namespace std;

class ComplexException : public exception {
private:
    string message;

public:
    ComplexException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class SetException : public exception {
private:
    string message;

public:
    SetException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class Complex {
private:
    double Real;
    double Image;

public:
    Complex() : Real(0), Image(0) {}

    Complex(double RealPart, double ImagePart) {
        setRealPart(RealPart);
        setImagePart(ImagePart);
    }

    double getRealPart() const {
        return Real;
    }

    double getImagePart() const {
        return Image;
    }

    void setRealPart(double RealPart) {
        this->Real = RealPart;
    }

    void setImagePart(double ImagePart) {
        this->Image = ImagePart;
    }

    Complex operator+(const Complex& other) const {
        return Complex(this->Real + other.Real, this->Image + other.Image);
    }

    Complex operator-(const Complex& other) const {
        return Complex(this->Real - other.Real, this->Image - other.Image);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            this->Real * other.Real - this->Image * other.Image,
            this->Real * other.Image + this->Image * other.Real
        );
    }

    double Modulus() const {
        return sqrt(Real * Real + Image * Image);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.Real << (c.Image >= 0 ? " + " : " - ") << abs(c.Image) << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        double real, image;
        if (is >> real >> image) {
            c.setRealPart(real);
            c.setImagePart(image);
        }
        else if (is.peek() != istream::traits_type::eof()) {
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            throw SetException("Ошибка ввода. Пожалуйста, введите два числа (действительную и мнимую части).");
        }
        return is;
    }

    bool operator==(const Complex& other) const {
        return Real == other.Real && Image == other.Image;
    }
};

template <typename T>
class Set {
private:
    T* elements;
    int capacity;
    int size;

    void resize(int newCapacity) {
        T* newElements = new T[newCapacity];
        for (int i = 0; i < size; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }

public:
    Set() : capacity(10), size(0) {
        elements = new T[capacity];
    }

    Set(int initialCapacity) : capacity(initialCapacity), size(0) {
        if (capacity <= 0) {
            throw SetException("Вместимость множества должна быть положительной.");
        }
        elements = new T[capacity];
    }

    ~Set() {
        delete[] elements;
    }

    void add(const T& element) {
        if (contains(element)) {
            throw SetException("Элемент уже существует в множестве.");
        }
        if (size >= capacity) {
            resize(capacity * 2);
        }
        elements[size++] = element;
        cout << "Элемент добавлен." << endl << "Текущее множество: " << *this << endl;
    }

    void remove(const T& element) {
        if (!contains(element)) {
            throw SetException("Элемент не найден в множестве.");
        }
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element) {
                for (int j = i; j < size - 1; ++j) {
                    elements[j] = elements[j + 1];
                }
                size--;
                cout << "Элемент удален. Текущее множество: " << *this << endl;
                return;
            }
        }
    }

    bool contains(const T& element) const {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }

    Set<T> unionWith(const Set<T>& other) const {
        Set<T> result(size + other.size);
        for (int i = 0; i < size; ++i) {
            result.add(elements[i]);
        }
        for (int i = 0; i < other.size; ++i) {
            if (!contains(other.elements[i])) {
                result.add(other.elements[i]);
            }
        }
        cout << "Первое множество: " << *this << endl;
        cout << "Второе множество: " << other << endl;
        cout << "Объединение множеств: " << result << endl;
        return result;
    }

    Set<T> intersectionWith(const Set<T>& other) const {
        Set<T> result(min(size, other.size));
        for (int i = 0; i < size; ++i) {
            if (other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
        cout << "Первое множество: " << *this << endl;
        cout << "Второе множество: " << other << endl;
        cout << "Пересечение множеств: " << result << endl;
        return result;
    }

    friend ostream& operator<<(ostream& os, const Set<T>& set) {
        os << "{ ";
        for (int i = 0; i < set.size; ++i) {
            os << set.elements[i];
            if (i < set.size - 1) {
                os << ", ";
            }
        }
        os << " }";
        return os;
    }

    friend istream& operator>>(istream& is, Set<T>& set) {
        string line;
        getline(is, line);
        istringstream iss(line);
        T element;

        while (true) {
            try {
                if (iss >> element) {
                    set.add(element);
                }
                else {
                    iss.clear();
                    iss.ignore(numeric_limits<streamsize>::max(), ' ');
                    if (iss.eof()) break;
                }
            }
            catch (const SetException& e) {
                cerr << "Ошибка: " << e.what() << endl;
                continue;
            }
        }

        if (set.size <= 0) {
            cout << "Создано пустое множество." << endl;
        }
        else {
            cout << "Множество успешно создано: " << set << endl;
        }
        return is;
    }
};

template<typename T>
void runSetOperations() {
    Set<T> set;
    Set<T> otherSet;
    bool running = true;

    while (running) {
        cout << "\nВыберите операцию:\n";
        cout << "1. Добавить элемент в 1-ое множество\n";
        cout << "2. Ввести 1-ое множество целиком\n";
        cout << "3. Добавить элемент во 2-ое множество\n";
        cout << "4. Ввести 2-ое множество целиком\n";
        cout << "5. Удалить элемент из 1-го множества\n";
        cout << "6. Проверить вхождение элемента в 1-ое множество\n";
        cout << "7. Объединить множества\n";
        cout << "8. Найти пересечение множеств\n";
        cout << "9. Вывести 1-ое множество\n";
        cout << "10. Завершить программу\n";
        cout << "Введите номер операции: ";

        int choice;
        cin >> choice;
        cin.ignore();

        try {
            switch (choice) {
            case 1: {
                T element;
                cout << "Введите элемент: ";
                cin >> element;
                set.add(element);
                break;
            }
            case 2: { // Ввод первого множества целиком
                cout << "Введите элементы 1-го множества (через пробел): ";
                cin >> set;
                break;
            }
            case 3: {
                T element;
                cout << "Введите элемент: ";
                cin >> element;
                otherSet.add(element);
                break;
            }
            case 4: { // Ввод второго множества целиком
                cout << "Введите элементы 2-го множества (через пробел): ";
                cin >> otherSet;
                break;
            }
            case 5: {
                T element;
                cout << "Введите элемент для удаления: ";
                cin >> element;
                set.remove(element);
                break;
            }
            case 6: {
                T element;
                cout << "Введите элемент для проверки: ";
                cin >> element;
                if (set.contains(element)) {
                    cout << "Элемент найден в множестве.\n";
                }
                else {
                    cout << "Элемент не найден в множестве.\n";
                }
                break;
            }
            case 7: {
                Set<T> unionSet = set.unionWith(otherSet);
                break;
            }
            case 8: {
                Set<T> intersectionSet = set.intersectionWith(otherSet);
                break;
            }
            case 9: {
                cout << "Текущее множество: " << set << endl;
                break;
            }
            case 10: {
                running = false;
                break;
            }
            default: {
                cout << "Неверный выбор. Попробуйте снова.\n";
                break;
            }
            }
        }
        catch (const SetException& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }
        catch (const exception& e) {
            cerr << "Неизвестная ошибка: " << e.what() << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Выберите тип данных для множества:\n";
    cout << "1. int\n";
    cout << "2. float\n";
    cout << "3. double\n";
    cout << "4. char\n";
    cout << "5. Complex\n";
    cout << "Введите номер типа: ";

    int typeChoice;
    cin >> typeChoice;
    cin.ignore();

    switch (typeChoice) {
    case 1:
        runSetOperations<int>();
        break;
    case 2:
        runSetOperations<float>();
        break;
    case 3:
        runSetOperations<double>();
        break;
    case 4:
        runSetOperations<char>();
        break;
    case 5:
        runSetOperations<Complex>();
        break;
    default:
        cout << "Неверный выбор. Завершение программы.\n";
        break;
    }

    return 0;
}