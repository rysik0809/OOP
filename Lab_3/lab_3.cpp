#include <iostream>
#include <vector>

using namespace std;

class Organization{
    protected:
        string name; //название
        string address; //адрес
        int employeas; //количество сотрудников
    public:
        Organization():name("Неизвестно"),address("Неизвестно"),employeas(0) {}
        Organization(const string& n, const string& addr, int emp){
            name = n;
            address = addr;
            employeas = emp;
        }
        virtual ~Organization() {}

        void setName(const string& n) { name = n; }
        string getName() const { return name; }

        void setAddress(const string& addr) { address = addr; }
        string getAddress() const { return address; }

        void setEmployeas(int emp) { employeas = emp; }
        int getEmployeas() const { return employeas; }

        virtual void print() const {
            cout<<"Организация: "<<name<<endl;
            cout<<"Адрес: "<<address<<endl;
            cout<<"Кол-во сотрудников: "<<employeas<<endl;
        }
};

class InsuranceCompany : public Organization{
    private:
        int policies; //кол-во страховак
        string insuranceTupe; //тип страховки

    public:
        InsuranceCompany() : Organization(),policies(0), insuranceTupe("Неизвестно") {} 
        InsuranceCompany(const string& n, const string& addr, int emp, int pol, const string& tupe){
            name = n;
            address = addr;
            employeas = emp;
            policies = pol;
            insuranceTupe = tupe;
        }

        void setPolicies(int pol) { policies = pol; }
        int getPolicies() const { return policies; }

        void setInsuranceTupe(const string& tupe) { insuranceTupe = tupe; }
        string getInsuranceTupe() const { return insuranceTupe; }

        void print() const override{
            cout<<"--- Страховая компания ---"<<endl;
            Organization::print();
            cout<<"Кол-во полисов: "<<policies<<endl;
            cout<<"Тип страховки: "<<insuranceTupe<<endl;
        }
};

class Factory : public Organization {
    private:
        string industry; //отрасль
        int workshops; //кол-во цехов
        double annualOutput; //годовой доход
    public:
        Factory() : Organization(),industry("Неизвестно"),workshops(0),annualOutput(0.0) {}
        Factory(const string& n, const string addr, int emp, 
            const string& ind, int ws, double output){
                name = n;
                address = addr;
                employeas = emp;
                industry = ind;
                workshops = ws;
                annualOutput = output;
        }

        void setIndustry(const string& ind) { industry = ind; }
        string getIndustry() const { return industry; }

        void setWorkshops(int ws) { workshops = ws; }
        int getWorkshops() const { return workshops; }

        void setAnnualOutput(double output) { annualOutput = output; }
        double getAnnualotput() const { return annualOutput; }

        void print() const override{
            cout<<"--- Завод ---"<<endl;
            Organization::print();
            cout<<"Отрасль: "<<industry<<endl;
            cout<<"Кол-во цехов: "<<workshops<<endl;
            cout<<"Годовой объем продукции: "<<annualOutput<<endl;
        }
};

int main(){
    int numComp, numFact = 0;
    
    vector<InsuranceCompany> insuranceCompanys;
    cout<<"Напишите кол-во страховых компаний: ";
    cin>>numComp;

    for(int i = 0; i < numComp; i++){
        string nm, ad, tupe;
        int em, num;
        cout<<"Организация: ";
        cin>>nm;
        cout<<"Адрес: ";
        cin>>ad;
        cout<<"Кол-во сотрудников: ";
        cin>>em;
        cout<<"Кол-во полисов: ";
        cin>>num;
        cout<<"Тип страховки: ";
        cin>>tupe;

        insuranceCompanys.push_back(InsuranceCompany(nm, ad, em, num, tupe));
        cout<<endl;
    }

    vector<Factory> factorys;
    cout<<"Напишите кол-во заводов: ";
    cin>>numFact;

    for(int i = 0; i < numFact; i++){
        string nm, ad, tupe;
        int em, numW;
        double V;
        cout<<"Организация: ";
        cin>>nm;
        cout<<"Адрес: ";
        cin>>ad;
        cout<<"Кол-во сотрудников: ";
        cin>>em;
        cout<<"Отрасль: ";
        cin>>tupe;
        cout<<"Кол-во цехов: ";
        cin>>numW;
        cout<<"Годовой объем продукции: ";
        cin>>V;

        factorys.push_back(Factory(nm, ad, em, tupe, numW, V));
        cout<<endl;
    }

    cout<<"____СТРАХОВЫЕ_КОМПАНИИ____\n";
    for(const auto& company : insuranceCompanys){
        company.print();
    }
    cout<<endl;
    cout<<"____ЗАВОДЫ____\n";
    for(const auto& factory : factorys){
        factory.print();
    }

    return 0;
}