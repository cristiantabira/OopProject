#include "Manager.h"

#include<iostream>
using namespace std;
int Manager::nr_ev = 4;
Manager::Manager() {
    evenimente = new Eveniment[1];
    Eveniment a;
    evenimente[0] = a;
}
Manager::Manager(Eveniment* evenimente) {
    this->evenimente = new Eveniment[nr_ev];
    this->evenimente = nullptr;

}
Manager::Manager(Manager& m) {
    this->evenimente = new Eveniment[nr_ev];
    for (int i = 0; i < m.nr_ev; i++)
        this->evenimente[i] = m.evenimente[i];
}
Manager::~Manager() {
    delete[] evenimente;

}
void Manager::AfisareEv() {
    if (nr_ev > 0)
        for (int i = 0; i < nr_ev; i++)
            if (evenimente != nullptr) {
                cout << "Evenimentul " << i + 1 << " :" << evenimente[i];
            }
            else cout << "Nu avem evenimente momentan";
}
bool Manager::verificareID(int x) {
    for (int i = 0; i < nr_ev; i++)
        for (int j = 0; j < this->evenimente[i].getNrBilete(); j++)
            if (this->evenimente[i].bilet[j].getID() == x)
                return true;
    return false;
}