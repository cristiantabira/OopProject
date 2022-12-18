#pragma once
#include<iostream>
#include <string>
using namespace std;
class Bilet
{	private:
	const int ID;
	static int nrBilete;
	string tip;
	float pret;
	int rand;
	int loc;
public:
	Bilet();
	Bilet(string tip, float pret, int rand, int loc);
	Bilet(const Bilet& other);
	~Bilet();
	Bilet& operator=(const Bilet& b);
	void setTip(string tip);
	void setPret(float pret);
	void setRand(int rand);
	void setLoc(int loc);
	int  getID() const;
	string  getTip() const;
	float  getPret() const;
	int  getRand() const;
	int  getLoc() const;
	bool accesVIP();
	int TVA();
	friend istream& operator>>(istream& in, Bilet& bilet);
	friend ostream& operator<<(ostream& out, const Bilet& bilet);
};

