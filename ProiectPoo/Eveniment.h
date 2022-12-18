#include <string>
#include <iostream>
//#include "Eveniment.cpp"
using namespace std;

class Eveniment
{
private:
    string denumire;
    string data;
    string locatie;
    float ora;
    int durata;
public:
    Eveniment(string denumire, string data, string locatie, float ora, int durata);
    Eveniment();
    string getDenumire();
    string getData();
    string getLocatie();
    float getOra();
    int getDurata();
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
    //void getDataInt(string data,int& zi, int& luna, int& an);
    //Eveniment operator>(const Eveniment &e);
    bool operator> (const Eveniment& other);
    bool operator< (const Eveniment& other);

    friend ostream& operator<<(ostream& out, const Eveniment& e);
    friend istream& operator>>(istream& in, Eveniment& e);


};


