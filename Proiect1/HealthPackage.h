//
// Created by Razvan on 08.11.2021.
//
#include <iostream>
#ifndef CPP_HEALTHPACKAGE_H
#define CPP_HEALTHPACKAGE_H
using namespace std;

class HealthPackage {
private:
    int varsta;
    bool vechime;
    int valabilitate;
    bool pensionar;
    float pret;
    void computePrice()
    {
        float pret;
        if(this->valabilitate == 1)
            pret = 300;
        else if(this->valabilitate == 3)
            pret= 790.99;
        else if(this->valabilitate == 12)
            pret= 2900;
        else pret = 300;

        float reducere = 0;

        if (this->vechime){
            reducere = 10;
        }
        if (this->varsta < 16)
            reducere = reducere +15;
        if (this->varsta > 16 && this->varsta < 25)
            reducere = reducere + 10;
        if (this->varsta > 25 && this->varsta < 50)
            reducere = reducere + 5;
        if (this->varsta > 50)
            reducere = reducere + 35;

        this->pret =(pret-((reducere/100.00))*pret);
    }

public:
    HealthPackage(){
        this->varsta=0;
        this->vechime=false;
        this->valabilitate=0;
        this->pensionar=false;
        this->pret=0;
    }

//    HealthPackage(): varsta(0), vechime(false), valabilitate(0), pensionar(false) , pret(0)
//    {
//    }

    ~HealthPackage() = default;


//    HealthPackage(int varsta,bool vechime,int valabilitate,bool pensionar){
//        this->varsta=varsta;
//        this->vechime=vechime;
//        this->valabilitate=valabilitate;
//        this->pensionar=pensionar;
//        computePrice();
//    }

    HealthPackage(int varsta,bool vechime,int valabilitate,bool pensionar): varsta(varsta), vechime(vechime), valabilitate(valabilitate), pensionar(pensionar)
    {
        computePrice();
    }

    HealthPackage(const HealthPackage &h)   /// Copy constructor
    {
        varsta = h.varsta;
        vechime = h.vechime;
        valabilitate = h.valabilitate;
        pensionar = h.pensionar;
        pret = h.pret;
    }

    friend istream& operator>>(istream& i, HealthPackage &h);
    friend ostream& operator<<(ostream& out,const HealthPackage &h);

    HealthPackage operator=(const HealthPackage &h){  /// Operatorul =
        if (this != &h) {
            varsta = h.varsta;
            vechime = h.vechime;
            valabilitate = h.valabilitate;
            pensionar = h.pensionar;
            pret = h.pret;
        }
        return *this;
    }



    int getVarsta() const {
        return varsta;
    }

    void setVarsta(int varsta) {
        HealthPackage::varsta = varsta;
    }

    bool isVechime() const {
        return vechime;
    }

    void setVechime(bool vechime) {
        HealthPackage::vechime = vechime;
    }

    int getValabilitate() const {
        return valabilitate;
    }

    void setValabilitate(int valabilitate) {
        HealthPackage::valabilitate = valabilitate;
    }

    bool isPensionar() const {
        return pensionar;
    }

    void setPensionar(bool pensionar) {
        HealthPackage::pensionar = pensionar;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float pret) {
        HealthPackage::pret = pret;
    }


};

istream& operator>>(istream& i, HealthPackage &h)   /// Operator de citire
{
    cout<<"\n(DA=1 , NU=0) Este pensionar? : "; i>>h.pensionar;
    cout<<"\nPe ce perioada? "; i>>h.valabilitate;
    cout<<"\n(DA=1 , NU=0) Are vechime? : "; i>>h.vechime;
    cout<<"\nVarsta: "; i>>h.varsta;
    h.computePrice();
    return i;

}

ostream& operator<<(ostream& out,const HealthPackage &h)   /// Operator de afisare
{
    out<<"Pretul:"<<h.pret<<"\n";
    out<<"(DA=1 , NU=0) Este pensionar?  : "<<h.pensionar<<"\n";
    out<<"Pe ce perioada? "<<h.valabilitate<<"\n";
    out<<"(DA=1 , NU=0) Are vechime? : "<<h.vechime<<"\n";
    out<<"Varsta: "<<h.varsta<<"\n";
    return out;
}

#endif //CPP_HEALTHPACKAGE_H
