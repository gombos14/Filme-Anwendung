#pragma once
#include "Repository.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


class Repository : public repo
{
// Die Klasse Repository ist von der Klasse repo vererbt

public:
	void from_file(const char* filename);
	void to_file(const char* filename);
};