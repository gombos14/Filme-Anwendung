#include "User.h"

Benutzer::Benutzer(repo& rep, Repository& watch) : r(rep), watchlist(watch) {}

void Benutzer::print_menu()
{
	//printing menu
	std::cout << "1. Filmen ansehen mit ein bestimmten Genre\n";
	std::cout << "2. Watchlist ansehen\n";
	std::cout << "3. Exit\n";
}

void Benutzer::run()
{
	while(true)
	{
		std::cout << "\nWahlen Sie ein Option\n\n";
		this->print_menu();
		int option;
		std::cin >> option;
		if (option == 1)
		{
			std::cout << "\n";
			std::cout << "Bestimmen Sie ein Genre: ";
			std::string g;
			try
			{
				input(g);
			}
			catch(Ausnahme e)
			{
				cout << e.what() << endl;
			}

			if (g == " ")
				r.display();
			else
			{
				int i = 0;
				while (i < r.getFilm().size())
				{
					if (r.getFilm()[i].getGenre() == g)
					{
						r.getFilm()[i].toString();

						char w;
						std::cout << "Mochten Sie dieses Film auf Watchlist setzen? (j/n) ";
						try
						{
							input(w);
						}
						catch (Ausnahme e)
						{
							cout << e.what() << endl;
						}
						if (w == 'j')
							this->toWatchlist(r.getFilm()[i]);
						std::cout << std::endl;
						char n;
						std::cout << "Nachstes Film? (j/n) ";
						try
						{
							input(n);
						}
						catch (Ausnahme e)
						{
							cout << e.what() << endl;
						}
						if (n != 'j')
							break;
						std::cout << std::endl;
					}
					i++;
				}
				if (i == r.getFilm().size())
				{
					std::cout << "\nEs gibt kein(e andere) Film(e) mit diesem Genre!\n\n";
					system("pause");
				}
			}
		}
		else if (option == 2)
		{
			if (watchlist.getSize() != 0)
			{
				system("watchlist.csv");
				
				std::cout << "\n";
				for (int i = 0; i < watchlist.getSize(); i++)
					std::cout << i + 1 << ". " << watchlist.at(i).getTitel() << std::endl;

				std::cout << "\nWelches Film mochten Sie ansehen? (Bitte die Ordinalzahl angeben!)\n";
				int k;
				try
				{
					input(k);
				}
				catch (Ausnahme e)
				{
					cout << e.what() << endl;
				}

				watchlist.at(k - 1).toString();


				std::cout << "\nGefallt Ihnen den Film? (j/n) ";
				char opt;
				try
				{
					input(opt);
				}
				catch (Ausnahme e)
				{
					cout << e.what() << endl;
				}
				if (opt == 'j')
				{
					film diese = watchlist.at(k - 1);
					watchlist.at(k - 1).setLikes(watchlist.at(k - 1).getLikes() + 1);
					r.changeLikes(diese, diese.getLikes() + 1);
				}

				std::cout << "\nMochten Sie den Film aus der Watchliste loschen? (j/n) ";
				char opt1;
				try
				{
					input(opt1);
				}
				catch (Ausnahme e)
				{
					cout << e.what() << endl;
				}
				if (opt1 == 'j')
					watchlist.remove(watchlist.at(k - 1));

			}
			else std::cout << "\nEs gibt keine Filme auf der Watchliste!\n";
		}
		else if (option == 0)
			r.getTitels();
		else break;
	}
}

void Benutzer::toWatchlist(film& f)
{
	this->watchlist.add(f);
	this->watchlist.to_file("watchlist.csv");
}