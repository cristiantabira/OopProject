#include <string>

#include <iostream>

#include "Manager.h"

#include "BiletNominal.h"

using namespace std;
int main() {

    cout << "=====================================MENIU===================================";
    cout << endl;
    cout << "==============================-1-Afisare Evenimente==========================";
    cout << endl;
    cout << "==============================-2-Cumparare bilet=============================";
    cout << endl;
    cout << "==============================-3-Verificare bilet============================";
    cout << endl;
    bool valid = false;
    Manager m;
    //Eveniment(string denumire, string data, string locatie, float ora, int durata, int nr_bilete, int nr_zone, Bilet * bilet, const string * zone);
    Bilet b1;
    Bilet b2;
    Bilet b3;
    Bilet* biletsteaua = new Bilet[4];
    biletsteaua[0] = b1;
    biletsteaua[1] = b2;
    biletsteaua[2] = b3;
    string* zoneMeci = new string[3];
    zoneMeci[0] = "Tribuna";
    zoneMeci[1] = "Peluza1";
    zoneMeci[2] = "Peluza2";
    Eveniment ev1("SteauavsDinamo", "2023-02-07", "Arena-Nationala", 17.30, 2, 3, 3, biletsteaua, zoneMeci);
    Eveniment ev2;
    Eveniment ev3;
    Eveniment ev4;
    m.evenimente[0] = ev1;
    int idx;
    while (!valid) {
        int optiune;
        cout << "Optiunea dumneavoastra este: ";
        cin >> optiune;

        switch (optiune) {
        case 1:
            cout << "Acestea sunt toate evenimentele noastre:" << endl;
            valid = true;
            //m.AfisareEv();

            break;
        case 2:
            cout << "Ati ales sa cumparati un bilet" << endl;
            valid = true;
            break;
        case 3:
            cout << "Ati ales verificarea biletului" << endl;
            cout << endl << "Alegeti ID-ul pe care doriti sa il verificati: ";
            do {
                cin >> idx;
            } while (idx < 0 || idx > 999999);
            /*if (m.verificareID(idx))
                cout << "Id valid";
            else cout << "Id invalid";*/
            valid = true;
            break;
        default:
            cout << "Optiune invalida, va rugam sa introduceti o optiune valida(1/2/3)." << endl;
            break;
        }
    }

    //Eveniment e("Untold","10.02","Cluj-Napoca",15.30,3);
    //e.setData("2002-01-07");
    //cout << e;
    //Eveniment a;
    //Bilet b;
    //cout << endl<<b<<endl;
    //Bilet c;
    //cout << c << endl;
    ////cin >> a;
    //cout << endl << a;
}