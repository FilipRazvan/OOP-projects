#include <iostream>

using namespace std;

const double PI = 3.1415;


// Pine, Cedar and ChristmasTree TODO Inheritance

// Vom alege un exemplu mai putin folosit.
// Am cunoscut de curand un antreprenor care si-a deschis o plantatie de conifere.
// Deocamdata cultiva trei tipuri de conifere:
// 1. Pine              (pin)
// 2. Cedar             (cedru)
// 3. ChristmasTree     (locul cadourile)

// Fiecare conifer, indiferent de gen, are o inaltime (m), circumferinta la nivelul solului (cm),
//                                     iar acele lui pot fi ascutite sau plate.
//
/*
// Deoarece antreprenorul vrea sa limiteze transportul lemnelor se ocupa on-site de transformarea lor in produse vandabile:
// 1. CedarOil
// 2. PineLogs
// 3. PineGrillTimber
// 4. ChristmasTreePack  ->  in care antreprenorul include, cu toata bunatatea (si din motive de marketing) si o stea aurie.
*/

// Pentru a simplifica procesul, vom crea o clasa Product care va retine tipul produsului (1, 2, 3, sau 4).
// Primul scop este sa creem cele 4 clase (clasa de baza, dar si trei clase derivate), astfel incat urmatorul main sa ruleze fara erori:

enum NeedleShape { // lista de constante
    SHARP,  // 0
    FLAT,    // 1
    DUSTER_SHAPED,    // 2
};
//// same as:
//const int SHARP = 0;
//const int FLAT = 1;
// Obliga compilatorul sa accepte fie valoarea 0, fie valoarea 1

// TODO Cand lucram, noi oricum le vom pune protected, ca sa ne usuram munca :))

class Conifer {
private:
    // in clasele derivate pot fi folosite numai cu ajutorul getterelor, setterelor, si a metodelor publice
    double height, diameter;
protected:
    // devine private in clasa care a mostenit-o
    NeedleShape shape;

public:

    Conifer(double height, double diameter, NeedleShape shape) : height(height), diameter(diameter), shape(shape) {}

    Conifer() : Conifer(0, 0, SHARP) {}

    // Alt+Insert
    double getHeight() const {
        return height;
    }

    void setHeight(double height) {
        Conifer::height = height;
    }

    double getDiameter() const {
        return diameter;
    }

    void setDiameter(double diameter) {
        Conifer::diameter = diameter;
    }

    // metoda simpla
    string description() {
        return "This is a Conifer";
    }

    friend ostream &operator<<(ostream &os, const Conifer &conifer) {
        os << "height: " << conifer.height << " diameter: " << conifer.diameter << " shape: " << conifer.shape;
        return os;
    }
    // functie pret
    double evaluarePret() {
        double pret = 2.5 * (PI* (diameter/200)*(diameter/200))*height;
        return pret;
    }

};

class Pine : public Conifer {
    // TODO  Alt+Insert  open the "Generate" context menu
private:
    int notaRezistenta;
public:
    // constructorii din derivate, au nevoie de cei din parinti, cel mai des macar de cel fara parametri
    Pine() : notaRezistenta(0) {}

    // constructorul cu toti parametri:
    Pine(double height, double diameter, NeedleShape shape,
         int notaRezistenta) : Conifer(height, diameter, shape),
                               notaRezistenta(notaRezistenta) {}

    // metoda simpla
    //  "specializare" a metodei din parinte (formal.. overriding = suprascriere)
    string description() {
        return "This is a Pine";
    }

    // operator<<
    friend ostream &operator<<(ostream &os, const Pine &pine) {
        os << (Conifer) pine << " notaRezistenta: " << pine.notaRezistenta;
        return os;
    }
    // functie pret
    double evaluarePret() {
        return 1.2* Conifer :: evaluarePret();
    }

};

class Cedar : public Conifer {
private:
    bool ulei;
public:
    Cedar() : ulei(false) {}

    Cedar(double height, double diameter, NeedleShape shape, bool ulei) :
            Conifer(height, diameter, shape), ulei(ulei) {}

    string description() {
        return "This is a Cedar";
    }

    friend ostream &operator<<(ostream &os, const Cedar &cedar) {
        os << (Conifer)cedar << " ulei: " << cedar.ulei;
        return os;
    }
    // functie pret
    double evaluarePret() {
        return 1.1* Conifer :: evaluarePret();
    }

};


class ChristmasTree : public Conifer {
private:
    string star;

public:
    ChristmasTree() : star("blank") {}

    ChristmasTree(double height, double diameter, NeedleShape shape , string star) :
        Conifer(height,diameter,shape), star(star){}

    string description()
    {
        return "This is a Christmas Tree";
    }

    friend ostream &operator<<(ostream &os, const ChristmasTree &ChristmasTree) {
        os << (Conifer) ChristmasTree << " Star_Color: " << ChristmasTree.star;
        return os;
    }
    double evaluarePret() {
        return 1.6* Conifer :: evaluarePret();
    }
};

// 1. implement the Cedar similarly to the Pine

int main() {
    Conifer c;
    // Part one: implementation using inheritance (constructors, setters, and getters)
    /*
     * Primul scop al mostenirii este sa putem refolosi o cantitate cat mai mare de cod.
     * Cum ar putea sa putem refolosi inclusiv constructorii, <<, si orice metode in clase care seama foarte mult?
     *  (e.g. Pine, Cedar, ChristmasTree?)
     */
    Conifer t{5, 34, FLAT};         // inaltime in m, diametru in cm, tipul acelor
    Pine t1{3, 28, SHARP, 7};       // inaltime in m, diametru in cm, tipul acelor  +  nota rezistentei, intre 1 si 10
    Cedar t2{3.2, 25, FLAT, true};  // inaltime in m, diametru in cm, tipul acelor  +  daca produce eficient ulei
    ChristmasTree t3{3, 28, SHARP, "yellow"}; // impreuna cu un brad se vinde si o stea de o anumita *culoare*


    //    cout << "Octeti Conifer: " << sizeof(t) << endl;
//    cout << "Octeti Pine: " << sizeof(t1) << endl;

    // Part two: metode specializate (overriding during inheritance)


//    cout << t.description() << endl; // prints "This is a Conifer"
//    cout << t1.description() << endl; // prints "This is a Pine"
//    cout << t2.description() << endl; // prints "This is a Cedar"
//    cout << t3.description() << endl; // prints "This is a Christmas Tree"

    // Part three:  cum folosim operator<< din parinte pt a nu repeta codul :D
//    cout << t << endl; // height: 5 diameter: 34 shape: 1
//    cout << t1 << endl; // height: 3 diameter: 28 shape: 0 notaRezistenta: 7
//    cout << t2 << endl; // height: 3 diameter: 28 shape: 0 ulei: 1
      cout << t3 <<endl;
    // TODO observatii:
    //      1. daca implementam << pentru parinte, deja merge pentru orice clase derivate
    //            formal... are loc object slicing, adica din Pine pastrezi doar partea de Conifer
    //      2. asta inseamna ca noi ne putem uita la un obiect Pine ca la un Conifer (pt ca Pine este un Conifer):
 //   Conifer conifer = t1; // copieaza doar bytii care corespund cu un Conifer
//    cout << conifer << endl;


    //  Part four:
    //  metodele membre: sa spunem ca vom avea metode de baza
    //                   double evaluareProfit();            care are efecte diferite in functie de tipul de conifer
    //  1. pentru conifer, pur si simplu calculeaza un pret de baza, care va fi 2.5 * volumul lemnos in m (aria bazei * inaltime)
    //  2. pentru un pin, valoarea va fi de 1.2 * pretul de baza (calculat cu ajutorul metodei mostenite)
    //  3. pentru un cedru, valoarea va fi de 1.1 * pretul de baza (calculat cu ajutorul metodei mostenite) + 50 bani pentru fiecare 10 centimetri din inaltime
    //  4. pentru un pom de Craciun, valoarea va fi de 1.6 * pretul de baza (calculat cu ajutorul metodei mostenite)

//    cout << t.evaluarePret() << endl;
//    cout << t1.evaluarePret() << endl;

}

//// exemplu metoda membra:
//class Produs {
//private:
//    double pretBaza;
//public:
//    double pret() {
//        return pretBaza;
//    }
//};
//
//class ProdusRedus20 : public Produs {
//public:
//    double pret() {
//        return 0.8 * Produs::pret();
//    }
//};


// PiatraPretioasa






