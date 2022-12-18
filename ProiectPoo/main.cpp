#include <string>
#include <iostream>
#include "Eveniment.h"

using namespace std;
int main()
{
	Eveniment e("Untold","10.02","Cluj-Napoca",15.30,3);
	e.setData("2002-1-07");
	cout << e;
	Eveniment a;
	cin >> a;
	cout << endl << a;
}