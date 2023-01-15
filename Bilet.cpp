#include "Bilet.h"

#include<iostream>

#include<string>

#include<cstdlib>

using namespace std;

Bilet::Bilet() : ID(1 + (rand() % 999999)) {
    tip = "standard";
    pret = -1;
    randd = -1;
    loc = -1;
}

Bilet::Bilet(string tip, float pret, int randd, int loc) :
    ID(1 + (rand() % 999999)), tip(tip), pret(pret), randd(randd), loc(loc) {}
Bilet::Bilet(const Bilet& b) :
    ID(rand() % 99999), tip(b.tip), pret(b.pret), randd(b.randd), loc(b.loc) {}

Bilet& Bilet::operator = (const Bilet& b) {
    if (this != &b) {
        tip = b.tip;
        pret = b.pret;
        randd = b.randd;
        loc = b.loc;
    }
    return *this;
}
void Bilet::setTip(string tip) {
    if (tip.length() > 0)
        this->tip = tip;
}
void Bilet::setPret(float pret) {
    if (pret >= 0)
        this->pret = pret;
}
void Bilet::setRand(int rand) {
    if (rand >= 0)
        this->randd = rand;
}
void Bilet::setLoc(int loc) {
    if (loc >= 0)
        this->loc = loc;
}

int Bilet::getID() const {
    return ID;
}
string Bilet::getTip() const {
    return tip;
}
float Bilet::getPret() const {
    return pret;
}
int Bilet::getRand() const {
    return randd;
}
int Bilet::getLoc() const {
    return loc;
}

ostream& operator << (ostream& out,
    const Bilet& bilet) {
    out << bilet.ID << " " << bilet.tip << " " << bilet.pret << " " << bilet.randd << " " << bilet.loc;
    return out;
}

istream& operator >> (istream& in, Bilet& bilet) {
    in >> bilet.tip >> bilet.pret >> bilet.randd >> bilet.loc;
    return in;
}
bool Bilet::accesVIP() {
    if (tip == "VIP")
        return true;
    else return false;
}
float Bilet::TVA() {
    return pret * (float)0.19;
}
void operator++(Bilet& b) {
    b.setRand(b.getRand() + 1);
}
bool Bilet::accesBackStage() {
    return false;

}