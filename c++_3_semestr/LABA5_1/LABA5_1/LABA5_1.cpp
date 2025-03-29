// LABA5_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Базовый класс
class Place {
private:
    string Country; // Название страны
public:
    Place(const string& country) : Country(country) {}

    virtual void display() const {
        cout << "Страна: " << Country << endl;
    }

    virtual ~Place() {}

    // Геттер и сеттер для поля Country
    string getCountry() const {
        return Country;
    }

    void setCountry(const string& country) {
        if (country.empty()) {
            throw runtime_error("Название страны не может быть пустым.");
        }
        Country = country;
    }
};

// Класс City, наследующий Place
class City : public Place {
private:
    string CityName;
    int CityPopulation;
public:
    City(const string& country, const string& cityName, int cityPopulation)
        : Place(country), CityName(cityName), CityPopulation(cityPopulation) {}

    void setCityName(const string& cityName) {
        if (cityName.empty()) {
            throw runtime_error("Название города не может быть пустым.");
        }
        this->CityName = cityName;
    }

    void setCityPopulation(int cityPopulation) {
        if (cityPopulation < 0) {
            throw runtime_error("Население не может быть отрицательным.");
        }
        this->CityPopulation = cityPopulation;
    }

    // Геттеры
    string getCityName() const {
        return CityName;
    }

    int getCityPopulation() const {
        return CityPopulation;
    }

    void display() const override {
        Place::display(); // Выводим страну
        cout << "Город: " << CityName << ", Население: " << CityPopulation << endl;
    }
};

// Класс Region, наследующий Place
class Region : public Place {
private:
    string RegionName;
    int RegionNumber;
public:
    Region(const string& country, const string& regionName, int regionNumber)
        : Place(country), RegionName(regionName), RegionNumber(regionNumber) {}

    void setRegionName(const string& regionName) {
        if (regionName.empty()) {
            throw runtime_error("Название региона не может быть пустым.");
        }
        this->RegionName = regionName;
    }

    void setRegionNumber(int regionNumber) {
        if (regionNumber < 1 || regionNumber > 999) {
            throw runtime_error("Номер региона должен быть от 1 до 999.");
        }
        this->RegionNumber = regionNumber;
    }

    // Геттеры
    string getRegionName() const {
        return RegionName;
    }

    int getRegionNumber() const {
        return RegionNumber;
    }

    void display() const override {
        Place::display(); // Выводим страну
        cout << "Регион: " << RegionName << ", Номер региона: " << RegionNumber << endl;
    }
};

// Класс Megapolis, наследующий City и Region
class Megapolis : public City, public Region {
private:
    int area; // Площадь мегаполиса
public:
    Megapolis(const string& country, const string& cityName, int population,
        const string& regionName, int regionNumber, int area)
        : City(country, cityName, population), Region(country, regionName, regionNumber), area(area) {
        if (area < 0) {
            throw runtime_error("Площадь не может быть отрицательной.");
        }
    }

    void setArea(int area) {
        if (area < 0) {
            throw runtime_error("Площадь не может быть отрицательной.");
        }
        this->area = area;
    }

    // Геттер для площади
    int getArea() const {
        return area;
    }

    void display() const override {
        City::display(); // Выводим данные о городе
        Region::display(); // Выводим данные о регионе
        cout << "Площадь мегаполиса: " << area << " кв. км" << endl;
    }
};

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");
    system("color F0");
    
    Place myPlace("Россия");
    
    City myCity("Россия", "Брянск", 400000);
    
    Region myRegion("Россия", "Брянская область", 32);
    
    Megapolis myMegapolis("Россия", "Москва", 10000000, "г.Москва", 777, 2561);

    cout << "Информация о географических объектах:" << endl;
    cout << endl << "===класс Place===" << endl;
    myPlace.display();
    cout << endl << "===класс City===" << endl;
    myCity.display();
    cout << endl << "===класс Region===" << endl;
    myRegion.display();
    cout << endl << "===класс Megapolis===" << endl;
    myMegapolis.display();

    return 0;
}

//#include <iostream>
//#include <string>
//#include <stdexcept>
//#include <windows.h>
//
//using namespace std;
//
//// Впереди объявление классов
//class Region; // Предварительное объявление класса Region
//class Megapolis; // Предварительное объявление класса Megapolis
//
//// Функция для проверки наличия цифр в строке
//bool hasDigit(const string& str) {
//    for (char ch : str) {
//        if (isdigit(ch)) return true;
//    }
//    return false;
//}
//
//// Функция для проверки корректности ввода названия
//string checkName() {
//    string input;
//    while (true) {
//        cout << "Введите название: ";
//        getline(cin, input);
//        if (input.empty() || input.length() > 40 || hasDigit(input)) {
//            cout << "Некорректный ввод! Пожалуйста, попробуйте снова: ";
//        }
//        else {
//            return input;
//        }
//    }
//}
//
//// Функция для проверки корректности ввода населения
//int checkPopulation() {
//    int population;
//    while (true) {
//        cout << "Введите население: ";
//        cin >> population;
//
//        if (cin.fail() || population < 0) {
//            cout << "Некорректный ввод! Пожалуйста, введите положительное число." << endl;
//            cin.clear(); // Сбросить состояние потока
//            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
//        }
//        else {
//            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
//            return population;
//        }
//    }
//}
//
//// Функция для проверки корректности ввода номера региона
//int checkRegionNumber() {
//    int regionNumber;
//    while (true) {
//        cout << "Введите номер региона (от 1 до 999): ";
//        cin >> regionNumber;
//
//        if (cin.fail() || regionNumber < 1 || regionNumber > 999) {
//            cout << "Некорректный ввод! Пожалуйста, введите целое число от 1 до 999." << endl;
//            cin.clear(); // Сбросить состояние потока
//            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
//        }
//        else {
//            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
//            return regionNumber;
//        }
//    }
//}
//
//char checkChoice() {
//    string input;
//    while (true) {
//        getline(cin, input);
//        if (input.length() != 1 || !isalpha(input[0])) {
//            cout << "Некорректный ввод! Пожалуйста, введите одну букву: ";
//        }
//        else {
//            return toupper(input[0]);
//        }
//    }
//}
//
//
//
//// Абстрактный виртуальный базовый класс
//class GeographicalEntity {
//public:
//    virtual void display() const = 0; // Чисто виртуальный метод
//    virtual ~GeographicalEntity() {}
//};
//
//// Класс City, наследующий GeographicalEntity
//class City : virtual public GeographicalEntity {
//private:
//    string CityName;
//    int CityPopulation;
//public:
//    City(const string& CityName, int CityPopulation) {
//        setCityName(CityName);
//        setCityPopulation(CityPopulation);
//    }
//
//    // Геттеры
//    string getCityName() const {
//        return CityName;
//    }
//
//    int getCityPopulation() const {
//        return CityPopulation;
//    }
//
//    // Сеттеры
//    void setCityName(const string& CityName) {
//        if (CityName.empty()) {
//            throw runtime_error("Название города не может быть пустым.");
//        }
//        this->CityName = CityName;
//    }
//
//    void setCityPopulation(int CityPopulation) {
//        if (CityPopulation < 0) {
//            throw runtime_error("Население не может быть отрицательным.");
//        }
//        this->CityPopulation = CityPopulation;
//    }
//
//    void display() const override {
//        cout << "Город: " << CityName << ", Население: " << CityPopulation << endl;
//    }
//
//    friend void displayinformation(const City& city, const Region& region, const Megapolis& megapolis);
//};
//
//// Класс Region, наследующий GeographicalEntity
//class Region : virtual public GeographicalEntity {
//private:
//    string RegionName;
//    int RegionNumber;
//public:
//    Region(const string& RegionName, int RegionNumber) {
//        setRegionName(RegionName);
//        setRegionNumber(RegionNumber);
//    }
//
//    // Геттеры
//    string getRegionName() const {
//        return RegionName;
//    }
//
//    int getRegionNumber() const {
//        return RegionNumber;
//    }
//
//    // Сеттеры
//    void setRegionName(const string& RegionName) {
//        if (RegionName.empty()) {
//            throw runtime_error("Название региона не может быть пустым.");
//        }
//        this->RegionName = RegionName;
//    }
//
//    void setRegionNumber(int RegionNumber) {
//        if (RegionNumber < 1 || RegionNumber > 999) {
//            throw runtime_error("Номер региона должен быть от 1 до 999.");
//        }
//        this->RegionNumber = RegionNumber;
//    }
//
//    void display() const override {
//        cout << "Регион: " << RegionName << ", Номер региона: " << RegionNumber << endl;
//    }
//
//    friend void displayinformation(const City& city, const Region& region, const Megapolis& megapolis);
//};
//
//// Класс Megapolis, наследующий City и Region
//class Megapolis : public City, public Region {
//private:
//    int area; // Площадь мегаполиса
//public:
//    Megapolis(const string& cityName, int population, const string& regionName, int regionNumber, int area)
//        : City(cityName, population), Region(regionName, regionNumber), area(area) {
//        if (area < 0) {
//            throw runtime_error("Площадь не может быть отрицательной.");
//        }
//    }
//
//    // Геттеры
//    int getArea() const {
//        return area;
//    }
//
//    // Сеттер
//    void setArea(int area) {
//        if (area < 0) {
//            throw runtime_error("Площадь не может быть отрицательной.");
//        }
//        this->area = area;
//    }
//
//    void display() const override {
//        City::display();
//        Region::display();
//        cout << "Площадь мегаполиса: " << area << " кв. км" << endl;
//    }
//    friend void displayinformation(const City& city, const Region& region, const Megapolis& megapolis);
//};
//
//// дружественная функция для вывода информации о географических объектах
//void displayinformation(const City& city, const Region& region, const Megapolis& megapolis) {
//    cout << "Город:"<< endl;
//    cout << "Название Города: " << city.getCityName() << endl;
//    cout << "Население Города: " << city.getCityPopulation() << endl;
//    cout << "Регион:" << endl;
//    cout << "Название Региона: " << region.getRegionName() << endl;
//    cout << "Номер Региона: " << region.getRegionNumber() << endl;
//    cout << "Мегаполис" << endl;
//    cout << "Название Мегаполиса: " << megapolis.getCityName() << endl;
//    cout << "Население Мегаполиса: " << megapolis.getCityPopulation() << endl;
//    cout << "Название Региона Мегаполиса: " << megapolis.getRegionName() << endl;
//    cout << "Номер Региона Мегаполиса: " << megapolis.getRegionNumber() << endl;
//    cout << "Площадь Мегаполиса: " << megapolis.getArea() << endl;
//
//}
//
//// Главная функция
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    char choice;
//    string cityName, regionName;
//    int population, regionNumber, area;
//
//    City myCity("Брянск", 400000);
//    Region myRegion("Брянская область", 32);
//    Megapolis myMegapolis("Москва", 10, "г.Москва", 777, 2561);
//
//    do {
//        cout << "\nA - создать город\n"
//            << "B - создать регион\n"
//            << "C - создать мегаполис\n"
//            << "D - показать информацию\n"
//            << "E - выход\n"
//            << "Введите ваш выбор: ";
//        choice = checkChoice();
//        //cin >> choice;
//        //cin.ignore(); // Игнорировать оставшиеся символы в строке
//
//        try {
//            switch (choice) {
//            case 'A':
//                cout << "=============================" << endl;
//                cityName = checkName();
//                population = checkPopulation();
//                myCity.setCityName(cityName);
//                myCity.setCityPopulation(population);
//                cout << "Город создан." << endl;
//                cout << "=============================" << endl;
//                break;
//
//            case 'B':
//                cout << "=============================" << endl;
//                regionName = checkName();
//                regionNumber = checkRegionNumber();
//                myRegion.setRegionName(regionName);
//                myRegion.setRegionNumber(regionNumber);
//                cout << "Регион создан." << endl;
//                cout << "=============================" << endl;
//                break;
//
//            case 'C':
//                cout << "=============================" << endl;
//                cityName = checkName();
//                population = checkPopulation();
//                cout << "(для региона) ";
//                regionName = checkName();
//                regionNumber = checkRegionNumber();
//                cout << "Введите площадь мегаполиса: ";
//                cin >> area;
//                myMegapolis.setRegionName(regionName);
//                myMegapolis.setRegionNumber(regionNumber);
//                myMegapolis.setArea(area);
//                myMegapolis.setCityName(cityName);
//                myMegapolis.setCityPopulation(population);
//                cout << "Мегаполис создан." << endl;
//                cout << "=============================" << endl;
//                break;
//
//            case 'D':
//                // Здесь можно добавить код для отображения информации о созданных объектах
//                cout << "Информация о географических объектах:" << endl;
//                displayinformation(myCity, myRegion, myMegapolis);
//                // Например, myCity.display(); и т.д.
//                cout << "=============================" << endl;
//                break;
//
//            case 'E':
//                return 0;
//
//            default:
//                cout << "Некорректный ввод! Пожалуйста, попробуйте снова." << endl;
//            }
//        }
//        catch (const exception& e) {
//            cout << "Произошла ошибка: " << e.what() << endl;
//        }
//    } while (true);
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//#include <stdexcept>
//#include <windows.h>
//
//using namespace std;
//
//// Абстрактный виртуальный базовый класс
//class GeographicalEntity {
//public:
//    virtual void display() const = 0; // Чисто виртуальный метод
//    virtual ~GeographicalEntity() {}
//};
//
//// Класс City, наследующий GeographicalEntity
//class City : virtual public GeographicalEntity {
//private:
//    string name;
//    int population;
//public:
//    City(const string& name, int population) {
//        setName(name);
//        setPopulation(population);
//    }
//
//    // Геттеры
//    string getName() const {
//        return name;
//    }
//
//    int getPopulation() const {
//        return population;
//    }
//
//    // Сеттеры
//    void setName(const string& name) {
//        if (name.empty()) {
//            throw runtime_error("Название города не может быть пустым.");
//        }
//        this->name = name;
//    }
//
//    void setPopulation(int population) {
//        if (population < 0) {
//            throw runtime_error("Население не может быть отрицательным.");
//        }
//        this->population = population;
//    }
//
//    void display() const override {
//        cout << "Город: " << name << ", Население: " << population << endl;
//    }
//};
//
//// Класс Region, наследующий GeographicalEntity
//class Region : virtual public GeographicalEntity {
//private:
//    string name;
//public:
//    Region(const string& name) {
//        setName(name);
//    }
//
//    // Геттер
//    string getName() const {
//        return name;
//    }
//
//    // Сеттер
//    void setName(const string& name) {
//        if (name.empty()) {
//            throw runtime_error("Название региона не может быть пустым.");
//        }
//        this->name = name;
//    }
//
//    void display() const override {
//        cout << "Регион: " << name << endl;
//    }
//};
//
//// Класс Megapolis, наследующий City и Region
//class Megapolis : public City, public Region {
//private:
//    int area; // Площадь мегаполиса
//public:
//    Megapolis(const string& cityName, int population, const string& regionName, int area)
//        : City(cityName, population), Region(regionName), area(area) {
//        if (area < 0) {
//            throw runtime_error("Площадь не может быть отрицательной.");
//        }
//    }
//
//    // Геттеры
//    int getArea() const {
//        return area;
//    }
//
//    // Сеттер
//    void setArea(int area) {
//        if (area < 0) {
//            throw runtime_error("Площадь не может быть отрицательной.");
//        }
//        this->area = area;
//    }
//
//    void display() const override {
//        City::display();
//        Region::display();
//        cout << "Площадь мегаполиса: " << area << " кв. км" << endl;
//    }
//};
//
//// Дружественная функция для вывода информации о географических объектах
//void displayInformation(const GeographicalEntity& entity) {
//    entity.display();
//}
//
//// Функция для проверки корректности ввода названия региона
//string checkRegionName() {
//    string name;
//    cout << "Введите название региона: ";
//    getline(cin, name);
//    return name;
//}
//
//// Функция для проверки корректности ввода населения
//int checkPopulation() {
//    int population;
//    while (true) {
//        cout << "Введите население: ";
//        cin >> population;
//
//        if (cin.fail() || population < 0) {
//            cout << "Некорректный ввод! Пожалуйста, введите положительное число." << endl;
//            cin.clear(); // Сбросить состояние потока
//            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
//        }
//        else {
//            cin.ignore(1000, '\n'); // Игнорировать оставшиеся символы в строке
//            return population;
//        }
//    }
//}
//
////// Функция проверки допустимого диапазона для целых чисел
////bool isValidInput(int value) {
////    return value >= -2147483648 && value <= 2147483647; // Проверка на допустимый диапазон для int
////}
//
//// Функция для очистки буфера ввода
//void clearInputBuffer() {
//    cin.clear(); // Сбросить флаг ошибки
//    while (cin.get() != '\n'); // Очищаем буфер ввода до конца строки
//}
//
//// Основная функция
//int main() {
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//    system("color F0");
//    try {
//        string regionName = checkRegionName();
//        Region region(regionName);
//
//        int population = checkPopulation();
//        City city("Город", population);
//
//        Megapolis megapolis("Мегаполис", population, regionName, 1000);
//
//        displayInformation(region);
//        displayInformation(city);
//        displayInformation(megapolis);
//
//        // Пример изменения значений с обработкой ошибок
//        region.setName("Новый Регион");
//        city.setName("Новый Город");
//        city.setPopulation(1500000);
//        megapolis.setArea(1200);
//
//        displayInformation(region);
//        displayInformation(city);
//        displayInformation(megapolis);
//
//    }
//    catch (const runtime_error& e) {
//        cout << "Ошибка: " << e.what() << endl;
//    }
//
//    return 0;
//}
//
//#include <iostream>
//#include <string>
//#include <stdexcept>
//#include <windows.h>
//#include <limits>
//
//using namespace std;
//
//// Абстрактный виртуальный базовый класс
//class GeographicalEntity {
//public:
//    virtual void display() const = 0; // Чисто виртуальный метод
//    virtual ~GeographicalEntity() {}
//};
//
//// Класс City, наследующий GeographicalEntity
//class City : virtual public GeographicalEntity {
//private:
//    string name;
//    int population;
//public:
//    City(const string& name, int population) {
//        setName(name);
//        setPopulation(population);
//    }
//
//    // Геттеры
//    string getName() const {
//        return name;
//    }
//
//    int getPopulation() const {
//        return population;
//    }
//
//    // Сеттеры
//    void setName(const string& name) {
//        if (name.empty()) {
//            throw runtime_error("Название города не может быть пустым.");
//        }
//        this->name = name;
//    }
//
//    void setPopulation(int population) {
//        if (population < 0) {
//            throw runtime_error("Население не может быть отрицательным.");
//        }
//        this->population = population;
//    }
//
//    void display() const override {
//        cout << "Город: " << name << ", Население: " << population << endl;
//    }
//};
//
//// Класс Region, наследующий GeographicalEntity
//class Region : virtual public GeographicalEntity {
//private:
//    string name;
//public:
//    Region(const string& name) {
//        setName(name);
//    }
//
//    // Геттер
//    string getName() const {
//        return name;
//    }
//
//    // Сеттер
//    void setName(const string& name) {
//        if (name.empty()) {
//            throw runtime_error("Название региона не может быть пустым.");
//        }
//        this->name = name;
//    }
//
//    void display() const override {
//        cout << "Регион: " << name << endl;
//    }
//};
//
//// Класс Megapolis, наследующий City и Region
//class Megapolis : public City, public Region {
//private:
//    int area; // Площадь мегаполиса
//public:
//    Megapolis(const string& cityName, int population, const string& regionName, int area)
//        : City(cityName, population), Region(regionName), area(area) {
//        if (area < 0) {
//            throw runtime_error("Площадь не может быть отрицательной.");
//        }
//    }
//
//    // Геттеры
//    int getArea() const {
//        return area;
//    }
//
//    // Сеттер
//    void setArea(int area) {
//        if (area < 0) {
//            throw runtime_error("Площадь не может быть отрицательной.");
//        }
//        this->area = area;
//    }
//
//    void display() const override {
//        City::display();
//        Region::display();
//        cout << "Площадь мегаполиса: " << area << " кв. км" << endl;
//    }
//};
//
//// Дружественная функция для вывода информации о географических объектах
//void displayInformation(const GeographicalEntity& entity) {
//    entity.display();
//}
//
//// Функция для проверки корректности ввода названия региона
//string checkRegionName() {
//    string name;
//    cout << "Введите название региона: ";
//    getline(cin, name);
//    return name;
//}
//
//// Функция для проверки корректности ввода населения
//int checkPopulation() {
//    int population;
//    cout << "Введите население: ";
//    while (true) {
//        cin >> population;
//        if (cin.fail() || population < 0) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Некорректный ввод! Пожалуйста, введите положительное число: ";
//        }
//        else {
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            return population;
//        }
//    }
//}
//
//// Основная функция
//int main() {
//    SetConsoleOutputCP(1251);
//    SetConsoleCP(1251);
//    system("color F0");
//    try {
//        string regionName = checkRegionName();
//        Region region(regionName);
//
//        int population = checkPopulation();
//        City city("Город", population);
//
//        Megapolis megapolis("Мегаполис", population, regionName, 1000);
//
//        displayInformation(region);
//        displayInformation(city);
//        displayInformation(megapolis);
//
//        // Пример изменения значений с обработкой ошибок
//        region.setName("Новый Регион");
//        city.setName("Новый Город");
//        city.setPopulation(1500000);
//        megapolis.setArea(1200);
//
//        displayInformation(region);
//        displayInformation(city);
//        displayInformation(megapolis);
//
//    }
//    catch (const runtime_error& e) {
//        cout << "Ошибка: " << e.what() << endl;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//#include <stdexcept>
//#include <limits>
//
//using namespace std;
//
//// Абстрактный виртуальный базовый класс
//class GeographicalEntity {
//public:
//    virtual void display() const = 0; // Чисто виртуальный метод
//    virtual ~GeographicalEntity() {}
//};
//
//
//
//// Класс Region
//class Region : public GeographicalEntity {
//private:
//    string name;
//public:
//    Region(const string& name) {
//        setName(name);
//    }
//
//    // Геттер
//    string getName() const {
//        return name;
//    }
//
//    // Сеттер
//    void setName(const string& name) {
//        if (name.empty()) {
//            throw runtime_error("Название региона не может быть пустым.");
//        }
//        this->name = name;
//    }
//
//    void display() const override {
//        cout << "Регион: " << name << endl;
//    }
//
//    friend void displayInformation(const GeographicalEntity& entity);
//};
//
//// Класс City
//class City : public GeographicalEntity {
//private:
//    string name;
//    int population;
//public:
//    City(const string& name, int population) {
//        setName(name);
//        setPopulation(population);
//    }
//
//    // Геттеры
//    string getName() const {
//        return name;
//    }
//
//    int getPopulation() const {
//        return population;
//    }
//
//    // Сеттеры
//    void setName(const string& name) {
//        if (name.empty()) {
//            throw runtime_error("Название города не может быть пустым.");
//        }
//        this->name = name;
//    }
//
//    void setPopulation(int population) {
//        if (population < 0) {
//            throw runtime_error("Население не может быть отрицательным.");
//        }
//        this->population = population;
//    }
//
//    void display() const override {
//        cout << "Город: " << name << ", Население: " << population << endl;
//    }
//
//    friend void displayInformation(const GeographicalEntity& entity);
//};
//
//// Класс Megapolis
//class Megapolis : public City, public Region {
//private:
//    int area; // Площадь мегаполиса
//public:
//    Megapolis(const string& cityName, int population, const string& regionName, int area)
//        : City(cityName, population), Region(regionName), area(area) {
//        if (area < 0) {
//            throw runtime_error("Площадь не может быть отрицательной.");
//        }
//    }
//
//    // Геттеры
//    int getArea() const {
//        return area;
//    }
//
//    // Сеттер
//    void setArea(int area) {
//        if (area < 0) {
//            throw runtime_error("Площадь не может быть отрицательной.");
//        }
//        this->area = area;
//    }
//
//    void display() const override {
//        City::display();
//        Region::display();
//        cout << "Площадь мегаполиса: " << area << " кв. км" << endl;
//    }
//
//    friend void displayInformation(const GeographicalEntity& entity);
//};
//
//// Дружественная функция для вывода информации о географических объектах
//void displayInformation(const GeographicalEntity& entity) {
//    entity.display();
//}
//
//// Функция для проверки корректности ввода названия региона
//string checkRegionName() {
//    string name;
//    cout << "Введите название региона: ";
//    getline(cin, name);
//    return name;
//}
//
//// Функция для проверки корректности ввода населения
//int checkPopulation() {
//    int population;
//    cout << "Введите население: ";
//    while (true) {
//        cin >> population;
//        if (cin.fail() || population < 0) {
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Некорректный ввод! Пожалуйста, введите положительное число: ";
//        }
//        else {
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            return population;
//        }
//    }
//}
//
//// Основная функция
//int main() {
//    try {
//        string regionName = checkRegionName();
//        Region region(regionName);
//
//        int population = checkPopulation();
//        City city("Город", population);
//
//        Megapolis megapolis("Мегаполис", population, regionName, 1000);
//
//        displayInformation(region);
//        displayInformation(city);
//        displayInformation(megapolis);
//
//        // Пример изменения значений с обработкой ошибок
//        region.setName("Новый Регион");
//        city.setName("Новый Город");
//        city.setPopulation(1500000);
//        megapolis.setArea(1200);
//
//        displayInformation(region);
//        displayInformation(city);
//        displayInformation(megapolis);
//
//    }
//    catch (const runtime_error& e) {
//        cout << "Ошибка: " << e.what() << endl;
//    }
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
