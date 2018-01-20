#include "Konta.h"
#include<sstream>
#include <Windows.h>
using namespace std;

Konta::Konta() {};

Konta::Konta(string login1, string haslo1)
{
	login = login1;
	haslo = haslo1;

}
void Konta::wczytKont(string s)
{
	ifstream plik(s);
	string linie;
	while (getline(plik, linie))
	{
		stringstream bob(linie);
		string login, haslo;
		bob >> login;
		bob.ignore();
		bob >> haslo;
		dane.push_back(Konta(login, haslo));
	}
	plik.close();
}
int Konta::iloscKont()
{
	return dane.size();
}
void Konta::zapisKont(Konta& daneKonta, std::string nazwaPliku)
{
	ofstream zapis(nazwaPliku);
	for (int i = 0; i<iloscKont(); i++)
	{
		zapis << dane[i].login << " " << dane[i].haslo << endl;
	}
	zapis.close();
}
void Konta::noweKonto(string nazwaPliku)
{
	int dziala = 0;
	string newLogin, newHaslo, newAdres, newTelefon;
	cout << "Podaj login : ";
	cin >> newLogin;
	cout << endl;
	for (int i = 0; i<iloscKont(); i++)
	{
		if (newLogin == dane[i].login)
		{
			dziala++;
			break;

		}

	}
	if (dziala == 0)
	{
		cout << "Podaj haslo : ";
		cin >> newHaslo;
		dane.push_back(Konta(newLogin, newHaslo));
	}
	else
	{
		cout << " Dany Login jest zajety, sprobuj ponownie " << endl;
		return noweKonto(nazwaPliku);
	}

}
int Konta::zaloguj()
{
	string wczytanyLogin, wczytaneHaslo, wczytanyAdres, wczytanyTel;
	cout << "Login : ";
	cin >> wczytanyLogin;
	bool a = false, b = false;

	for (int i = 0; i < iloscKont(); i++)
	{
		if (wczytanyLogin == dane[i].login)
		{
			a = true;
			cout << "Haslo : ";
			cin >> wczytaneHaslo;

			if (wczytaneHaslo == dane[i].haslo)
			{
				b = true;
				break;
			}

		}
	}
	switch (a)
	{
	case true:
	{
		if (b == true)
			if (wczytanyLogin == "admin")
			{
				cout << "Logowanie Prawidlowe, witam miszczu!" << endl;
				Sleep(2000);
				return 2;
			}

			else
			{
				cout << "Logowanie Prawidlowe!" << endl;
				Sleep(2000);
				return 1;
			}
		else
		{
			cout << "Wrong Password" << endl;
			Sleep(2000);
			return 0;
		}


	}
	break;
	case false:
	{
		cout << "Nie ma takiego Uzytkownika" << endl;
		Sleep(2000);
		return 0;
	}
	}

}