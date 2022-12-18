#include "Bilet.h"
#include<iostream>
#include<string>
using namespace std;
int Bilet::nrBilete = 0;

    Bilet::Bilet():ID(nrBilete++) {
        tip = "standard";
        pret = -1;;
        rand = -1;
        loc = -1;
    }

      Bilet::Bilet(string tip, float pret, int rand, int loc) : 
          ID(nrBilete++), tip(tip), pret(pret), rand(rand), loc(loc) {}
      Bilet::Bilet(const Bilet& b) : ID(nrBilete++), tip(b.tip), pret(b.pret), rand(b.rand), loc(b.loc) {}

      
      Bilet::~Bilet() {}

      
      Bilet& Bilet::operator=(const Bilet& b) {
          if (this != &b) {
              tip = b.tip;
              pret = b.pret;
              rand = b.rand;
              loc = b.loc;
          }
          return *this;
      }
          void  Bilet::setTip(string tip) {
              this->tip = tip; }
          void  Bilet::setPret(float pret) { 
              this->pret = pret; }
          void  Bilet::setRand(int rand) {
              this->rand = rand; }
          void  Bilet::setLoc(int loc) {
              this->loc = loc; }

          int  Bilet::getID() const { 
              return ID; }
          string  Bilet::getTip() const {
              return tip; }
          float  Bilet::getPret() const {
              return pret; }
          int  Bilet::getRand() const { 
              return rand; }
          int  Bilet::getLoc() const { 
              return loc; }

          ostream& operator<<(ostream& out, const Bilet& bilet) {
              out << bilet.ID << " " << bilet.tip << " " << bilet.pret << " " << bilet.rand << " " << bilet.loc;
              return out;
          }

          
          istream& operator>>(istream& in, Bilet& bilet) {
              in >> bilet.tip >> bilet.pret >> bilet.rand >> bilet.loc;
              return in;
          }
