#pragma once
#include "rep.h"

class Ausnahme
{
	//Ausnahme Klasse um Fehlern zu melden
public:
	const char* what();
	void check_repo(Repository x);
};