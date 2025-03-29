// laba5_23.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <stdexcept>
#include <windows.h>

using namespace std;

// Впереди объявление классов
class Region; // Предварительное объявление класса Region
class Megapolis; // Предварительное объявление класса Megapolis

// Функция для проверки наличия цифр в строке
bool hasDigit(const string& str) {
    for (char ch : str) {
        if (isdigit(ch)) return true;
    }
    return false;
}

// Функция для проверки корректности ввода названия
string checkName() {
    string input;
    while (true) {
        cout << "Введите название: ";
        getline(cin, input);
        if (input.empty() || input.length() > 40 || hasDigit(input)) {
            cout << "Некорректный ввод! Пожалуйста, попробуйте снова: ";
        }
        else {
            return input;
        }
    }
}

// Функция для проверки корректности ввода населения
int checkPopulation() {
    int population;
    while (true) {
        cout << "Введите население: ";
        cin >> population;

        if (cin.fail() || population < 0) {
            cout << "Некорректный ввод! Пожалуйста, введите положительное число." << endl;
            cin.clear(); // Сбросить состояние потока
            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
        }
        else {
            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
            return population;
        }
    }
}

// Функция для проверки корректности ввода номера региона
int checkRegionNumber() {
    int regionNumber;
    while (true) {
        cout << "Введите номер региона (от 1 до 999): ";
        cin >> regionNumber;

        if (cin.fail() || regionNumber < 1 || regionNumber > 999) {
            cout << "Некорректный ввод! Пожалуйста, введите целое число от 1 до 999." << endl;
            cin.clear(); // Сбросить состояние потока
            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
        }
        else {
            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
            return regionNumber;
        }
    }
}

char checkChoice() {
    string input;
    while (true) {
        getline(cin, input);
        if (input.length() != 1 || !isalpha(input[0])) {
            cout << "Некорректный ввод! Пожалуйста, введите одну букву: ";
        }
        else {
            return toupper(input[0]);
        }
    }
}



// Абстрактный виртуальный базовый класс
class GeographicalEntity {
public:
    virtual void display() const = 0; // Чисто виртуальный метод
    virtual ~GeographicalEntity() {}
};

// Класс City, наследующий GeographicalEntity
class City : virtual public GeographicalEntity {
private:
    string CityName;
    int CityPopulation;
public:
    City(const string& CityName, int CityPopulation) {
        setCityName(CityName);
        setCityPopulation(CityPopulation);
    }

    // Геттеры
    string getCityName() const {
        return CityName;
    }

    int getCityPopulation() const {
        return CityPopulation;
    }

    // Сеттеры
    void setCityName(const string& CityName) {
        if (CityName.empty()) {
            throw runtime_error("Название города не может быть пустым.");
        }
        this->CityName = CityName;
    }

    void setCityPopulation(int CityPopulation) {
        if (CityPopulation < 0) {
            throw runtime_error("Население не может быть отрицательным.");
        }
        this->CityPopulation = CityPopulation;
    }

    void display() const override {
        cout << "Город: " << CityName << ", Население: " << CityPopulation << endl;
    }

    friend void displayinformation(const City& city, const Region& region, const Megapolis& megapolis);
};

// Класс Region, наследующий GeographicalEntity
class Region : virtual public GeographicalEntity {
private:
    string RegionName;
    int RegionNumber;
public:
    Region(const string& RegionName, int RegionNumber) {
        setRegionName(RegionName);
        setRegionNumber(RegionNumber);
    }

    // Геттеры
    string getRegionName() const {
        return RegionName;
    }

    int getRegionNumber() const {
        return RegionNumber;
    }

    // Сеттеры
    void setRegionName(const string& RegionName) {
        if (RegionName.empty()) {
            throw runtime_error("Название региона не может быть пустым.");
        }
        this->RegionName = RegionName;
    }

    void setRegionNumber(int RegionNumber) {
        if (RegionNumber < 1 || RegionNumber > 999) {
            throw runtime_error("Номер региона должен быть от 1 до 999.");
        }
        this->RegionNumber = RegionNumber;
    }

    void display() const override {
        cout << "Регион: " << RegionName << ", Номер региона: " << RegionNumber << endl;
    }

    friend void displayinformation(const City& city, const Region& region, const Megapolis& megapolis);
};

// Класс Megapolis, наследующий City и Region
class Megapolis : public City, public Region {
private:
    int area; // Площадь мегаполиса
public:
    Megapolis(const string& cityName, int population, const string& regionName, int regionNumber, int area)
        : City(cityName, population), Region(regionName, regionNumber), area(area) {
        if (area < 0) {
            throw runtime_error("Площадь не может быть отрицательной.");
        }
    }

    // Геттеры
    int getArea() const {
        return area;
    }

    // Сеттер
    void setArea(int area) {
        if (area < 0) {
            throw runtime_error("Площадь не может быть отрицательной.");
        }
        this->area = area;
    }

    void display() const override {
        City::display();
        Region::display();
        cout << "Площадь мегаполиса: " << area << " кв. км" << endl;
    }
    friend void displayinformation(const City& city, const Region& region, const Megapolis& megapolis);
};

// дружественная функция для вывода информации о географических объектах
void displayinformation(const City& city, const Region& region, const Megapolis& megapolis) {
    cout << "Город:" << endl;
    cout << "Название Города: " << city.CityName << endl;
    cout << "Население Города: " << city.CityPopulation << endl;
    cout << "Регион:" << endl;
    cout << "Название Региона: " << region.RegionName << endl;
    cout << "Номер Региона: " << region.RegionNumber << endl;
    cout << "Мегаполис" << endl;
    cout << "Название Мегаполиса: " << megapolis.CityName << endl;
    cout << "Население Мегаполиса: " << megapolis.CityPopulation << endl;
    cout << "Название Региона Мегаполиса: " << megapolis.RegionName << endl;
    cout << "Номер Региона Мегаполиса: " << megapolis.RegionNumber << endl;
    cout << "Площадь Мегаполиса: " << megapolis.area << endl;

}

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("color F0");

    char choice;
    string cityName, regionName;
    int population, regionNumber, area;

    City myCity("Брянск", 400000);
    Region myRegion("Брянская область", 32);
    Megapolis myMegapolis("Москва", 10, "г.Москва", 777, 2561);

    do {
        cout << "\nA - создать город\n"
            << "B - создать регион\n"
            << "C - создать мегаполис\n"
            << "D - показать информацию\n"
            << "E - выход\n"
            << "Введите ваш выбор: ";
        choice = checkChoice();
        //cin >> choice;
        //cin.ignore(); // Игнорировать оставшиеся символы в строке

        try {
            switch (choice) {
            case 'A':
                cout << "=============================" << endl;
                cityName = checkName();
                population = checkPopulation();
                myCity.setCityName(cityName);
                myCity.setCityPopulation(population);
                cout << "Город создан." << endl;
                cout << "=============================" << endl;
                break;

            case 'B':
                cout << "=============================" << endl;
                regionName = checkName();
                regionNumber = checkRegionNumber();
                myRegion.setRegionName(regionName);
                myRegion.setRegionNumber(regionNumber);
                cout << "Регион создан." << endl;
                cout << "=============================" << endl;
                break;

            case 'C':
                cout << "=============================" << endl;
                cityName = checkName();
                population = checkPopulation();
                cout << "(для региона) ";
                regionName = checkName();
                regionNumber = checkRegionNumber();
                cout << "Введите площадь мегаполиса: ";
                cin >> area;
                myMegapolis.setRegionName(regionName);
                myMegapolis.setRegionNumber(regionNumber);
                myMegapolis.setArea(area);
                myMegapolis.setCityName(cityName);
                myMegapolis.setCityPopulation(population);
                cout << "Мегаполис создан." << endl;
                cout << "=============================" << endl;
                break;

            case 'D':
                // Здесь можно добавить код для отображения информации о созданных объектах
                cout << "Информация о географических объектах:" << endl;
                displayinformation(myCity, myRegion, myMegapolis);
                // Например, myCity.display(); и т.д.
                cout << "=============================" << endl;
                break;

            case 'E':
                return 0;

            default:
                cout << "Некорректный ввод! Пожалуйста, попробуйте снова." << endl;
            }
        }
        catch (const exception& e) {
            cout << "Произошла ошибка: " << e.what() << endl;
        }
    } while (true);

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
