#pragma once
#include <string>

class film
{
private:
	std::string titel;
	std::string genre;
	int jahr;
	int likes;
	std::string trailer;
public:
	film(); //constructor
	film(std::string name); //explicit contructor
	film(std::string t, std::string g, int j, int l, std::string tr); //full cosntructor
	std::string getTitel(); //returning the title
	void setTitel(std::string Titel); //setting the title
	std::string getGenre(); //returning the genre
	void setGenre(std::string Genre); //setting the genre
	int getYear(); //returning the year
	void setYear(int year); //setting the year
	int getLikes(); //returning the nr of likes
	void setLikes(int Likes); //setting the nr of likes
	std::string getTrailer(); //returning the link to the trailer
	void setTrailer(std::string Trailer); //setting the link to the trailer
	void toString(); //printing all the infos and opening the URL
	bool operator==(const film other); //operator
};