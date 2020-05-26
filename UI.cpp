#include "UI.h"
using namespace std;

void UserInterface(repo& rep, Repository& watch)
{
	char x;
	cout << "Hallo!\nWahlen Sie ein Modus:\nAdministrator (a) oder Benutzer (b)\n";
	cin >> x;
	if (x == 'a')
	{
		cout << "\nWilkommen in Administratormodus!\n";
		Administrator admin(rep);
		admin.run();
	}
	else if (x == 'b')
	{
		cout << "\nWilkommen in Benutzermodus!\n";
		Benutzer user(rep, watch);
		user.run();
	}
	else
	{
		cout << "\nGeben Sie eine gultige Moglichkeit an!\n\n";
		UserInterface(rep, watch);
	}
}
