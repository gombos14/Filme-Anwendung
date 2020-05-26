#pragma once
#include "Film.h"
#include <vector>
#include <string>

class repo
{
private:
	std::vector<film> v;
	std::vector<film>::iterator it;
public:
	repo(); //constructor explicit
	repo(std::vector<film> o); //constructor implicit
	repo(const repo& other);
	repo& operator=(const repo& other);
	std::vector<film> getFilm() const; //returns the vector of films
	void setFilm(const std::vector<film>& other);
	void add(film newFilm); //adds a new film to the repository
	void remove(film toRemove); //removes a film from the repository
	void changeTitle(film f, std::string newTitel); //modifies the title of a film
	void changeGenre(film f, std::string newGenre); //modifies the genre
	void changeYear(film f, int newYear); //modifies the year
	void changeLikes(film f, int newLikes); //modifies the nr of likes
	void changeTrailer(film f, std::string newTrailer); //modifies the link to the trailer
	void watchFilm(film f); //same as toString() from Film.h
	void display(); //toString() to all the films
	size_t getSize() const; //returns the size of the repository
	film& at(int index); //returns the element at the specified index
	void getTitels(); //prints the titels of the films
};