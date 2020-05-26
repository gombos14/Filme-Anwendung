#include <iostream>
#include "Film.h"

film::film()
{
	//constructor
}

film::film(std::string name) : titel(name)
{
	//explicit contructor
}

film::film(std::string t, std::string g, int j, int l, std::string tr)
{
	//full constructor
	titel = t;
	genre = g;
	jahr = j;
	likes = l;
	trailer = tr;
}

std::string film::getTitel()
{
	//returning the title
	return this->titel;
}

void film::setTitel(std::string Titel)
{
	//setting the title
	this->titel = Titel;
}

std::string film::getGenre()
{
	//returning the genre
	return this->genre;
}

void film::setGenre(std::string Genre)
{
	//setting the genre
	this->genre = Genre;
}

int film::getYear()
{
	//returning the year
	return this->jahr;
}

void film::setYear(int year)
{
	//setting the year
	this->jahr = year;
}

int film::getLikes()
{
	//returning the nr of likes
	return this->likes;
}

void film::setLikes(int Likes)
{
	//setting the nr of likes
	this->likes = Likes;
}

std::string film::getTrailer()
{
	//returning the link to the trailer
	return this->trailer;
}

void film::setTrailer(std::string Trailer)
{
	//setting the link to the trailer
	this->trailer = Trailer;
}

void film::toString()
{
	//printing all the infos and opening the URL
	std::cout << std::endl;
	std::cout << "This is an awesome film!\n";
	std::cout << "Titel: " << this->getTitel() << std::endl;
	std::cout << "Genre: " << this->getGenre() << std::endl;
	std::cout << "Erscheinungsjahr: " << this->getYear() << std::endl;
	std::cout << "Likes: " << this->getLikes() << std::endl;
	std::cout << std::endl;

	std::string url;
	url.append("start ");
	url.append(this->getTrailer());
	system(url.c_str());
	system("pause");
}

bool film::operator==(const film o)
{
	//operator
	if (this->titel == o.titel)
		return true;
	else return false;
}