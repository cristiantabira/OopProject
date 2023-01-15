#pragma once
#include "Bilet.h"
#include <string>
using namespace std;
//Clasa abstracta,
class BiletNominal :
    public Bilet
{
private:
    string nume;
    string prenume;
public:
    BiletNominal();
    BiletNominal(string nume, string prenume, string tip, float pret, int rand, int loc);
    BiletNominal(const BiletNominal& other);
    ~BiletNominal();
    BiletNominal& operator=(const BiletNominal& b);
    void setNume(string nume);
    void setPrenume(string prenume);
    string getNume();
    string getPrenume();
    virtual bool accesBackStage() override = 0;
};

