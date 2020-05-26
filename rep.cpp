#include "rep.h"

void Repository::from_file(const char* filename)
{
    ifstream ip(filename);

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

        this->add(film(titel, genre, jahr_int, likes_int, trailer));
    }

    ip.close();
}

void Repository::to_file(const char* filename)
{
    ofstream op(filename);
    int i = 0;
    for (i = 0; i < this->getSize() - 1; i++)
    {
        op << this->at(i).getTitel();
        op << ",";
        op << this->at(i).getGenre();
        op << ",";
        op << this->at(i).getYear();
        op << ",";
        op << this->at(i).getLikes();
        op << ",";
        op << this->at(i).getTrailer();
        op << "\n";
    }
    op << this->at(i).getTitel();
    op << ",";
    op << this->at(i).getGenre();
    op << ",";
    op << this->at(i).getYear();
    op << ",";
    op << this->at(i).getLikes();
    op << ",";
    op << this->at(i).getTrailer();

    op.close();
}