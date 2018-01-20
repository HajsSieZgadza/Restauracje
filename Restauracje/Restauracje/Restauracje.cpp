#include "Restauracje.h"

using namespace std;

Restauracje::Restauracje() {};

Restauracje::Restauracje(string _nazwa, string _typ, double _ocena) 
{
	nazwa = _nazwa;
	typ = _typ;
	ocena = _ocena;

}

void Restauracje::wczytRestauracji(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		string nazwa, typ;
		double ocena;
		wczyt >> nazwa;
		wczyt.ignore();
		wczyt >> typ;
		wczyt.ignore();
		wczyt >> ocena;
		restauracje.push_back(Restauracje(nazwa,typ,ocena));
	}
	plik.close();
}

int Restauracje::iloscRestauracji()
{
	return restauracje.size();
}

void Restauracje::zapisRestauracji(Restauracje& dane, std::string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i<iloscRestauracji(); i++)
	{
		zapis << restauracje[i].nazwa << " " << restauracje[i].typ << " " << restauracje[i].ocena << endl;
	}
	zapis.close();
}

void Restauracje::dodajRestauracje()
{
	int dziala = 0;
	string newNazwa, newTyp;
	double newOcena;
	cout << "Podaj nazwe : ";
	cin >> newNazwa;
	for (int i = 0; i<iloscRestauracji(); i++)
	{
		if (newNazwa == restauracje[i].nazwa)
		{
			dziala++;
			break;

		}

	}
	if (dziala == 0)
	{
		cout << "Podaj typ restauracji: ";
		cin >> newTyp;
		cout << "Dodaj ocene: ";
		cin >> newOcena;
		restauracje.push_back(Restauracje(newNazwa, newTyp, newOcena));
	}
	else
	{
		cout << " Taka restauracja juz istnieje " << endl;
		Sleep(100);
		return dodajRestauracje();
	}

}

void Restauracje::wyswietlRestauracje()
{
	for (int i = 0; i < iloscRestauracji(); i++)
	{
		cout << restauracje[i].nazwa << " " << restauracje[i].typ << " " << restauracje[i].ocena << endl;
	}
}

void Restauracje::wyszukajRestauracje(string s)
{
	cout << "Po czym chcesz wyszukac restauracje:\n 1) Nazwa\n 2) Typ\n 3) Minimalna ocena\n";
	char wyb,wybor2;
	int dziala=0,id=0;
	cin >> wyb;
	switch (wyb)
	{
	case '1':
	{
		string szukananazwa;
		cout << "Wpisz nazwe restauracji: ";
		cin >> szukananazwa;
		for (int i = 0; i < iloscRestauracji(); i++)
		{
			if (szukananazwa == restauracje[i].nazwa)
			{
				cout << restauracje[i].nazwa << " " << restauracje[i].typ << " " << restauracje[i].ocena << endl;
				dziala=dziala+1;
				id = i;
			}
		}
		if (dziala == 0)
		{
			cout << "Nie ma takiej restauracji!!";
			Sleep(1000);
			exit(0);
		}
		else
		{
			cout << "Czy chcesz dodaj ocene? 1) Tak  2) Nie" << endl;
			cin >> wybor2;
			switch (wybor2)
			{
			case '1':
			{
				cout << "Podaj ocene: ";
				double nowaocena;
				cin >> nowaocena;
				while (nowaocena > 5 || nowaocena < 1)
				{
					cout << "Podaj ocene miedzt 1-5";
					cin >> nowaocena;
				}
				restauracje[id].ocena = (restauracje[id].ocena + nowaocena) / 2;
			}
			break;
			case '2':
			{
				exit(0);
			}
			break;
			default:
				break;
			}
			char wybor;
			cout << "Czy chcesz dodaj restauracje do ulubionych? 1)Tak  2)Nie" << endl;
			cin >> wybor;
			switch (wybor)
			{
			case'1':
			{
				ofstream zapis(s);
				zapis << restauracje[id].nazwa << " " << restauracje[id].typ << " " << restauracje[id].ocena << endl;
				zapis.close();
			}
			break;
			break;
			default:
				break;
			}
		}
	}
	break;
	case '2':
	{
		string szukanytyp;
		cout << "Wpisz typ restauracji: ";
		cin >> szukanytyp;
		for (int i = 0; i < iloscRestauracji(); i++)
		{
			if (szukanytyp == restauracje[i].typ)
			{
				cout << restauracje[i].nazwa << " " << restauracje[i].typ << " " << restauracje[i].ocena << endl;
				dziala = dziala + 1;
				break;
			}
		}
		if (dziala == 0)
		{
			cout << "Nie ma takiego typu!!";
			Sleep(1000);
			exit(0);
		}
	}
	break;
	case '3':
	{
		double szukanaocena;
		cout << "Wpisz typ restauracji: ";
		cin >> szukanaocena;
		for (int i = 0; i < iloscRestauracji(); i++)
		{
			if (szukanaocena <= restauracje[i].ocena)
			{
				cout << restauracje[i].nazwa << " " << restauracje[i].typ << " " << restauracje[i].ocena << endl;
				dziala = dziala + 1;
				break;
			}
		}
		if (dziala == 0) 
		{
			cout << "Nie ma restauracji z taka ocena!!";
			Sleep(1000);
			exit(0);
		}
	}
	break;
	default:
		break;
	}
	

}

void Restauracje::usunRestauracje(Restauracje& dane)
{
	string szukananazwa;
	cout << "Podaj nazwe restauracji ktorej chcesz usunac :";
	cin >> szukananazwa;
	for (int i = 0; i < iloscRestauracji(); i++)
	{
		if (szukananazwa == restauracje[i].nazwa)
		{
			restauracje.erase(restauracje.begin() + i);
		}
	}
}

void Restauracje::wyswietlUlub(string a)
{
	ifstream plik(a);
	string linie;
	while (getline(plik, linie))
	{
		stringstream wczyt(linie);
		string nazwa, typ;
		double ocena;
		wczyt >> nazwa;
		wczyt.ignore();
		wczyt >> typ;
		wczyt.ignore();
		wczyt >> ocena;
		cout << nazwa << " " << typ << " " << ocena << endl;
	}
	plik.close();
}