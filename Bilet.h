#pragma once
#include<iostream>
#include <string>
using namespace std;
class Bilet
{	private:
	int ID;
	string tip;
	float pret;
	int randd;
	int loc;
public:
	Bilet();
	Bilet(string tip, float pret, int rand, int loc);
	Bilet(const Bilet& other);
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
	virtual bool accesBackStage();
	float TVA();
	friend istream& operator>>(istream& in, Bilet& bilet);
	friend ostream& operator<<(ostream& out, const Bilet& bilet);
	friend class Eveniment;
};

