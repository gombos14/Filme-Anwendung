#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Repository.h"
#include "Film.h"
#include "UI.h"
#include "Ausnahmen.h"
#include "input.h"

class Benutzer
{
private:
	repo& r;
	Repository& watchlist;

public:
	Benutzer(repo& rep, Repository& watch);
	void print_menu();
	void run(); //main function
	void toWatchlist(film& f);
};
