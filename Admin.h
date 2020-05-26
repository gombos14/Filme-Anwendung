#pragma once
#include "UI.h"
#include "Repository.h"
#include "Film.h"
#include "input.h"
#include <iostream>
#include <string>

class Administrator
{
	friend class repo;
private:
	repo& r;
public:
	Administrator(repo& rep);
	void print_menu();
	void run(); //main function
	void dsp();
};