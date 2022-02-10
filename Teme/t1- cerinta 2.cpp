#include <iostream>
#include <algorithm>

using namespace std;

class Employee {
protected:
    int SalariuBrut{};
    string Nume;

public:
    Employee(int _salariuBrut, string _nume) : SalariuBrut(_salariuBrut), Nume(std::move(_nume)) {}

    Employee() = default;
    ~Employee() = default;

    int getSalariuBrut() const {
        return SalariuBrut;
    }

    void setSalariuBrut(int salariuBrut) {
        SalariuBrut = salariuBrut;
    }

    string getNume() const {
        return Nume;
    }

    void setNume(string &_nume) {
        Nume = _nume;
    }

    friend ostream &operator<<(ostream &os, const Employee &employee) {
        os << "SalariuBrut: " << employee.SalariuBrut << endl << "Nume: " << employee.Nume << endl;
        return os;
    }

    friend istream&operator>>(istream& i,Employee &employee){
        cout<<"SalariuBrut:" ; i>>employee.SalariuBrut;
        cout<<"Nume" ; i>>employee.Nume;
        return i;
    }

    virtual double bruteSalary() {
        return SalariuBrut;
    }

    virtual double netSalary() {
        return 0;
    }

    virtual string description () {
        return "Please do not call virtual methods on parents! We need specialized classes ;)";
    }

};



class Programmer : public Employee {
private:
    int oreBonus;

public:
    Programmer(int _salariuBrut, string _nume, int _oreBonus) : Employee(_salariuBrut, std::move(_nume)), oreBonus(_oreBonus) {}

    Programmer() : oreBonus(0) {}

    virtual ~Programmer() = default;

    friend istream &operator>>(istream &i, Programmer &programmer) {
        cout << "SalariuBrut:";
        i >> programmer.SalariuBrut;
        cout << "Nume:";
        i >> programmer.Nume;
        cout<< "Ore Bonus:";
        i >> programmer.oreBonus;
        return i;
    }

    friend ostream &operator<<(ostream &out, const Programmer &programmer) {
        out << (Employee) programmer << "Ore Bonus: " << programmer.oreBonus << "\n";
        return out;
    }

    double bruteSalary() override {
        return Employee::bruteSalary() + oreBonus * (double) 75;
    }

    double netSalary() override {
        return bruteSalary() - min((double) 47 / (double) 100 * Employee::bruteSalary(), double(800));
    }

    string description() override {
        return Programmer::getNume() + " Is our programmer";
    }
};

    class MarketingExpert : public Employee {
    private:
        int profitGenerat;

    public:
        MarketingExpert(int _salariuBrut, string _nume, int _profitGenerat) : Employee(_salariuBrut, std::move(_nume)),
                                                                           profitGenerat(_profitGenerat) {}

        MarketingExpert() : profitGenerat(0) {}

        virtual ~MarketingExpert() = default;

        friend istream &operator>>(istream &i, MarketingExpert &marketingexpert) {
            cout << "SalariuBrut:";
            i >> marketingexpert.SalariuBrut;
            cout << "Nume:";
            i >> marketingexpert.Nume;
            cout<< "Profit generat:";
            i >> marketingexpert.profitGenerat;
            return i;
        }

        friend ostream &operator<<(ostream &os, const MarketingExpert &marketingexpert) {
            os << (Employee) marketingexpert << "profit Generat: " << marketingexpert.profitGenerat << endl;
            return os;
        }

        double bruteSalary() override {
            return (Employee::bruteSalary) () + (0.05*profitGenerat);
        }

        double netSalary() override {
            return bruteSalary()/2;
        }
        string description() override {
            return MarketingExpert::getNume() + " Is our Marketing Expert";
        }
    };

    class FinancialAnalyst : public Employee {
    public:
        FinancialAnalyst(int _salariuBrut, string _nume) : Employee(_salariuBrut, std::move(_nume)) {}

        virtual ~FinancialAnalyst() = default;

        friend istream &operator>>(istream &i, FinancialAnalyst &financialanalyst) {
            cout << "SalariuBrut:";
            i >> financialanalyst.SalariuBrut;
            cout << "Nume:";
            i >> financialanalyst.Nume;
            return i;
        }

        friend ostream &operator<<(ostream &os, const FinancialAnalyst &financialanalyst) {
            os << (Employee) financialanalyst << endl;
            return os;
        }

        double bruteSalary() override {
            return Employee::bruteSalary();
        }

        double netSalary() override {
            return (double) 53 / (double) 100 * Employee::bruteSalary();
        }
        string description() override {
            return FinancialAnalyst::getNume() + " Is our Financial Analyst";
        }


    };

//int main()
//{
//    Employee p;
//    Programmer pr(5000,"andrei", 10);
//    Programmer pr2{6000,"cosmin",20};
//    MarketingExpert pr3{4000,"sjajdn",5000};
//    FinancialAnalyst pr4{4500,"dushds"};
//
//
//
//    cout<<pr.bruteSalary()<<" "<<pr.netSalary()<<" ";
//    cout<<endl;
//    cout<<pr3.bruteSalary() << " "<< pr3.netSalary();
//    cout<<endl;
//    cout<<pr4.netSalary()<< "  " <<pr4.bruteSalary();


// TODO va fi recomendat
//  ca inainte de a lucra la clasele derivate, sa creati in clasa de baza toate metodele virtuale,
//  astfel incat sa puteti folosi Ctrl+O pentru a le genera usor
//  .
//  CA BONUS, veti putea implementa inclusiv metodele de afisare si citire "implementata virtual".
//            Vom face asta in laboratorul 8.


// TODO rand pe rand, puteti decomenta fiecare dintre liniile de mai jos, trecute cu TODO inainte
int main() {


        // *** PART 1: Crearea unor angajati din fiecare tip ***
// TODO DONE

        Employee e;
        Programmer e1{4000, "Marc", 10};
        MarketingExpert e2{3000, "Peter", 7000};
        FinancialAnalyst e3{2700, "Stephen"};

        cout << "Octeti Programmer: " << sizeof(e1) << endl;
        // TODO
        //  Va rog sa scrieti si linia necesara pentru a afisa de cati octeti este nevoie
        //  cand cream un MarketingExpert, respectiv un FinancialAnalyst:
        //  aici..
        cout << "Octeti MarketingExpert: " << sizeof(e2) << endl;
        cout << "Octeti FinancialAnalyst: " << sizeof(e3) << endl;
        cout << endl;

// TODO DONE

        // *** PART 2: Metode specializate (en. overriding during inheritance) ***
        // TODO hotkey: Ctrl+O (from Override) when inside a child class, and we can choose from a list of methods.
        //              !!! it only works if your class inehrits another class.

        cout << e.description() << endl;    // prints "Please do not call virtual methods on parents!
        //                                              We need specialized classes ;)"
        cout << e1.description() << endl;   // prints "Marc is our Programmer"
        cout << e2.description() << endl;   // prints "Peter is our Marketing Expert"
        cout << e3.description() << endl;   // prints "Stephen is our Financing Expert"
        cout << endl;


       // TODO DONE


        // *** PART 3: cum folosim operator<< din parinte pt a nu repeta codul :D ***

        cout << e << endl; // baseSalary: 0 name: ""       <- e a fost creat folosind constructorul default.
        cout << e1 << endl;
        cout << e2 << endl;
        cout << e3 << endl;
        cout<<endl;

//
//        // *** PART 4: metodele membre pe care le suprascriem (en. override) ***
//
//
//        //  Acestea sunt descrise in cerinta din docx.
//
//        // 1. ()
        cout << e.bruteSalary() << endl;    // prints 0
        cout << e1.bruteSalary() << endl;   // prints 4750
        cout << e2.bruteSalary() << endl;   // prints 3350
        cout << e3.bruteSalary() << endl;   // prints 2700
        cout << endl;

//        // 2. netSalary()
        cout << e.netSalary() << endl;    // prints 0
        cout << e1.netSalary() << endl;   // prints 3950
        cout << e2.netSalary() << endl;   // prints 1675
        cout << e3.netSalary() << endl;   // prints 1431
        cout << endl;
//
//        // *** PART 5: Implementam de la zero si metoda de citire (>>) ***
//
//
//        // Hint: va fi foarte similar cu << pe care deja l-ati implementat.
//        // E.g. pentru Programmer
        Programmer programmer;
        cin >> programmer; /*
// Citirea se va face:
//
//    baseSalary: ENTERED_BASE_SALARY
//    name: ENTERED_NAME
//    bonus hours: ENTERED_INT
//
// */
        cout << " -> Am citit: " << programmer; // verificare citire.
//        // TODO similar (citire + afisare) pentru MarketingExpert si FinancialAnalyst
//        //  ..
}