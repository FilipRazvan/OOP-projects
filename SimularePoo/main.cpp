//// jucariile pot fi de mai multe tipuri
//// copiii pot fi copii cuminti sau neastamparati

/// Filip Razvan Adrian
/// Grupa 263
/// IDE C-lion

//Clasa Jucarie -> Clasice, Educative , Electronice , Moderne
//Clasa Moderne -> Mostenire diamant , pot fi si educative si electronice
//Clasa Copil -> Cuminti , Neastamparati
// Copiii au un ID care se incrementeaza automat, ceea ce inseamna ca avem nevoie de o variabila statica
#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <ios>

using namespace std;

class Jucarie {                                     ///CLASA JUCARIE
protected:
    string denumire;
    float dimensiune{};  /// Cand avem o valoare este indicat sa initializam cu "{}" .
    string tip;


public:
    Jucarie() = default;
    virtual ~Jucarie() = default;
    Jucarie(string _denumire,float _dimensiune, string _tip);  // Constructorul parametrizat
    Jucarie(const Jucarie&) = default;  // Constructorul de copiere
    Jucarie &operator=(const Jucarie&) = default; // Operatorul egal


    friend istream& operator>>(istream& in, Jucarie& jucarie);
    friend ostream& operator<<(ostream& out, const Jucarie& jucarie);

    virtual void read(istream& in);
    virtual void print(ostream& out) const;  // Punem const sa evitam orice risc de editare in timpul apelului        Alt+Insert -> Generate definitions

};

Jucarie::Jucarie(string _denumire, float _dimensiune, string _tip) {

    this->denumire = _denumire;
    this->dimensiune = _dimensiune;
    this->tip = _tip;
}

istream &operator>>(istream &in, Jucarie &jucarie) {
    jucarie.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Jucarie &jucarie) {
    jucarie.print(out);
    return out;
}

void Jucarie::read(istream &in) {
    cout<<"Denumire: ";
    in>>denumire;

    cout<<"Dimensiune: ";
    in>>dimensiune;

    cout<<"Tip: ";
    in>>tip;
}

void Jucarie::print(ostream &out) const {
        out<<"Denumire: " <<denumire <<"\n";
        out<<"Dimensiune: "<<dimensiune <<"\n";
        out<<"Tip: "<< tip << "\n";
}






class JucarieClasica : public Jucarie {

protected:
    string material;
    string culoare;

public:

    JucarieClasica() = default;
    ~JucarieClasica() override = default;
    JucarieClasica(string _denumire,float _dimensiune, string _tip,string _material, string _culoare);
    JucarieClasica(const JucarieClasica&) = default; // Op. Egal
    JucarieClasica & operator=(const JucarieClasica&) = default;



    void read(istream& in) override;
    void print(ostream& out) const override;
};

JucarieClasica::JucarieClasica(string _denumire,float _dimensiune, string _tip,string _material, string _culoare): Jucarie(_denumire,_dimensiune,_tip) {
    this->material = _material;
    this->culoare = _culoare;
}

void JucarieClasica::read(istream &in) {
    Jucarie::read(in);

    cout<<"Material: ";
    in>>material;

    cout<<"Culoare: ";
    in>>culoare;
}

void JucarieClasica::print(ostream &out) const {
    Jucarie::print(out);

    cout<<"Material: " << material << "\n";
    cout<<"Culoare: " << culoare << "\n";

}


class JucarieEducativa : virtual public Jucarie {
protected:
    string abilitate;

public:

    JucarieEducativa() = default;
    ~JucarieEducativa() override = default;

    JucarieEducativa(string _denumire,float _dimensiune, string _tip, string _abilitate);
    JucarieEducativa(const JucarieEducativa&) = default;
    JucarieEducativa &operator=(const JucarieEducativa&) = default;

    void read(istream& in) override;
    void print(ostream& out) const override;
};

JucarieEducativa::JucarieEducativa(string _denumire, float _dimensiune, string _tip, string _abilitate):Jucarie(_denumire,_dimensiune,_tip) {

    this->abilitate = _abilitate;
}

void JucarieEducativa::read(istream &in) {
    Jucarie::read(in);

    cout<<"Abilitate: ";
    in>> abilitate;


}

void JucarieEducativa::print(ostream &out) const {
    Jucarie::print(out);

    cout<<"Abilitate: " << abilitate << "\n";
}



class JucarieElectronica : virtual public Jucarie {
public:
    int numarBaterii{};  // Pentru initializare Acoladele

public:

    JucarieElectronica() = default;
    ~JucarieElectronica() override = default;
    JucarieElectronica(string _denumire,float _dimensiune, string _tip, int numarBaterii);
    JucarieElectronica & operator =(const JucarieElectronica&) = default;
    JucarieElectronica(const JucarieElectronica&) = default;


    void read(istream& in) override;
    void print(ostream& out) const override;

};

JucarieElectronica::JucarieElectronica(string _denumire, float _dimensiune, string _tip, int _numarBaterii): Jucarie(_denumire,_dimensiune,_tip) {

    this->numarBaterii = _numarBaterii;
}

void JucarieElectronica::read(istream &in) {
    Jucarie::read(in);

    cout<<"Numar Baterii: ";
    in>>numarBaterii;
}

void JucarieElectronica::print(ostream &out) const {
    Jucarie::print(out);

    cout<<"Numar Baterii: " << numarBaterii << "\n";

}


class JucarieModerna : public JucarieEducativa, public JucarieElectronica{
protected:
    string brand;
    string model;

public:
    JucarieModerna() = default;
    ~JucarieModerna() override = default;
    JucarieModerna(string _denumire,float _dimensiune, string _tip, string _brand, string _model);
    JucarieModerna(const JucarieModerna&) = default;
    JucarieModerna &operator=(const JucarieModerna&) = default;

    void read(istream &in) override;

    void print(ostream &out) const override;


};

JucarieModerna::JucarieModerna(string _denumire, float _dimensiune, string _tip, string _brand, string _model) :
Jucarie(_denumire,_dimensiune,_tip),
JucarieEducativa(_denumire,_dimensiune,_tip,"generala"),
JucarieElectronica(_denumire,_dimensiune,_tip,1){

    this->brand = _brand;
    this->model = _model;

}

void JucarieModerna::read(istream &in) {
    cout<< "Denumire: ";
    in>> denumire;

    cout<< "Dimensiune: ";
    in>> dimensiune;

    cout<< "Tip: ";
    in>> tip;

    cout<<"Brand: ";
    in>>brand;

    cout<<"Model: ";
    in>>model;
}

void JucarieModerna::print(ostream &out) const {
    JucarieEducativa::print(out);
    out<<"Numar baterii: " << numarBaterii << "\n";

    out<<"Brand: " << brand << "\n";
    out<<"Model: " << model << "\n";
}


class Copil {
protected:
    static int static_idCopil;
    int idCopil{};
    string nume;
    string prenume;
    string adresa;
    unsigned int varsta{};
    unsigned int numarFapteBune{};
    vector<shared_ptr<Jucarie>>jucarii;


public:
    Copil() = default;
    virtual ~Copil() = default;
    Copil(string _nume,string _prenume, string _adresa, unsigned int _varsta, unsigned int _numarFapteBune, vector<shared_ptr<Jucarie>> _jucarii);
    Copil(const Copil&) = default;
    Copil &operator=(const Copil&) = default;


    friend istream& operator>>(istream& in, Copil& copil);
    friend ostream& operator<<(ostream& out, const Copil& copil);

    virtual void read(istream& in);
    virtual void print(ostream& out) const;

    const string &getNume() const;

};

int Copil::static_idCopil = 0;


Copil::Copil(string _nume, string _prenume, string _adresa, unsigned int _varsta, unsigned int _numarFapteBune,
             vector<shared_ptr<Jucarie>> _jucarii) : idCopil(++static_idCopil){




    this->nume = _nume;
    this->prenume = _prenume;
    this->adresa = _adresa;
    this->varsta = _varsta;
    this->numarFapteBune = _numarFapteBune;
    this->jucarii = _jucarii;


}

void Copil::read(istream &in) {
    cout << "Nume: ";
    in >> nume;

    cout << "Prenume: ";
    in >> prenume;

    cout << "Adresa: ";
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in, adresa);

    cout << "Varsta: ";
    in >> varsta;

    cout << "Fapte Bune: ";
    in >> numarFapteBune;

    for (int i = 0; i < numarFapteBune; i++) {
        shared_ptr<Jucarie> tempJucarie;
        unsigned int option, conditieCitire = 0;

        while (conditieCitire == 0) {
            cout << "Tip Jucarie( 1- clasica , 2 -educativa, 3-electronica, 4- moderna) : ";
            cin >> option;
            conditieCitire = 1;
            try {
                if (option < 1 || option > 4) {
                    throw option;
                }
                switch (option) {
                    case 1: {
                        tempJucarie = make_shared<JucarieClasica>();
                        break;
                    }
                    case 2: {
                        tempJucarie = make_shared<JucarieEducativa>();
                        break;
                    }
                    case 3: {
                        tempJucarie = make_shared<JucarieElectronica>();
                        break;
                    }
                    case 4: {
                        tempJucarie = make_shared<JucarieModerna>();
                        break;
                    }
                }
                tempJucarie->read(cin);
                jucarii.push_back(tempJucarie); }

                catch (...) {
                    cout << "Eroare: Optiune invalida \n";
                    conditieCitire = 0;
                }
            }

    }
}

void Copil::print(ostream &out) const {
    out<< "ID: " << idCopil << "\n";
    out << "Nume si prenume: " << nume << " " << prenume << "\n";
    out<< "Adresa: " << adresa << "\n";
    out<<"Varsta: " << varsta << "\n";
    out<< "Numar fapte bune: " << numarFapteBune << "\n";
    out<< "Jucarii:\n" ;
    for (auto &jucarie: jucarii){
        jucarie->print(out);
    }
}

istream &operator>>(istream &in, Copil &copil) {
    copil.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Copil &copil) {
    copil.print(out);
    return out;
}

const string &Copil::getNume() const {
    return nume;
}


class CopilCuminte : public Copil {
private:
    int numarDulciuri{};

public:
    CopilCuminte() = default;
    ~CopilCuminte() override = default;
    CopilCuminte(string _nume, string _prenume, string _adresa, unsigned int _varsta, unsigned int _numarFapteBune,
                 vector<shared_ptr<Jucarie>> _jucarii, int numarDulciuri);

    CopilCuminte(const CopilCuminte&) = default;
    CopilCuminte &operator=(const CopilCuminte&) = default;


    void read(istream& in) override;
    void print(ostream& out) const override;


};

CopilCuminte::CopilCuminte(string _nume, string _prenume, string _adresa, unsigned int _varsta,
                           unsigned int _numarFapteBune, vector<shared_ptr<Jucarie>> _jucarii, int numarDulciuri)
                           : Copil(_nume,_prenume,_adresa,_varsta,_numarFapteBune,_jucarii){

    this->numarDulciuri = numarDulciuri;
}

void CopilCuminte::read(istream &in) {
    cout << "Nume: ";
    in >> nume;

    cout << "Prenume: ";
    in >> prenume;

    cout << "Adresa: ";
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(in, adresa);

    cout << "Varsta: ";
    in >> varsta;

    cout << "Fapte Bune: ";
    in >> numarFapteBune;

    cout<<"Numar dulciuri: ";
    in>>numarDulciuri;

//    while(numarFapteBune < 10) {
//        cout << "Numar fapte bune gresit !";
//            cout<<"Numar fapte bune: ";
//            in>>numarFapteBune;
//    }

    for (int i = 0; i < numarFapteBune; i++) {
        shared_ptr<Jucarie> tempJucarie;
        unsigned int option, conditieCitire = 0;

        while (conditieCitire == 0) {
            cout << "Tip Jucarie( 1- clasica , 2 -educativa, 3-electronica, 4- moderna) : ";
            cin >> option;
            conditieCitire = 1;
            try {
                if (option < 1 || option > 4) {
                    throw option;
                }
                switch (option) {
                    case 1: {
                        tempJucarie = make_shared<JucarieClasica>();
                        break;
                    }
                    case 2: {
                        tempJucarie = make_shared<JucarieEducativa>();
                        break;
                    }
                    case 3: {
                        tempJucarie = make_shared<JucarieElectronica>();
                        break;
                    }
                    case 4: {
                        tempJucarie = make_shared<JucarieModerna>();
                        break;
                    }
                }
                tempJucarie->read(cin);
                jucarii.push_back(tempJucarie); }

            catch (...) {
                cout << "Eroare: Optiune invalida \n";
                conditieCitire = 0;
            }
        }

    }
}


void CopilCuminte::print(ostream &out) const {
    Copil::print(out);
    out<<"Numar dulciuri: ";
    out<<numarDulciuri;
}

class CopilNeastamparat: public Copil {
private:
int numarCarbuni{};

public:
CopilNeastamparat() = default;
~CopilNeastamparat() override = default;
CopilNeastamparat(string _nume, string _prenume, string _adresa, unsigned int _varsta, unsigned int _numarFapteBune,
        vector<shared_ptr<Jucarie>> _jucarii, int numarCarbuni);

CopilNeastamparat(const CopilNeastamparat&) = default;
CopilNeastamparat &operator=(const CopilNeastamparat&) = default;


void read(istream& in) override;
void print(ostream& out) const override;


};

CopilNeastamparat::CopilNeastamparat(string _nume, string _prenume, string _adresa, unsigned int _varsta,
                                     unsigned int _numarFapteBune, vector<shared_ptr<Jucarie>> _jucarii,
                                     int numarCarbuni) :Copil(_nume,_prenume,_adresa,_varsta,_numarFapteBune,_jucarii) {


    this->numarCarbuni = numarCarbuni;
}

void CopilNeastamparat::read(istream &in) {
    Copil::read(in);

    cout<<"Numar carbuni: ";
    in>> numarCarbuni;
}

void CopilNeastamparat::print(ostream &out) const {
    Copil::print(out);
    cout<<"Numar carbuni: "<< numarCarbuni << "\n";
}



class Meniu{
private:
    static Meniu* instance;
    Meniu() = default;
    vector<shared_ptr<Copil>> copii;

public:
    ~Meniu() = default;
    static Meniu* getInstance();

    //Functii:

    void meniu();
    void adaugareCopii();
    void afisareCopii();
    void cautaCopil(string numeCopil);

};



Meniu* Meniu::instance = nullptr;

Meniu *Meniu::getInstance() {
    if (instance == nullptr){
//        cout<<"Am primit memorie! ";
        instance = new Meniu();
    }
    return instance;
}

void Meniu::meniu() {

    cout<<"-----------------------------------\n";
    cout<<"\tMENIU\tALEGETI O OPTIUNE:\n";
    cout<<"1. CITIRE COPII \n";
    cout<<"2. AFISARE COPII \n";
    cout<<"3. CAUTARE COPIL \n";
    cout<<"0. IESIRE \n";
    cout<<"-----------------------------------\n";

}



void Meniu::adaugareCopii() {
    unsigned int numarCopii;
    cout<<"Numarul de copii este: ";
    cin>> numarCopii;

    for (int i = 0; i < numarCopii; ++i) {
        unsigned int option,conditieCitire=0;
        shared_ptr<Copil>tempCopil;
        while(conditieCitire==0){
            cout<<"Tip Copil: (1-Cuminte , 2-Neastamparat";
            cin>>option;
            conditieCitire = 1;
            try {
                switch (option){
                    case 1: {
                        tempCopil = make_shared<CopilCuminte>();
                        break;
                    }
                    case 2: {
                        tempCopil = make_shared<CopilNeastamparat>();
                        break;
                    }
                    default: {
                        throw option;
                    }


                }
                tempCopil->read(cin);
                copii.push_back(tempCopil);
            } catch (...){
                cout<<"Optiune invalida !";
                conditieCitire=0;
            }

        }
    }
}



void Meniu::afisareCopii() {


    for (auto &copil : copii){
        copil->print(cout);
    }
}



void Meniu::cautaCopil(string numeCopil) {
    size_t found;
    for( auto &copil : copii)
    {
            found = copil->getNume().find(numeCopil);
            if(found != std::string::npos){
                copil->print(cout);
            }
    }
}

/// pentru ordonare - > tutoriat .


int main(){

    Meniu* meniu = Meniu::getInstance();
//    meniu->meniu();
    meniu->adaugareCopii();
    meniu->afisareCopii();
    cout<<"\n";
    cout<<"-----------------\n";
    meniu->cautaCopil("Ana");


    return 0;
}



