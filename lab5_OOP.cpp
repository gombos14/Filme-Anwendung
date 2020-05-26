#include <iostream>
#include <fstream>
#include <sstream>
#include "rep.h"
#include "Film.h"
#include "Repository.h"
#include "Admin.h"
#include "UI.h"
#include "tests.h"
#include "input.h"

using namespace std;


int main()
{
    //ein paar tests
    TestFilms();
    TestRepository();
    
    Repository MyRepo;
    Repository watchlist;

    //polymorphismus
    //class Repository ist von class repo vererbt
    repo* films = &MyRepo;

    
    //lesen von das csv file
    ifstream ip("input.csv");

    if (!ip.is_open()) cout << "Error: File open\n";

    string titel;
    string genre;
    string jahr;
    string likes;
    string trailer;

    while (ip.good())
    {
        getline(ip, titel, ',');
        getline(ip, genre, ',');
        getline(ip, jahr, ',');
        getline(ip, likes, ',');
        getline(ip, trailer, '\n');

        stringstream j(jahr);
        stringstream l(likes);

        int jahr_int, likes_int;

        j >> jahr_int;
        l >> likes_int;

        films->add(film(titel, genre, jahr_int, likes_int, trailer));
    }

    ip.close();

    //MyRepo.from_file("input.csv");
    UserInterface(*films, watchlist);

    MyRepo.to_file("input.csv");
}