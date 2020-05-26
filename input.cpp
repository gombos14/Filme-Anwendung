#include "input.h"

void input(int& cucc)
{
	//input fuer Integers

	cin >> setw(1) >> cucc;

	if (!cin.good())
	{
		throw Ausnahme();
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

void input(string& cucc)
{
	//input fuer Strings

	cin.ignore();
	getline(cin, cucc);

	if (!cin.good())
	{
		throw Ausnahme();
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}

void input(char& cucc)
{
	//input fuer Char
	
	cin >> setw(1) >> cucc;

	if (!cin.good())
	{
		throw Ausnahme();
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
}