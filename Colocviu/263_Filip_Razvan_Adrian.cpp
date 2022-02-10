/// Filip Razvan Adrian
/// Grupa 263
/// IDE C-lion
/// Tutore Laborator: Deaconu Stefan Eduard

#include <iostream>
#include <vector>
using namespace std;




class PachetClasic {
protected:
    unsigned int nrMese;
    bool cazare; ///(0- Nu, nu se doreste cazare intr-o singura camera /// 1-Da,se doreste cazare intr-o singura camera)
    string listaAlergeni;


public:

    PachetClasic() = default ;
    virtual ~PachetClasic() = default;
    PachetClasic(unsigned int _nrMese,bool _cazare,string _listaAlergeni);  // Constructor parametrizat
    PachetClasic(const PachetClasic&) = default ; // Constructor de copiere
    PachetClasic &operator=(const PachetClasic&) = default; // Operatorul egal

    friend istream& operator>>(istream& in, PachetClasic& pachetClasic);
    friend ostream& operator<<(ostream& out, const PachetClasic& pachetClasic);


    virtual void read(istream& in);
    virtual void print(ostream& out) const;   // Folosim const ca sa evitam orice risc de editare in timpul apelului

};

PachetClasic::PachetClasic(unsigned int _nrMese, bool _cazare, string _listaAlergeni) {

    this->nrMese = _nrMese;
    this->cazare = _cazare;
    this->listaAlergeni = _listaAlergeni;

}

istream &operator>>(istream &in, PachetClasic &pachetClasic) {
    pachetClasic.read(in);
    return in;
}

ostream &operator<<(ostream &out, const PachetClasic &pachetClasic) {
    pachetClasic.print(out);
    return out;
}

void PachetClasic::read(istream &in) {

    cout<<"Cate mese doriti sa aibe animalul dvs? ";
    in>>nrMese;

    cout<<"Doriti ca animalul dvs sa fie cazat singur in camera? (0- Nu, nu se doreste cazare intr-o singura camera /// 1-Da,se doreste cazare intr-o singura camera)";
    in>>cazare;

    cout<<"Specificati lista de posibil alergeni: ";
    in>>listaAlergeni;
}

void PachetClasic::print(ostream &out) const {

    out<<"Mese: " << nrMese <<"\n";
    out<<"Cazare: " << cazare << "\n";
    out<<"Lista alergeni: " << listaAlergeni << "\n";

}


class PachetSportiv : public PachetClasic {
protected:
    unsigned int nrPlimbari;

public:

    PachetSportiv() = default;
    ~PachetSportiv() override = default;
    PachetSportiv(unsigned int _nrMese, bool _cazare, string _listaAlergeni,unsigned int _nrPlimbari);
    PachetSportiv(const PachetSportiv&) = default;
    PachetSportiv &operator=(const PachetSportiv&) = default;


    void read(istream& in) override;
    void print(ostream& out) const override;


};

PachetSportiv::PachetSportiv(unsigned int _nrMese, bool _cazare, string _listaAlergeni, unsigned int _nrPlimbari) : PachetClasic(_nrMese,_cazare,_listaAlergeni) {


    this->nrPlimbari = _nrPlimbari;
}

void PachetSportiv::read(istream &in) {
    PachetClasic::read(in);

    cout<<"Cate plimbari doriti sa aiba animalul dvs? MAXIM 5: ";
    in>>nrPlimbari;
}

void PachetSportiv::print(ostream &out) const {
    PachetClasic::print(out);

    cout<<"Nr. plimbari : " << nrPlimbari << "\n";
}



class PachetConfort : public PachetClasic{
protected:
    vector<string> activitati;

public:

    PachetConfort() = default;
    ~PachetConfort() override = default;
    PachetConfort(unsigned int _nrMese, bool _cazare, string _listaAlergeni,vector<string> _activitati);
    PachetConfort(const PachetConfort&) = default;
    PachetConfort &operator=(const PachetConfort&) = default;

    void read(istream& in) override;
    void print(ostream& out) const override;

};

PachetConfort::PachetConfort(unsigned int _nrMese, bool _cazare, string _listaAlergeni,vector<string> _activitati ):PachetClasic(_nrMese,_cazare,_listaAlergeni) {

    this->activitati = _activitati;
}

void PachetConfort::read(istream &in) {
    PachetClasic::read(in);

    int activitate = 0;
    int numarActivitati = 0;

    cout<<"Alegeti ce activitati doriti pe durata cazarii: (MAXIM 2)";
    cout<<"1. Spalare \t 2. Periere \t 3. Joaca \t 4. Dresaj \t 5. Socializare \t 6.Nu doresc alte activitati";

    while(numarActivitati < 2 && activitate != 6){
        in>> activitate;
        numarActivitati++;
        switch(activitate) {
            case 1:
                this->activitati.push_back("Spalare");
                break;
            case 2:
                this->activitati.push_back("Periere");
                break;
            case 3:
                this->activitati.push_back("Joaca");
                break;
            case 4:
                this->activitati.push_back("Dresaj");
                break;
            case 5:
                this->activitati.push_back("Socializare");
                break;
            default:
                break;
        }
    }
}

void PachetConfort::print(ostream &out) const {
    PachetClasic::print(out);

    for (auto &activitate : activitati)
        out<<"Activitati: " << activitate << "\n";
}



class PachetVIP :public PachetClasic {
    vector<string> activitati;
    unsigned int nrPlimbari;
    string orePlimbare;
    unsigned int durata; //IN MINUTE
    unsigned int cateActivitati;

public:
    PachetVIP() = default;
    ~PachetVIP() override = default;
    PachetVIP(unsigned int _nrMese, bool _cazare, string _listaAlergeni,vector<string> _activitati, unsigned int _nrPlimbari , string _orePlimbare, unsigned int _durata,unsigned int _cateActivitati);
    PachetVIP(const PachetVIP&) = default;
    PachetVIP &operator=(const PachetVIP&) = default;

    void read(istream &in) override;

    void print(ostream &out) const override;



};

PachetVIP::PachetVIP(unsigned int _nrMese, bool _cazare, string _listaAlergeni, vector<string> _activitati,
                     unsigned int _nrPlimbari, string _orePlimbare, unsigned int _durata,
                     unsigned int _cateActivitati) :PachetClasic(_nrMese,_cazare,_listaAlergeni){

    this->activitati = _activitati;
    this->nrPlimbari = _nrPlimbari;
    this->orePlimbare = _orePlimbare;
    this->durata = _durata;
    this->cateActivitati = _cateActivitati;


}

void PachetVIP::read(istream &in) {
    PachetClasic::read(in);
    int activitate = 0;
    int numarActivitati = 0;

    cout<<"Alegeti ce activitati doriti pe durata cazarii: (MAXIM 2)";
    cout<<"1. Spalare \t 2. Periere \t 3. Joaca \t 4. Dresaj \t 5. Socializare \t 6.Nu doresc alte activitati";

    while(numarActivitati < 2 && activitate != 6){
        in>> activitate;
        numarActivitati++;
        switch(activitate) {
            case 1:
                this->activitati.push_back("Spalare");
                break;
            case 2:
                this->activitati.push_back("Periere");
                break;
            case 3:
                this->activitati.push_back("Joaca");
                break;
            case 4:
                this->activitati.push_back("Dresaj");
                break;
            case 5:
                this->activitati.push_back("Socializare");
                break;
            default:
                break;
        }
    }
    cout<<"Cate plimbari doriti sa aiba animalul dvs? MAXIM 5: ";
    in>>nrPlimbari;

    cout<< "Ore plimbare preferate:";
    in.get();
    getline(in,orePlimbare);

    cout<<"durata: (IN MINUTE)";
    in>>durata;

    cout<<"cate activitati?";
    in>>cateActivitati;


}

void PachetVIP::print(ostream &out) const {
    PachetClasic::print(out);

    for (auto &activitate : activitati)
        out<<"Activitati: " << activitate << "\n";


    cout<<"Nr. plimbari : " << nrPlimbari << "\n";

    cout<<"Ore plimbare preferate: " <<orePlimbare << "\n";
    cout<<"Durata in minute: "<< durata<< "\n";
    cout<<"Cate activitati? "<<cateActivitati<< "\n";

}


class Client {
protected:
    string nume;
    unsigned int numarTelefon;
    string adresa;
    unsigned int cnp;

public:
    Client() = default;
    virtual ~Client() = default;
    Client(string _nume, unsigned int _numarTelefon, string _adresa, unsigned int _cnp);
    Client(const Client&) = default;
    Client &operator=(const Client&) = default;


    friend istream& operator>>(istream& in, Client& client);
    friend ostream& operator<<(ostream& out, const Client& client);

    virtual void read(istream& in);
    virtual void print(ostream& out) const;
};

Client::Client(string _nume, unsigned int _numarTelefon, string _adresa, unsigned int _cnp) {

    this->nume = _nume;
    this->numarTelefon = _numarTelefon;
    this->adresa = _adresa;
    this->cnp = _cnp;
}

istream &operator>>(istream &in, Client &client) {
    client.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Client &client) {
    client.print(out);
    return out;
}

void Client::read(istream &in) {
    cout<<"Nume: ";
    in>>nume;

    cout<<"Numar Telefon: ";
    in>>numarTelefon;

    cout<<"adresa:";
    in>>adresa;

    cout<<"CNP:";
    in>>cnp;
}

void Client::print(ostream &out) const {

    cout<<"Nume: "<<nume<<"\n";
    cout<<"Numar telefon" << numarTelefon <<"\n";
    cout<<"Adresa: "<<adresa <<"\n";
    cout<<"CNP:" <<cnp<<"\n";
}



class Animal {
protected:

    string nume;
    unsigned int varsta;
    string rasa;
    unsigned int codCazare;

public:
    Animal() = default;
    virtual ~Animal() = default;
    Animal(string _nume,unsigned int _varsta, string _rasa, unsigned int _codCazare);
    Animal(const Animal&) = default;
    Animal &operator=(const Animal&) = default;


    friend istream& operator>>(istream& in, Animal& animal);
    friend ostream& operator<<(ostream& out, const Animal& animal);

    virtual void read(istream& in);
    virtual void print(ostream& out) const;
};

Animal::Animal(string _nume, unsigned int _varsta, string _rasa, unsigned int _codCazare) {

    this->nume = _nume;
    this->varsta = _varsta;
    this->rasa = _rasa;
    this->codCazare = _codCazare;
}

istream &operator>>(istream &in, Animal &animal) {
    animal.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Animal &animal) {
    animal.print(out);
    return out;
}

void Animal::read(istream &in) {
        cout<<"Nume: ";
        in>>nume;

        cout<<"Varsta: ";
        in>>varsta;

        cout<<"Rasa: ";
        in>>rasa;

        cout<<"Cod Cazare: ";
        in>>codCazare;
}

void Animal::print(ostream &out) const {

    cout<<"Nume: "<< nume << "\n";
    cout<<"Varsta" <<varsta<<"\n";
    cout<<"Rasa" << rasa << "\n";
    cout<<"Cod cazare"<<codCazare << "\n";
}


class Meniu{                ///PRELUAT DIN LABORATORUL 10 si adaptat
private:
    static Meniu* instance;
    Meniu() = default;

public:
    ~Meniu() = default;
    static Meniu* getInstance();

    //Functii:
    void meniu();
    void adaugareFormular();

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

    cout<<"-----------------------------------\n";          //Din pacate meniul nu este finalizat.
    cout<<"\tMENIU\tALEGETI O OPTIUNE:\n";
    cout<<"1. ADAUGARE ANIMAL \n";
    cout<<"2. ADAUGARE CLIENT \n";
    cout<<"3. AFISASRE ANIMAL \n";
    cout<<"4. AFISASRE CLIENT \n";
    cout<<"0. IESIRE \n";
    cout<<"-----------------------------------\n";

}

int main(){
    Meniu* meniu = Meniu::getInstance();
   meniu->meniu();

                                            /// VERIFICARE FIECARE CLASA DACA CITESTE / SCRIE CORECT
   cout<<"Adaugare si afisare animal";
    Animal a;
    cin>>a;
    cout<<a;
    cout<<"-------------------------------------------";
    cout<<"Adaugare si afisare client";
    Client c;
    cin>>c;
    cout<<c;

    cout<<"-------------------------------------------";
    cout<<"Adaugare si afisare PachetVIP";
    PachetVIP VIP;
    cin>>VIP;
    cout<<VIP;









}

