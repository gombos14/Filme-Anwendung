#include "tests.h"

void TestFilms()
{
    film a("Batman", "action", 2005, 47, "https://www.youtube.com/watch?v=cElcLipGNIA");
    film b("Batman", "action", 2005, 47, "https://www.youtube.com/watch?v=cElcLipGNIA");

    assert(a.getTitel() == "Batman");
    assert(a.getYear() == 2005);
    assert(a == b);
    a.setGenre("fantasy");
    assert(a.getGenre() == "fantasy");
}

void TestRepository()
{
    repo a;
    film x("Batman", "action", 2005, 47, "https://www.youtube.com/watch?v=cElcLipGNIA");
    film y("The Irishman", "crime", 2019, 98, "https://www.youtube.com/watch?v=WHXxVmeGQUc");

    a.add(x);
    assert(a.getSize() == 1);

    repo b;
    b = a;
    assert(b.getSize() == 1);

    b.add(y);
    assert(b.at(0) == x);
    assert(b.at(1) == y);
}