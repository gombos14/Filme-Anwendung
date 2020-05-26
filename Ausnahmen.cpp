#include "Ausnahmen.h"

const char* Ausnahme::what()
{
	return "Falsche Eingabe!";
}

void Ausnahme::check_repo(Repository x)
{
	for (int i = 0; i < x.getSize(); i++)
	{
		//
	}
}