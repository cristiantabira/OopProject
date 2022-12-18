#include "Eveniment.h"
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
Eveniment::Eveniment(string denumire, string data, string locatie, float ora, int durata)
    : denumire(denumire), data(data), locatie(locatie), ora(ora), durata(durata) {}

    Eveniment::Eveniment() {
        denumire = "Nedefinita";
        data = "Nedefinita";
        locatie = "Nedefinita";
        ora = 0;
        durata = 0;
   }
    string Eveniment::getDenumire()
    {
        return denumire;
    }

    
    string Eveniment::getData()
    {
        return data;
    }

    
    string Eveniment::getLocatie()
    {
        return locatie;
    }

    
    float Eveniment::getOra()
    {
        return ora;
    }

    
    int Eveniment::getDurata()
    {
        return durata;
    }
void Eveniment::setDenumire(string denumire) {
    if(denumire.length()>0)
    this->denumire = denumire;
}

void  Eveniment::setData(string data) {
    if (dataValida(data))this->data = data;
   // else cout<< "data invalida";
}
bool Eveniment::dataValida(const string& data)
{
    
    regex pattern("^[0-9]{4}-[0-9]{2}-[0-9]{2}$");

    
    return regex_match(data, pattern);
}
void Eveniment::setLocatie(string locatie)
{   if(locatie.length()>0)
    this->locatie = locatie;
}
void Eveniment::setOra(float ora) {
    this->ora = ora;
}

void Eveniment::setDurata(int durata)
{
    if (durata > 0)
        this->durata = durata;
    else this->durata = 0;
}
//Eveniment Eveniment::operator>(const Eveniment &e)
//{
//    int zi, an, luna;
//    getDataInt(e.data,zi, luna, an);
//
//}
//void Eveniment::getDataInt(string data, int& zi, int& luna, int& an)
//{
//    
//    stringstream ss(data);
//    getline(delim, an, '-');
//    getline(ss, luna, '-');
//    getline(ss, zi);
//
//    
//    an = stoi(an);
//    luna = stoi(luna);
//    zi = stoi(zi);
//}


Eveniment::~Eveniment() {

}
Eveniment::Eveniment(const Eveniment &e)
{
    denumire = e.denumire;
    data = e.data;
    locatie = e.locatie;
    ora = e.ora;
    durata = e.durata;
}
Eveniment& Eveniment::operator=(const Eveniment& e)
{
    if (this == &e)
    {
        return *this;
    }

    denumire = e.denumire;
    data = e.data;
    locatie = e.locatie;
    ora = e.ora;
    durata = e.durata;
    return *this;
}
void Eveniment::getDataInt(int& zi, int& luna, int& an)const
{
   
    sscanf(data.c_str(), "%d-%d-%d", &zi, &luna, &an);
}
bool Eveniment::operator> (const Eveniment& other)
{
    int zi1, luna1, an1;
    getDataInt(zi1, luna1, an1);

    int zi2, luna2, an2;
    other.getDataInt(zi2, luna2, an2);

    if (an1 > an2)
    {
        return true;
    }
    else if (an1 == an2)
    {
        if (luna1 > luna2)
        {
            return true;
        }
        else if (luna1 == luna2)
        {
            return zi1 > zi2;
        }
    }

    return false;
}
bool Eveniment::operator< (const Eveniment& other)
{
    int zi1, luna1, an1;
    getDataInt(zi1, luna1, an1);

    int zi2, luna2, an2;
    other.getDataInt(zi2, luna2, an2);

    if (an1 < an2)
    {
        return true;
    }
    else if (an1 == an2)
    {
        if (luna1 < luna2)
        {
            return true;
        }
        else if (luna1 == luna2)
        {
            return zi1 < zi2;
        }
    }

    return false;
}
ostream& operator<<(ostream& out, const Eveniment& e)
{
    out <<"Evenimentul " <<e.denumire << " " <<"are loc la data de " << e.data << " " <<", la " << e.locatie <<
        " "<<"la ora " << e.ora << " "<<"si va dura " << e.durata<<" zile";
    return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
    cout <<endl<< "Evenimentul ";
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

