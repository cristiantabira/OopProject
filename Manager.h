#include<iostream>
#include<string>
#include"Eveniment.h"

class Manager
{	private:
		static int nr_ev;
	public:
		Eveniment* evenimente;
		Manager();
		Manager(Eveniment* evenimente);
		Manager(Manager& m);
		~Manager();
		void AfisareEv();
		bool verificareID(int x);


};
