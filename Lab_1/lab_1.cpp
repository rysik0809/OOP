#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Train{
    private:
        string destination; //пункт назначения
        int trainNumber; //номер поезда
        int timeHour; // время отправления час 
        int timeMinute; // время отправления минуты
        int numberCommonPlaces; // число общих мест
        int numberCompartments; // купе
        int numberReservedSeat; // плацкарт
        
        bool isValidTrainNumber(int n){ // валидация номеров поездов
            return (n > 0 && n < 1000000);
        }
        bool isTimeHour(int th){ // валидация времени отправления (часы)
            return (th >= 0 && th < 24);
        }
        bool isTimeMinute(int tm){ // валидация времени отправления (минуты)
            return (tm >= 0 && tm < 60);
        }
        bool isNumberCommonPlaces(int x){ // валидация всех мест в поезде
            return (x > 0 && x < 5000);
        }
        bool isNumberCompartments(int y){ // валидация мест купе
            return (y > 0 && y <= numberCommonPlaces);
        }
        bool isNumberReservedSeat(int z){ // валидация мест плацкарт
            return (z > 0 && z <= numberCommonPlaces - numberCompartments);
        }

    public:
        Train();
        Train(const string& d, int tn, int th, int tm, int ncp, int nc, int nrs){
            if(!d.empty()){
                destination = d;
            }else{
                destination = "Город Z";
                cout<<"Нет пункта назначения, установлено имя: Город Z\n";
            }
            if (isValidTrainNumber(tn)){
                trainNumber = tn;
            }else{
                trainNumber = 1;
                cout<<"Не указан номер поезда, установлено: 1\n";
            }
            if(isTimeHour(th)){
                timeHour = th;
            }else{
                timeHour = 12;
                cout<<"Не указан час отправления поезда, установлено: 12 часов\n";
            }
            if(isTimeMinute(tm)){
                timeMinute = tm;
            }else{
                timeMinute = 0;
                cout<<"Не указаны минуты отправления, установлено: 0 мин.\n";
            }
            if (isNumberCommonPlaces(ncp)){
                numberCommonPlaces = ncp;
            }else{
                numberCommonPlaces = 100;
                cout<<"Не указано всего мест в поезде, установлено: 100\n";
            }
            if (isNumberCommonPlaces(ncp)){
                numberCommonPlaces = ncp;
            }else{
                numberCommonPlaces = 100;
                cout<<"Не указано всего мест в поезде, установлено: 100\n";
            }
            if (isNumberCompartments(nc)){
                numberCompartments = nc;
            }else{
                numberCompartments = numberCommonPlaces / 2;
                cout<<"Не указано мест купе в поезде, установлено значение по умолчанию.\n";
            }
            if (isNumberReservedSeat(nrs)){
                numberReservedSeat = nrs;
            }else{
                numberReservedSeat = numberCommonPlaces - numberCompartments;
                cout<<"Не указано мест плацкарт в поезде, устано значение по умолчанию.\n";
            }
        }
        Train(const Train& train){
            destination = train.destination;
            trainNumber = train.trainNumber;
            timeHour = train.timeHour; 
            timeMinute = train.timeMinute;
            numberCommonPlaces = train.numberCommonPlaces;
            numberCompartments = train.numberCompartments;
            numberReservedSeat = train.numberReservedSeat;
        }

        void setDestination(const string& sd);
        void setTrainNumber(int stn);
        void setTimeHour(int sth);
        void setTimeMinute(int stm);
        void setNumberCommonPlaces(int sncp);
        void setNumberCompartments(int snc);
        void setNumberReservedSeat(int snrs);

        string getDestination() const {return destination;}
        int getTrainNumber() const {return trainNumber;}
        int getTimeHour() const {return timeHour;}
        int getTimeMinute() const {return timeMinute;}
        int getNumberCommonPlaces() const {return numberCommonPlaces;}
        int getNumberCompartments() const {return numberCompartments;}
        int getNumberReservedSeat() const {return numberReservedSeat;}

        void getTrain(){
            cout<<"Поезд №"<<trainNumber<<endl<<"Пункт назначения: "<<destination<<endl
                <<"Время отправления: "<<timeHour<<":"<<setfill('0')<<setw(2)<<timeMinute<<endl
                <<"Количество мест в поезде: "<<numberCommonPlaces<<endl
                <<"Плацкарт: "<<numberReservedSeat<<endl<<"Купе: "<<numberCompartments<<endl;
        } 
        ~Train();
};

Train::Train():destination("Неизвестно"),trainNumber(1),timeHour(0),
    timeMinute(0),numberCommonPlaces(0),numberCompartments(0),numberReservedSeat(0){
    }

void Train::setDestination(const string& d){
    if(!d.empty()){
        destination = d;
    }else{
        destination = "Город Z";
        cout<<"Нет пункта назначения, установлено имя: Город Z\n";
    }
}
void Train::setTrainNumber(int tn){
    if (isValidTrainNumber(tn)){
        trainNumber = tn;
    }else{
        trainNumber = 1;
        cout<<"Не указан номер поезда, установлено: 1\n";
    }
}
void Train::setTimeHour(int th){
    if(isTimeHour(th)){
        timeHour = th;
    }else{
        timeHour = 12;
        cout<<"Не указан час отправления поезда, установлено: 12 часов\n";
    }
}
void Train::setTimeMinute(int tm){
    if(isTimeMinute(tm)){
        timeMinute = tm;
    }else{
        timeMinute = 0;
        cout<<"Не указаны минуты отправления, установлено: 0 мин.\n";
    }
}
void Train::setNumberCommonPlaces(int ncp){
    if (isNumberCommonPlaces(ncp)){
        numberCommonPlaces = ncp;
    }else{
        numberCommonPlaces = 100;
        cout<<"Не указано всего мест в поезде, установлено: 100\n";
    }
}
void Train::setNumberCompartments(int nc){
    if (isNumberCompartments(nc)){
        numberCompartments = nc;
    }else{
        numberCompartments = numberCommonPlaces / 2;
        cout<<"Не указано мест купе в поезде, установлено значение по умолчанию.\n";
    }
}
void Train::setNumberReservedSeat(int nrs){
    if (isNumberReservedSeat(nrs)){
        numberReservedSeat = nrs;
    }else{
        numberReservedSeat = numberCommonPlaces - numberCompartments;
        cout<<"Не указано мест плацкарт в поезде, устано значение по умолчанию.\n";
    }
}

Train::~Train(){}

int main(){
    int size;
    cout<<"Введите количество поездов: ";
    cin>>size;
    if (size <= 0) {
        cout<<"Некорректное количество поездов!\n";
        return 1;
    }
    Train* trains = new Train[size];

    int controller = 1;

    while (controller != 0)
    {
        cout<<"\nМеню:\n";
        cout<<"1. Создать список поездов\n";
        cout<<"2. Создать копию существующего поезда\n";
        cout<<"3. Вывести список поездов\n";
        cout<<"4. Вывести список поездов, следующих до заданного пункта\n";
        cout<<"5. Вывести список поездов, следующих до заданного пункта и после заданного часа\n";
        cout<<"6. Вывести список поездов, следующих до заданного пункта и с одинаковой вместимостью\n";
        cout<<"0. Выход\n";
        cout<<"Выберите действие: ";
        cin>>controller;
        switch (controller)
        {
            case 1:
                for(int i = 0; i < size; i++){
                    cout << "\nПоезд #" << (i + 1) << ":\n";
                    string d; 
                    int tn, th, tm, ncp, nc, nrs; 
                    cout<<"Введите пункт назначения: ";
                    cin.ignore();
                    getline(cin, d);
                    cout<<"Введите номер поезда: ";
                    cin>>tn;
                    cout<<"Введите время отправления поезда(час) поезда: ";
                    cin>>th;
                    cout<<"Введите время отправления поезда(минуты) поезда: ";
                    cin>>tm;
                    cout<<"Введите число общих мест в поезде: ";
                    cin>>ncp;
                    cout<<"Введите число мест (купе) в поезде: ";
                    cin>>nc;
                    cout<<"Введите число мест (плацкарт) в поезде: ";
                    cin>>nrs;
                    trains[i] = Train(d, tn, th, tm, ncp, nc, nrs);
                }
                break;
            case 2:
                {
                    int sourceIndex, destIndex;
                    cout<<"Введите номер поезда для копирования (1-"<<size<<"): ";
                    cin>>sourceIndex;
                    
                    if (sourceIndex < 1 || sourceIndex > size) {
                        cout << "Некорректный номер поезда!\n";
                        break;
                    }
                    cout<<"Введите номер позиции для вставки копии (1-"<<size<<"): ";
                    cin >> destIndex;
                    
                    if (destIndex < 1 || destIndex > size) {
                        cout<<"Некорректная позиция!\n";
                        break;
                    }
                    
                    trains[destIndex - 1] = Train(trains[sourceIndex - 1]);
                    cout<<"Поезд успешно скопирован!\n";
                }
                break;
            case 3:
                cout<<"Список всех поездов:\n";
                for(int i = 0; i < size; i++){
                    cout<<"Поезд #"<< i + 1<<endl;
                    trains[i].getTrain();
                    cout<<endl;
                }
                break;
            case 4:
                {
                    string current;
                    cout<<"Введите пункт назначения: ";
                    cin.ignore();
                    getline(cin, current);
                    cout<<"Список поездов, следующих до пункта "<<current<<":\n";
                    bool found = false;
                    for(int i = 0; i < size; i++){
                        if(trains[i].getDestination() == current){
                            trains[i].getTrain();
                            cout<<endl;
                            found = true;
                        }
                    }
                    if (!found) {
                        cout<<"Поездов до "<<current<<" не найдено.\n";
                    }
                }
                break;
            case 5:
                {
                    string current;
                    int hour;
                    cout<<"Введите пункт назначения: ";
                    cin.ignore();
                    getline(cin, current);
                    cout<<"Введите час: ";
                    cin>>hour;
                    cout<<"Список поездов, следующих до пункта "<<current<<" после "<<hour<<" часов:\n";
                    bool found = false;
                    for(int i = 0; i < size; i++){
                        if(trains[i].getDestination() == current && trains[i].getTimeHour() > hour){
                            trains[i].getTrain();
                            cout<<endl;
                            found = true;
                        }
                    }
                    if (!found) {
                        cout<<"Поездов до "<<current<<" после "<<hour<<" часов не найдено.\n";
                    }
                }
                break;
            case 6:
                {
                    string current;
                    int capacity;
                    cout<<"Введите пункт назначения: ";
                    cin.ignore();
                    getline(cin, current);
                    cout<<"Введите вместимость (общее количество мест): ";
                    cin>>capacity;
                    cout<<"Список поездов, следующих до пункта "<<current<<" с вместимостью "<<capacity<<":\n";
                    bool found = false;
                    for(int i = 0; i < size; i++){
                        if(trains[i].getDestination() == current && trains[i].getNumberCommonPlaces() == capacity){
                            trains[i].getTrain();
                            cout<<endl;
                            found = true;
                        }
                    }
                    if (!found) {
                        cout<<"Поездов до "<<current<<" с вместимостью "<<capacity<<" не найдено.\n";
                    }
                }
                break;
            case 0:
                cout<<"Выход из программы.\n";
                break;
            default:
                cout<<"Некорректный выбор! Попробуйте снова.\n";
                break;
        }
    }
    
    delete[] trains;
    return 0;
}