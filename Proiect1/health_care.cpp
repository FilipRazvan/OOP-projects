//
// Created by Razvan on 08.11.2021.
//

#include "HealthPackage.h"
#include <fstream>
#include <iostream>

using namespace std;



// Test de memorie

// vom folosi cin si cout:

// vom folosi string-uri:

// vom folosi std


// TODO 404 class not found, deoarece veti folosi fisiere:
//  Click-Dreapta folder proiect -> New -> C++ CLass (campul Type trebuie sa fie .cpp/.h)

int main() {

    ofstream file("facturi.txt");


    // un pachet gol, dar care poate fi folosit cu cin si cout
    HealthPackage empty;

    // un pachet pentru un client de 23 ani,
    // care a mai cumparat si in trecut, cu valabilitate de 3 luni
    HealthPackage client(23, true, 3, false); // ultimul false inseaman ca nu este pensionar
    HealthPackage happyClient(47, false, 3, false);
    HealthPackage curiousClient(77, false, 12, true); // chiar si o persoana care n-a cunoscut pana la varsta de 77 ani compania, are incredere in noi :)
    HealthPackage clients[] = {client, happyClient, curiousClient};
//    for (HealthPackage package : clients) {
//        cout<<"Pretul este:" << package.getPret()<<"\n"; // va afisa 632.792 751.4405 1885
//    }
//
//
      cin >> empty;
//    cout << empty;
//    cout << empty.getPret();
    int nr=1;
    for (HealthPackage package : clients) {
        file<<"FACTURA"<< nr++<< "\n Pretul este:" << package.getPret()<<"\n";
    }
    file<<"FACTURA"<<nr++<<"\n"<<empty;
    file<<"Pretul cerut este:"<<empty.getPret();

    file.close();
    return 0;
}

// TODO BTW, fisierele cu codul driver (functia main()) se scriu cu lowercase sau snake_case pt a nu se ciocni in denumiri
//  cu fisierele pentru o clasa (spre exemplu n-am fi putut numi acest fisier HealthPackage.cpp)



