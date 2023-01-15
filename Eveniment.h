#include <string>
#include <iostream>
#include "Bilet.h"
using namespace std;

class Eveniment
{
private:
    string* zone;
    int nr_zone;
    int nr_bilete;
    const int id;
    string denumire;
    string data;
    string locatie;
    float ora;
    int durata;
public:
    Eveniment(string denumire, string data, string locatie, float ora, int durata,int nr_bilete,int nr_zone, Bilet* bilet, string*zone );
    Eveniment();
    Bilet* bilet;
    string getDenumire();
    string getData();
    string getLocatie();
    float getOra();
    int getNrZone();
    int getDurata();
    int getNrBilete();
    Bilet* getBilete();
    void setZone(const string* zone,int nr_zone);
    void setDenumire(string denumire);
    void setData(string data);
    void setLocatie(string locatie);
    void setOra(float ora);
    void setDurata(int durata);
    Eveniment& operator=(const Eveniment& e);
    Eveniment(const Eveniment&e);
    ~Eveniment();
    bool dataValida(const string& data);
    void getDataInt(int& zi, int& luna, int& an)const;
    bool operator> (const Eveniment& other);
    bool operator< (const Eveniment& other);
    //friend ofstream& operator<<(ofstream& out, const Eveniment& e);
    friend ostream& operator<<(ostream& out, const Eveniment& e);
    friend istream& operator>>(istream& in, Eveniment& e);


};


