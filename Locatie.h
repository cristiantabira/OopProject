#pragma once
#include<string>
#include<iostream>
using namespace std;
class Locatie
{	private:
	char denumire[50] ;
	int nrMax_locuri;
	int* locuri;
	string adresa;
public:
	Locatie();
	Locatie(char denumire[50], int nrMax_locuri, int* locuri, string adresa);
	Locatie(const Locatie& l);
	char* getDenumire();
	int getNrMaxLocuri();
	int* getLocuri();
	string getAdresa();
	void setDenumire(char* Denumire);
	void setNrMaxLocuri(int NrMaxLocuri);
	void setLocuri(int* Locuri);
	void setAdresa(string Adresa);
	Locatie& operator=(const Locatie& l);
	friend ostream& operator<<(ostream& out, const Locatie& loc);
	friend istream& operator>>(istream& in, Locatie& loc);
	bool operator<(const Locatie& other);
	bool operator>(const Locatie& other);
	int nrLocuriLibere();
	int nrLocuriOcupate();
	~Locatie();
};

