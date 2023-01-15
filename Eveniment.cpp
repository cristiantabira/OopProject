#include "Eveniment.h"

#include <iostream>

#include <regex>

#include <string>

#include <sstream>

int nrEvenimente;
Eveniment::Eveniment(string denumire, string data, string locatie, float ora, int durata, int nr_bilet, int nr_zone, Bilet* bilet, string* zone) : denumire(denumire), data(data), locatie(locatie), ora(ora), durata(durata), id(++nrEvenimente), nr_bilete(nr_bilet), nr_zone(nr_zone) {
    this->zone = new string[nr_zone];
    for (int i = 0; i < nr_zone; i++)
        this->zone[i] = "";
    this->bilet = new Bilet[nr_bilete];
    for (int i = 0; i < nr_bilete; i++)
        this->bilet[i] = bilet[i];
}

Eveniment::Eveniment() : id(++nrEvenimente) {
    nr_bilete = 0;
    nr_zone = 1;
    zone = new string[nr_zone];
    zone[0] = "Zona 1";
    bilet = nullptr;

    denumire = "Nedefinita";
    data = "Nedefinita";
    locatie = "Nedefinita";
    ora = 0;
    durata = 0;
}
Bilet* Eveniment::getBilete() {
    if (bilet)
        return new Bilet(*bilet);
    return nullptr;
}
string Eveniment::getDenumire() {
    return denumire;
}

string Eveniment::getData() {
    return data;
}

string Eveniment::getLocatie() {
    return locatie;
}
int Eveniment::getNrZone() {
    return nr_zone;
}

float Eveniment::getOra() {
    return ora;
}

int Eveniment::getDurata() {
    return durata;
}
int Eveniment::getNrBilete() {
    return this->nr_bilete;
}
void Eveniment::setDenumire(string denumire) {
    if (denumire.length() > 0)
        this->denumire = denumire;
}

void Eveniment::setZone(const string* zone, int nr_zone) {
    this->zone = new string[nr_zone];
    this->nr_zone = nr_zone;
    for (int i = 0; i < nr_zone; i++)
        this->zone[i] = zone[i];
}
void Eveniment::setData(string data) {
    if (dataValida(data))
        this->data = data;
    else cout << "data invalida";
}
bool Eveniment::dataValida(const string& data) {

    regex pattern("[0-9]{4}-[0-9]{2}-[0-9]{2}");

    return regex_match(data, pattern);
}
void Eveniment::setLocatie(string locatie) {
    if (locatie.length() > 0)
        this->locatie = locatie;
}
void Eveniment::setOra(float ora) {
    this->ora = ora;
}

void Eveniment::setDurata(int durata) {
    if (durata > 0)
        this->durata = durata;
    else this->durata = 0;
}
Eveniment::~Eveniment() {
    if (bilet)
        delete[] bilet;
    if (zone)
        delete[] zone;

}
Eveniment::Eveniment(const Eveniment& e) : id(++nrEvenimente) {
    this->nr_bilete = e.nr_bilete;
    this->denumire = e.denumire;
    this->data = e.data;
    this->locatie = e.locatie;
    this->ora = e.ora;
    this->durata = e.durata;
}

Eveniment& Eveniment::operator = (const Eveniment& e) {
    if (this == &e) {
        return *this;
    }
    if (this->bilet != nullptr) {
        delete[] this->bilet;
        bilet = nullptr;
    }
    if (this->zone != nullptr) {
        delete[] this->zone;
        zone = nullptr;
    }
    this->bilet = new Bilet[e.nr_bilete];
    this->zone = new string[e.nr_zone];
    this->nr_bilete = e.nr_bilete;
    this->nr_zone = e.nr_zone;
    denumire = e.denumire;
    data = e.data;
    locatie = e.locatie;
    ora = e.ora;
    durata = e.durata;
    if (e.bilet)
        for (int i = 0; i < this->nr_bilete; i++)
            this->bilet[i] = e.bilet[i];
    if (e.zone)
        for (int i = 0; i < this->nr_zone; i++)
            this->zone[i] = e.zone[i];
    return *this;
}
void Eveniment::getDataInt(int& zi, int& luna, int& an) const {

    sscanf_s(data.c_str(), "%d-%d-%d", &zi, &luna, &an);
}
bool Eveniment::operator > (const Eveniment& other) {
    int zi1, luna1, an1;
    getDataInt(zi1, luna1, an1);

    int zi2, luna2, an2;
    other.getDataInt(zi2, luna2, an2);

    if (an1 > an2) {
        return true;
    }
    else if (an1 == an2) {
        if (luna1 > luna2) {
            return true;
        }
        else if (luna1 == luna2) {
            return zi1 > zi2;
        }
    }

    return false;
}
bool Eveniment::operator < (const Eveniment& other) {
    int zi1, luna1, an1;
    getDataInt(zi1, luna1, an1);

    int zi2, luna2, an2;
    other.getDataInt(zi2, luna2, an2);

    if (an1 < an2) {
        return true;
    }
    else if (an1 == an2) {
        if (luna1 < luna2) {
            return true;
        }
        else if (luna1 == luna2) {
            return zi1 < zi2;
        }
    }

    return false;
}
ostream& operator << (ostream& out,
    const Eveniment& e) {
    out << "Evenimentul " << e.denumire << " " << "are loc la data de " << e.data << " " << ", la " << e.locatie <<
        " " << "la ora " << e.ora << " " << "si va dura " << e.durata << " zile";
    return out;
}
istream& operator >> (istream& in, Eveniment& e) {
    cout << endl << "Evenimentul ";
    in >> e.denumire;
    cout << " are loc la data de(an-luna-zi) ";
    in >> e.data;
    cout << " la locatia: ";
    in >> e.locatie;
    cout << "incepand cu ora(format ora: ora.minute): ";
    in >> e.ora;
    cout << "si va dura: ";
    in >> e.durata;
    return in;
}