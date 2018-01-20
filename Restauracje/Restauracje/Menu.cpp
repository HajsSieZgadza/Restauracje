#include "Menu.h"
using namespace std;

void Uzytkownik::menu( Restauracje *y, string s,string a)
{
	char wybor;
	cout << "1.) Dodaj restauracje.\n2.) Wyszukaj restauracje\n3.) Wyswietl wszystkie restauracje\n4.) Wyswietl ulubione\n";
	cin >> wybor;
	switch (wybor)
	{
	case '1':
	{
		y->dodajRestauracje();
		y->zapisRestauracji(*y,s);

	}
	break;
	case '2':
	{
		y->wyszukajRestauracje(a);
		y->zapisRestauracji(*y, s);
	}
	break;
	case '3':
	{
		y->wyswietlRestauracje();
	}
	break;
	case '4':
	{
		y->wyswietlUlub(a);
	}
	break;
	default: {
		exit(0);
	}
		break;
	}
}

void Admin::menu( Restauracje *y, string s,string a)
{
	char wybor;
	cout << "1.) Usun restauracje z bazy danych dnia.\n3.) Wyjdz\n ";
	cin >> wybor;
	switch (wybor)
	{
	case '1':
	{
		y->usunRestauracje(*y);
		y->zapisRestauracji(*y, s);

	}
	break;
	break;
	default:
	{
		exit(0);
	}
		break;
	}
}