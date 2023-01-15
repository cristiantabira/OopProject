#include "BiletNominal.h"

#include <iostream>

#include<string>

using namespace std;

BiletNominal::BiletNominal() : Bilet() {
    nume = "Necunoscut";
    prenume = "Necunoscut";
}
BiletNominal::BiletNominal(string nume, string prenume, string tip, float pret, int rand, int loc) : Bilet(tip, pret, rand, loc) {
    this->nume = nume;
    this->prenume = prenume;
}
BiletNominal::BiletNominal(const BiletNominal& other) {
    this->nume = other.nume;
    this->prenume = other.prenume;
}
BiletNominal::~BiletNominal() {

}
BiletNominal& BiletNominal::operator = (const BiletNominal& b) {

    this->nume = b.nume;
    this->prenume;
    return *this;
}
void BiletNominal::setNume(string nume) {
    this->nume = nume;
}
void BiletNominal::setPrenume(string prenume) {
    this->prenume = prenume;
}
string BiletNominal::getNume() {
    return this->nume;
}
string BiletNominal::getPrenume() {
    return this->prenume;
}