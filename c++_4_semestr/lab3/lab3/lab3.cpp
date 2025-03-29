#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>

using namespace std;

// Исключение для множества
class SetException : public exception {
private:
    string message;

public:
    SetException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Шаблонный класс Множество
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
        return result;
    }

    Set<T> intersectionWith(const Set<T>& other) const {
        Set<T> result(min(size, other.size));
        for (int i = 0; i < size; ++i) {
            if (other.contains(elements[i])) {
                result.add(elements[i]);
            }
        }
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
};

// Класс Самолет
class Airplane {
private:
    string model;
    int seats;

public:
    Airplane(string model, int seats) : model(model), seats(seats) {}

    string getModel() const {
        return model;
    }

    int getSeats() const {
        return seats;
    }

    bool operator==(const Airplane& other) const {
        return model == other.model;
    }

    friend ostream& operator<<(ostream& os, const Airplane& airplane) {
        os << airplane.model << " (" << airplane.seats << " мест)";
        return os;
    }
};

// Класс Аэропорт
class Airport {
private:
    string name;
    Set<Airplane> airplanes;

public:
    Airport(string name) : name(name) {}

    void addAirplane(const Airplane& airplane) {
        airplanes.add(airplane);
    }

    string getName() const {
        return name;
    }

    const Set<Airplane>& getAirplanes() const {
        return airplanes;
    }

    int getTotalPassengers() const {
        int total = 0;
        for (int i = 0; i < airplanes.size; ++i) {
            total += airplanes.elements[i].getSeats();
        }
        return total;
    }

    friend ostream& operator<<(ostream& os, const Airport& airport) {
        os << "Аэропорт: " << airport.name << ", Самолеты: " << airport.airplanes;
        return os;
    }
};

// Класс-наследник для управления аэропортами
class AirportManager : public Set<Airport> {
public:
    // Вывести названия аэропортов, имеющих все марки самолетов
    void airportsWithAllPlanes(const Set<Airplane>& allPlanes) const {
        cout << "Аэропорты, имеющие все марки самолетов:\n";
        for (int i = 0; i < size; ++i) {
            if (allPlanes.intersectionWith(this->elements[i].getAirplanes()).size == allPlanes.size) {
                cout << this->elements[i].getName() << endl;
            }
        }
    }

    // Вывести названия самолетов, которых нет ни в одном аэропорту
    void planesNotInAnyAirport(const Set<Airplane>& allPlanes) const {
        Set<Airplane> unionOfAirplanes;
        for (int i = 0; i < size; ++i) {
            unionOfAirplanes = unionOfAirplanes.unionWith(this->elements[i].getAirplanes());
        }

        Set<Airplane> missingPlanes = allPlanes;
        for (int i = 0; i < unionOfAirplanes.size; ++i) {
            missingPlanes.remove(unionOfAirplanes.elements[i]);
        }

        cout << "Самолеты, которых нет ни в одном аэропорту:\n" << missingPlanes << endl;
    }

    // Вывести суммарное количество пассажиров для каждого аэропорта
    void printTotalPassengersPerAirport() const {
        cout << "Суммарное количество пассажиров для каждого аэропорта:\n";
        for (int i = 0; i < size; ++i) {
            cout << this->elements[i].getName() << ": " << this->elements[i].getTotalPassengers() << " пассажиров\n";
        }
    }
};

// Функция для чтения списка самолетов
Set<Airplane> readAirplanes() {
    Set<Airplane> airplanes;
    cout << "Введите список самолетов (модель и число мест, по одному на строку, пустая строка для завершения):" << endl;
    while (true) {
        string model;
        int seats;
        cout << "Модель: ";
        getline(cin, model);
        if (model.empty()) break;

        cout << "Число мест: ";
        cin >> seats;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        airplanes.add(Airplane(model, seats));
    }
    return airplanes;
}

// Функция для чтения списка аэропортов
AirportManager readAirports(const Set<Airplane>& allPlanes) {
    AirportManager manager;
    cout << "Введите список аэропортов (название, затем список самолетов, пустая строка для завершения):" << endl;
    while (true) {
        string name;
        cout << "Название аэропорта: ";
        getline(cin, name);
        if (name.empty()) break;

        Airport airport(name);
        cout << "Введите список самолетов для аэропорта " << name << ":" << endl;
        while (true) {
            string model;
            int seats;
            cout << "Модель: ";
            getline(cin, model);
            if (model.empty()) break;

            cout << "Число мест: ";
            cin >> seats;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            airport.addAirplane(Airplane(model, seats));
        }
        manager.add(airport);
    }
    return manager;
}

int main() {
    try {
        // Чтение всех возможных самолетов
        Set<Airplane> allPlanes = readAirplanes();

        // Чтение информации об аэропортах
        AirportManager manager = readAirports(allPlanes);

        // Решение задачи
        manager.airportsWithAllPlanes(allPlanes);
        manager.planesNotInAnyAirport(allPlanes);
        manager.printTotalPassengersPerAirport();
    }
    catch (const SetException& e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}