#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Базовый класс
class Transport {
protected:
    string type;
public:
    Transport() : type("Неизвестно") {}
    Transport(const string& t) : type(t) {}
    virtual ~Transport() {}

    void setType(const string& t) { type = t; }
    string getType() const { return type; }

    virtual void print() const {
        cout << "Тип транспорта: " << type << endl;
    }
};

// Самолёт
class Airplane : public Transport {
private:
    int capacity;
    string name;
    string aerodrome;
public:
    Airplane() : Transport(), capacity(0), name("Неизвестно"), aerodrome("Неизвестно") {}
    Airplane(const string& t, const string& n, const string& aer, int cap)
        : Transport(t), name(n), aerodrome(aer), capacity(cap) {}

    void setCapacity(int c) { capacity = c; }
    int getCapacity() const { return capacity; }
    void setAerodrome(const string& a) { aerodrome = a; }
    string getAerodrome() const { return aerodrome; }
    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void print() const override {
        cout << "--- Самолет ---" << endl;
        Transport::print();
        cout << "Название: " << name << endl;
        cout << "Кол-во пассажиров: " << capacity << endl;
        cout << "Аэродром: " << aerodrome << endl;
    }
};

// Автомобиль
class Car : public Transport {
private:
    int capacity;
    string name;
    string garage;
public:
    Car() : Transport(), capacity(0), name("Неизвестно"), garage("Неизвестно") {}
    Car(const string& t, const string& n, const string& gar, int cap)
        : Transport(t), name(n), garage(gar), capacity(cap) {}

    void setCapacity(int c) { capacity = c; }
    int getCapacity() const { return capacity; }
    void setGarage(const string& g) { garage = g; }
    string getGarage() const { return garage; }
    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void print() const override {
        cout << "--- Автомобиль ---" << endl;
        Transport::print();
        cout << "Название: " << name << endl;
        cout << "Кол-во пассажиров: " << capacity << endl;
        cout << "Гараж: " << garage << endl;
    }
};

// Поезд
class Train : public Transport {
private:
    int capacity;
    string name;
    string depo;
public:
    Train() : Transport(), capacity(0), name("Неизвестно"), depo("Неизвестно") {}
    Train(const string& t, const string& n, const string& d, int cap)
        : Transport(t), name(n), depo(d), capacity(cap) {}

    void setCapacity(int c) { capacity = c; }
    int getCapacity() const { return capacity; }
    void setDepo(const string& d) { depo = d; }
    string getDepo() const { return depo; }
    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void print() const override {
        cout << "--- Поезд ---" << endl;
        Transport::print();
        cout << "Название: " << name << endl;
        cout << "Кол-во пассажиров: " << capacity << endl;
        cout << "Депо: " << depo << endl;
    }
};

int main() {
    vector<Transport*> vehicles;   // вектор сырых указателей

    int numPlanes, numCars, numTrains;

    // ---- Ввод самолётов ----
    cout << "Напишите кол-во самолетов: ";
    cin >> numPlanes;
    for (int i = 0; i < numPlanes; ++i) {
        string name, type, aerodrome;
        int capacity;
        cout << "Название: ";
        cin >> name;
        cout << "Тип: ";
        cin >> type;
        cout << "Аэродром: ";
        cin >> aerodrome;
        cout << "Кол-во пассажиров: ";
        cin >> capacity;

        vehicles.push_back(new Airplane(type, name, aerodrome, capacity));
        cout << endl;
    }

    // ---- Ввод автомобилей ----
    cout << "Напишите кол-во машин: ";
    cin >> numCars;
    for (int i = 0; i < numCars; ++i) {
        string name, type, garage;
        int capacity;
        cout << "Название: ";
        cin >> name;
        cout << "Тип: ";
        cin >> type;
        cout << "Гараж: ";
        cin >> garage;
        cout << "Кол-во пассажиров: ";
        cin >> capacity;

        vehicles.push_back(new Car(type, name, garage, capacity));
        cout << endl;
    }

    // ---- Ввод поездов ----
    cout << "Напишите кол-во поездов: ";
    cin >> numTrains;
    for (int i = 0; i < numTrains; ++i) {
        string name, type, depo;
        int capacity;
        cout << "Название: ";
        cin >> name;
        cout << "Тип: ";
        cin >> type;
        cout << "Депо: ";
        cin >> depo;
        cout << "Кол-во пассажиров: ";
        cin >> capacity;

        vehicles.push_back(new Train(type, name, depo, capacity));
        cout << endl;
    }

    // ---- Вывод всех транспортных средств ----
    cout << "\n=== СПИСОК ВСЕХ ТРАНСПОРТНЫХ СРЕДСТВ ===\n";
    for (const auto& v : vehicles) {
        v->print();
        cout << endl;
    }

    // ---- Освобождение памяти (ВАЖНО!) ----
    for (auto& v : vehicles) {
        delete v;
    }
    vehicles.clear();

    return 0;
}