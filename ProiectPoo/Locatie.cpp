#include "Locatie.h"
Locatie::Locatie() {
	strcpy(denumire, "Nedefinita");
	nrMax_locuri = 0;
	locuri = nullptr;
	adresa = "Nedefinita";
}
Locatie::Locatie(char denumire[50], int nrMax_locuri, int* locuri, string adresa) {
	strcpy(this->denumire, denumire);
	this->nrMax_locuri = nrMax_locuri;
	for (int i = 0; i < nrMax_locuri; i++)
		this->locuri[i] = this->locuri[i];
	this->adresa = adresa;

}
char* Locatie::getDenumire() {
	return denumire;
}
int Locatie::getNrMaxLocuri() {
	return nrMax_locuri;
}
int* Locatie::getLocuri() {
	
	int* copy = new int[nrMax_locuri];
	for (int i = 0; i < nrMax_locuri; i++) {
		copy[i] = locuri[i];
	}
	return copy;
}
string Locatie::getAdresa() {
	return adresa;
}
// Setters
void Locatie::setDenumire(char* Denumire) {
	strcpy(denumire, Denumire);
}
void Locatie::setNrMaxLocuri(int newNrMaxLocuri) {
	nrMax_locuri = newNrMaxLocuri;
}
void Locatie::setLocuri(int* Locuri) {
	
	locuri = new int[nrMax_locuri];
	for (int i = 0; i < nrMax_locuri; i++) {
		locuri[i] = Locuri[i];
	}
}
void Locatie::setAdresa(string Adresa) {
	adresa = Adresa;
}

    Locatie::Locatie(const Locatie& other)
    {
        
        strcpy(denumire, other.denumire);

       
        nrMax_locuri = other.nrMax_locuri;

        
        locuri = new int[nrMax_locuri];

       
        for (int i = 0; i < nrMax_locuri; i++)
        {
            locuri[i] = other.locuri[i];
        }

        
        adresa = other.adresa;
    }

  
    Locatie& Locatie::operator=(const Locatie& l)
    {
       
        if (this == &l)
        {
            return *this;
        }

        strcpy(denumire, l.denumire);

        
        nrMax_locuri = l.nrMax_locuri;

        if (locuri)
            delete[] locuri;
        locuri = new int[nrMax_locuri];

        
        for (int i = 0; i < nrMax_locuri; i++)
        {
            locuri[i] = l.locuri[i];
        }

        adresa = l.adresa;

        return *this;
    }

   
    ostream& operator<<(ostream& out, const Locatie& loc)
    {
        out << "Denumire: " << loc.denumire << endl;
        out << "Numar maxim de locuri: " << loc.nrMax_locuri << endl;
        out << "Locuri: ";
        for (int i = 0; i < loc.nrMax_locuri; i++)
        {
            out << loc.locuri[i] << " ";
        }
        out << endl;
        out << "Adresa: " << loc.adresa << endl;
        return out;
    }

    istream& operator>>(istream& in, Locatie& loc)
    {
        cout << "Denumire: ";
        in >> loc.denumire;

        cout << "Numar maxim de locuri: ";
        in >> loc.nrMax_locuri;

       
        loc.locuri = new int[loc.nrMax_locuri];

        cout << "Locuri: ";
        for (int i = 0; i < loc.nrMax_locuri; i++)
            in >> loc.locuri[i];
    }
    bool Locatie::operator>(const Locatie& other) 
    {
        return nrMax_locuri > other.nrMax_locuri;
    }

    
    bool Locatie::operator<(const Locatie& other) 
    {
        return nrMax_locuri < other.nrMax_locuri;
    }
    int Locatie::nrLocuriLibere() {
        int nr=0;
        for (int i = 0; i < nrMax_locuri; i++)
            if (locuri[i])
                nr++;
        return nrMax_locuri - nr;
    }
    int Locatie::nrLocuriOcupate() {
        int nr = 0;
        for (int i = 0; i < nrMax_locuri; i++)
            if (locuri[i]==0)
                nr++;
        return nrMax_locuri - nr;
    }
    //if (loc1 > loc2)
    //{
    //    cout << "Locatia 1 are mai multe locuri decat locatia 2" << endl;
    //}
    //else if (loc1 < loc2)
    //{
    //    cout << "Locatia 1 are mai putine locuri decat locatia 2" << endl;
    //}
    //else
    //{
    //    cout << "Locatiile 1 si 2 au acelasi numar de locuri" << endl;
    //}
    Locatie::~Locatie() {
        if (locuri)
            delete[]locuri, locuri = nullptr;
            
    }
