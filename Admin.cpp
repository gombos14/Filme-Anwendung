#include "Admin.h"

Administrator::Administrator(repo& rep) : r(rep) {}

void Administrator::print_menu()
{
	std::cout << "1. Einen neuen Film hinzufugen\n";
	std::cout << "2. Einen Film loschen\n";
	std::cout << "3. Das Titel eines Films andern\n";
	std::cout << "4. Das Genre eines Films andern\n";
	std::cout << "5. Das Erscheinungsjahr eines Films andern\n";
	std::cout << "6. Die Anzahl von Likes eines Films andern\n";
	std::cout << "7. Das Trailer eines Films andern\n";
	std::cout << "8. Ein Film ansehen\n";
	std::cout << "9. Exit\n";
}

void Administrator::run()
{
	while (true)
	{
		std::cout << "\nWahlen Sie ein Option\n\n";
		this->print_menu();
		int option;
		try
		{
			input(option);
		}
		catch (Ausnahme e)
		{
			cout << e.what() << endl;
		}
		if (option == 1)
		{
			std::cout << "\n";
			std::string titel;
			std::cout << "Titel: ";
			try
			{
				input(titel);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}

			std::string genre;
			std::cout << "Genre: ";
			try
			{
				input(genre);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}

			int jahr;
			std::cout << "Ersheinungsjahr: ";
			try
			{
				input(jahr);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}

			int likes;
			std::cout << "Anzahl von Likes: ";
			try
			{
				input(likes);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}

			std::string trailer;
			std::cout << "Link zum Trailer: ";
			try
			{
				input(trailer);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			std::cout << std::endl;

			film x(titel, genre, jahr, likes, trailer);
			r.add(x);
		}
		else if (option == 2)
		{
			std::string t;
			std::cout << "Welche Film mochten Sie loshen?\nGeben Sie den Titel an! ";
			try
			{
				input(t);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			film x(t);
			r.remove(x);
		}
		else if (option == 3)
		{
			std::string t;
			std::cout << "Welcher Film mochten Sie den Titel andern?\nGeben Sie den Titel an! ";
			try
			{
				input(t);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			film x(t);
			std::string nt;
			std::cout << "Geben Sie die neue Titel an! ";
			try
			{
				input(nt);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			r.changeTitle(x, nt);
		}
		else if (option == 4)
		{
			std::string t;
			std::cout << "Welcher Film mochten Sie den Genre andern?\nGeben Sie den Titel an! ";
			try
			{
				input(t);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			film x(t);
			std::string ng;
			std::cout << "Geben Sie die neue Genre an! ";
			try
			{
				input(ng);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			r.changeGenre(x, ng);
		}
		else if (option == 5)
		{
			std::string t;
			std::cout << "Welcher Film mochten Sie den Erscheinungsjahr andern?\nGeben Sie den Titel an! ";
			try
			{
				input(t);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			film x(t);
			int nj;
			std::cout << "Geben Sie die neue Jahr an! ";
			try
			{
				input(nj);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			r.changeYear(x, nj);
		}
		else if (option == 6)
		{
			std::string t;
			std::cout << "Welcher Film mochten Sie den Anzahl von Likes andern?\nGeben Sie den Titel an! ";
			try
			{
				input(t);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			film x(t);
			int na;
			std::cout << "Geben Sie die neue Anzahl an! ";
			try
			{
				input(na);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			r.changeLikes(x, na);
		}
		else if (option == 7)
		{
			std::string t;
			std::cout << "Welcher Film mochten Sie den Link zum Trailer andern?\nGeben Sie den Titel an! ";
			try
			{
				input(t);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			film x(t);
			std::string nl;
			std::cout << "Geben Sie die neue Link an! ";
			try
			{
				input(nl);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			r.changeTrailer(x, nl);
		}
		else if (option == 8)
		{
			std::string t;
			std::cout << "Welche Film mochten Sie ansehen?\nGeben Sie den Titel an! ";
			try
			{
				input(t);
			}
			catch (Ausnahme e)
			{
				cout << e.what() << endl;
			}
			film x(t);
			r.watchFilm(x);
		}
		else if (option == 0)
			r.getTitels();
		else break;
	}
}

void Administrator::dsp()
{
	r.display();
}