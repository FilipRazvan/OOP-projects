#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>

using namespace std;

/// IERARHIE
///Clasa Produs (pret si nume)
///mostenim
//CLASA Music , Player , Sticker
//
//Music - > Vinyl , CD
//Player - > VinylPlayer , CdPlayer

////////////////////////////////////////////////////////////////                CLASA PRODUS

class Produs{
protected:
    float pret;
    string nume;

public:
    Produs() = default;
    virtual ~Produs() = default;
    Produs(float _pret,const string _nume);
    Produs(const Produs&) = default; ///Constructor de copiere default
    Produs &operator=(const Produs&) = default;     ///Operatorul egal


    friend istream& operator>>(istream& in , Produs& produs);
    friend ostream& operator<<(ostream& out ,const Produs& produs);


    virtual void read(istream& in) ;
    virtual void print(ostream& out) const;


};

Produs::Produs(float _pret, const string _nume) {
    this->pret = _pret;
    this->nume = _nume;
}

istream &operator>>(istream &in, Produs &produs) {
    produs.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Produs &produs) {
    produs.print(out);
    return out;
}

void Produs::read(istream &in) {
    cout<<"Nume: ";
    in>>nume;

    cout<<"Pret: ";
    in>>pret;

}

void Produs::print(ostream &out) const {
    out<<"Nume: "<< nume << "\n";
    out<<"Pret: "<< pret << "\n";
}



////////////////////////////////////////////////////////////////                CLASA MUSIC

class Music : public Produs {
protected:
    string autor;
    string titlu;
    unsigned int lungime;

public:
    Music() = default;
    ~Music() override = default;
    Music(float _pret,const string _nume, string _autor, string _titlu, unsigned int _lungime);


    Music(const Music&) = default;
    Music & operator =(const Music&) = default;

    void read(istream& in ) override;
    void print(ostream& out) const override;


};


Music::Music(float _pret, const string _nume, string _autor, string _titlu, unsigned int _lungime):Produs(_pret,_nume) {
    this->autor= _autor;
    this->titlu= _titlu;
    this->lungime = _lungime;
}

void Music::read(istream &in) {
    Produs::read(in);

    cout<<"Autor: ";
    in.get();
    getline(in,autor);
    cout<<"Titlu: ";
    getline(in,titlu);
    cout<<"Lungime: ";
    in>>lungime;
}

void Music::print(ostream &out) const {
    Produs::print(out);

    cout<<"Autor: "<<autor<<"\n";
    cout<<"Titlu: "<<titlu<<"\n";
    cout<<"Lungime: "<<lungime<<"\n";

}


////////////////////////////////////////////////////////////////                CLASA MUSICPLAYER

class MusicPlayer : public Produs{
protected:
    string titlu;
    string cantaret;

public:
    MusicPlayer() = default;
    ~MusicPlayer() override = default;
    MusicPlayer(float _pret,const string _nume, string _titlu,string _cantaret);


    MusicPlayer(const MusicPlayer&) = default;
    MusicPlayer & operator =(const MusicPlayer&) = default;


    void read(istream& in ) override;
    void print(ostream& out) const override;

};

MusicPlayer::MusicPlayer(float _pret, const string _nume, string _titlu, string _cantaret):Produs(_pret,_nume) {
    this->titlu=_titlu;
    this->cantaret=_cantaret;

}

void MusicPlayer::read(istream &in) {
    Produs::read(in);
    in.get();
    cout<<"Titlu: ";
    getline(in,titlu);
    cout<<"Cantaret: ";
    in>>cantaret;
}

void MusicPlayer::print(ostream &out) const {
    Produs::print(out);
    cout<<"Titlu: "<<titlu<<"\n";
    cout<<"Cantaret: "<<cantaret<<"\n";
}

////////////////////////////////////////////////////////////////                CLASA STICKER

class Sticker : public Produs {
protected:
    string extraString;

public:
    Sticker() = default;
    ~Sticker() override = default;
    Sticker(float _pret, const string _nume,string _extraString);


    Sticker(const Sticker&) = default;
    Sticker & operator =(const Sticker&) = default;

    void read(istream& in ) override;
    void print(ostream& out) const override;


};

Sticker::Sticker(float _pret, const string _nume, string _extraString):Produs(_pret,_nume) {
    this->extraString = _extraString;

}

void Sticker::read(istream &in) {
    Produs::read(in);
    cout<<"String: ";
    in>>extraString;
}

void Sticker::print(ostream &out) const {
    Produs::print(out);
    cout<<"Extra String: "<<extraString<<"\n";
}

////////////////////////////////////////////////////////////////                CLASA VINYL

class Vinyl : public Music {
protected:


public:
    Vinyl() = default;
    ~Vinyl() override = default;
    Vinyl(float _pret,const string _nume, string _autor, string _titlu, unsigned int _lungime);


    Vinyl(const Vinyl&) = default;
    Vinyl & operator =(const Vinyl&) = default;

    void read(istream& in ) override;
    void print(ostream& out) const override;
};

void Vinyl::read(istream &in) {
    Music::read(in);
}

void Vinyl::print(ostream &out) const {
    Music::print(out);
}

Vinyl::Vinyl(float _pret, const string _nume, string _autor, string _titlu, unsigned int _lungime) : Music(_pret,
                                                                                                              _nume,
                                                                                                              _autor,
                                                                                                              _titlu,
                                                                                                              _lungime) {

}

////////////////////////////////////////////////////////////////                CLASA CD

class Cd : public Music{
protected:

public:

    Cd() = default;
    ~Cd() override = default;
    Cd(float _pret,const string _nume, string _autor, string _titlu, unsigned int _lungime);


    Cd(const Cd&) = default;
    Cd & operator =(const Cd&) = default;

    void read(istream& in ) override;
    void print(ostream& out) const override;

};

void Cd::read(istream &in) {
    Music::read(in);
}

void Cd::print(ostream &out) const {
    Music::print(out);
}

Cd::Cd(float _pret, const string _nume, string _autor, string _titlu, unsigned int _lungime) : Music(_pret, _nume,
                                                                                                        _autor, _titlu,
                                                                                                        _lungime) {

}
////////////////////////////////////////////////////////////////                CLASA VinylPlayer

class VinylPlayer : public MusicPlayer{
protected:

public:
    VinylPlayer() = default;
    ~VinylPlayer() override = default;
    VinylPlayer(float _pret,const string _nume, string _titlu,string _cantaret);

    VinylPlayer(const VinylPlayer&) = default;
    VinylPlayer & operator =(const VinylPlayer&) = default;

    void read(istream& in ) override;
    void print(ostream& out) const override;
};

void VinylPlayer::read(istream &in) {
    MusicPlayer::read(in);
}

void VinylPlayer::print(ostream &out) const {
    MusicPlayer::print(out);
}

VinylPlayer::VinylPlayer(float _pret, const string _nume, string _titlu, string _cantaret) : MusicPlayer(_pret,
                                                                                                            _nume,
                                                                                                            _titlu,
                                                                                                            _cantaret) {

}

////////////////////////////////////////////////////////////////                CLASA CDPLAYER

class CdPlayer : public MusicPlayer{
protected:


public:
    CdPlayer() = default;
    ~CdPlayer() override = default;
    CdPlayer(float _pret,const string _nume, string _titlu,string _cantaret);

    CdPlayer(const CdPlayer&) = default;
    CdPlayer & operator =(const CdPlayer&) = default;

    void read(istream& in ) override;
    void print(ostream& out) const override;

};

void CdPlayer::read(istream &in) {
    MusicPlayer::read(in);
}

void CdPlayer::print(ostream &out) const {
    MusicPlayer::print(out);
}

CdPlayer::CdPlayer(float _pret, const string _nume, string _titlu, string _cantaret) : MusicPlayer(_pret, _nume,
                                                                                                      _titlu,
                                                                                                      _cantaret) {

}
                                                                                                                                            /// Am terminat ierarhia claselor

class MusicStore {
private:
    vector<Produs*>products;
    static MusicStore *instance;
    vector<shared_ptr<Produs>>produse;

    //Private constructor so that no objects can be created.
    MusicStore() {
    produse.clear();
    }

public:
    ~MusicStore() = default;
    static MusicStore *getInstance() {
        if (!instance)
            instance = new MusicStore;
        return instance;

    }

    ///functii
    void meniu();
    void adaugaProdus();
    void afisareProduse();
    void addProduct();
    void addProduct(Produs &p);
    void adauga(){                                                                                              /// Adaugat 5 produse de tipuri diferite din care sa existe minim 3 perechi compatibile.
        Produs* product = new Cd(20,"Song","Mircea","Onlyforyou",200);
        products.push_back(product);
        product = new Vinyl(30,"Vinyl","Mircea","Onlyforyou",250);
        products.push_back(product);
        product = new Sticker(30,"sticker","Onlyforyou");
        products.push_back(product);
        product = new VinylPlayer(20,"Player","Onlyforyou","Andrei");
        products.push_back(product);
        product = new CdPlayer(25,"Title","Melodie","Andrei");
        products.push_back(product);
    }
    void isCompatibleWith(Produs *other);
};
MusicStore *MusicStore::instance = nullptr;



void MusicStore::adaugaProdus() {

    unsigned int nrProduse;
    cout<<"Cate produse doriti sa adaugati? \t";
    cin>>nrProduse;

    for(int i=0; i<nrProduse; i++)
    {
        unsigned int option, conditieCitire = 0,option2,option3;
        shared_ptr<Produs> tempProdus;
        while (conditieCitire ==0){
            cout<<"Tip Produs (1-Music , 2-MusicPlayer , 3-Sticker) \n";
            cin>>option;
            conditieCitire = 1;

            try{
                switch(option){
                    case 1: {
                        cout<<"Ce fel de Music?" << "    " << "1. Vinyl "<< " 2. CD\n"; cin>>option2;
                            if(option2==1)
                        tempProdus = make_shared<Cd>();
                            else if (option2==2)
                                tempProdus = make_shared<Vinyl>();  else cout<<"OPTIUNE INTRODUSA GRESIT";
                        break;
                    }
                    case 2: {
                        cout<<"Ce fel de MusicPlayer?" << "    " << "1. VinylPlayer "<< " 2. CDPlayer\n"; cin>>option3;
                        if(option3==1)
                            tempProdus = make_shared<VinylPlayer>();
                        else if (option3==2)
                            tempProdus = make_shared<CdPlayer>();  else cout<<"OPTIUNE INTRODUSA GRESIT";
                        break;
                    }
                    case 3: {
                        tempProdus = make_shared<Sticker>();
                        break;
                    }
                }
                tempProdus->read(cin);
                produse.push_back(tempProdus);
            } catch(...){
                cout<<"eroare: Optiune invalida\n";
                conditieCitire=0;
            }

        }

    }

}
void MusicStore::meniu() {
    int optiune0;
    cout<<"------------------------------------\n";
    cout<<"\tMENIU\tALEGETI O OPTIUNE:\n";
    cout<<"1. ADAUGA PRODUS\n";
    cout<<"0. IESIRE\n";
    cout<<"Introduceti optiune: ";
    cin>>optiune0;
    if(optiune0 == 1)
        this->adaugaProdus();
    else
       exit(0);

}

void MusicStore::afisareProduse(){
    int i=1;
    for(auto produs : produse){
        cout<<"PRODUSUL NR " <<i<<"\n";
        produs->print(cout);
        i=i+1; cout<<"\n\n";
    }
}

void MusicStore::isCompatibleWith(Produs* other) {

}

void MusicStore::addProduct() {

    string produs;
    cout<< "Produs: " ;
    cin.get();
    getline(cin,produs);
    try{
        Produs *p;
        if (produs == "Music")
        {
            p = new Music();

        }
        if (produs == "MusicPLayer")
        {
            p = new MusicPlayer();

        }
        if (produs == "Sticker")
        {
            p = new Sticker();

        }
        if (produs == "Vinyl")
        {
            p = new Vinyl();

        }
        if (produs == "Cd")
        {
            p = new Cd();

        }
        if (produs == "VinylPlayer")
        {
            p = new VinylPlayer();

        }
        if (produs == "CdPlayer")
        {
            p = new CdPlayer();

        }
        else
            throw 1;
        cin>>*p;
        products.push_back(p);
    }
    catch(int x)
    {
        cout<< " Invalid product";
    }


}

void MusicStore::addProduct(Produs &p) {

    Sticker *s = dynamic_cast<Sticker *>(&p);
    Vinyl *v = dynamic_cast<Vinyl *>(&p);
    VinylPlayer *vl = dynamic_cast <VinylPlayer *> (&p);
    Cd *c = dynamic_cast <Cd *>(&p);
    CdPlayer *cdp = dynamic_cast <CdPlayer *> (&p);


    if (s){
        cout<< "Clasa Sticker";
    }
   else if (v){
        cout<< "Clasa Vinyl";
    }
    else if (vl){
        cout<<"Clasa VinylPlayer";
    }
    else if(c){
        cout<<"Clasa Cd";
    }
    else if(cdp){
        cout<<"Clasa CdPlayer";
    }
    products.push_back(&p);

}


int main () {
    MusicStore* musicStore = MusicStore::getInstance();
    musicStore->meniu();
    cout<<"----------------------------------- Afisare Produse ------------------\n";
    musicStore->afisareProduse();
    Produs *p = new Cd();
    musicStore->addProduct(*p);


    return 0;
}