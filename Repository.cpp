#include <iostream>
#include "Repository.h"

repo::repo()
{
	//constructor explicit
}

repo::repo(std::vector<film> o) : v(o)
{
	//constructor implicit
}

repo::repo(const repo& other)
{
	v = other.getFilm();
}

repo& repo::operator=(const repo& other)
{
	v = other.getFilm();
	return *this;
}

std::vector<film> repo::getFilm() const
{
	//returning the vector of films
	return v;
}

void repo::setFilm(const std::vector<film>& other)
{
	v = other;
}

void repo::add(film newFilm)
{
	v.push_back(newFilm);
}

void repo::remove(film f)
{
	it = std::find(v.begin(), v.end(), f);
	if (it != v.end())
		v.erase(it);
	else {
		std::cout << "Element not found!\n";
		system("pause");
	}
}

void repo::changeTitle(film f, std::string newTitel)
{
	it = std::find(v.begin(), v.end(), f);
	if (it != v.end())
		(*it).setTitel(newTitel);
	else {
		std::cout << "Element not found!\n";
		system("pause");
	}
}

void repo::changeGenre(film f, std::string newGenre)
{
	it = std::find(v.begin(), v.end(), f);
	if (it != v.end())
		(*it).setGenre(newGenre);
	else {
		std::cout << "Element not found!\n";
		system("pause");
	}
}

void repo::changeYear(film f, int year)
{
	it = std::find(v.begin(), v.end(), f);
	if (it != v.end())
		(*it).setYear(year);
	else {
		std::cout << "Element not found!\n";
		system("pause");
	}
}

void repo::changeLikes(film f, int l)
{
	it = std::find(v.begin(), v.end(), f);
	if (it != v.end())
		(*it).setLikes(l);
	else {
		std::cout << "Element not found!\n";
		system("pause");
	}
}

void repo::changeTrailer(film f, std::string newTrailer)
{
	it = std::find(v.begin(), v.end(), f);
	if (it != v.end())
		(*it).setTrailer(newTrailer);
	else {
		std::cout << "Element not found!\n";
		system("pause");
	}
}

void repo::display()
{
	for (int i = 0; i < v.size(); i++)
		v[i].toString();
}

void repo::watchFilm(film f)
{
	it = std::find(v.begin(), v.end(), f);
	if (it != v.end())
		(*it).toString();
	else {
		std::cout << "Element not found!\n";
		system("pause");
	}
}

size_t repo::getSize() const
{
	return v.size();
}

film& repo::at(int index)
{
	return v[index];
}

void repo::getTitels()
{
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i].getTitel() << "\n";
}