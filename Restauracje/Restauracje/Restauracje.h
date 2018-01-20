#ifndef Restauracje_h
#define Restauracje_h
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>

class Restauracje																//klasa odpowiedzialna za metody zwiazanymi z restauracjami
{
public:
	std::vector<Restauracje> restauracje;										//wektor do klasy Restauracje
	std::string nazwa, typ;	
	double ocena;
	Restauracje();																//stworzenie konstruktora do klasy Restauracje
	Restauracje(std::string _nazwa, std::string _typ, double _ocena);			//stworzenie konstruktora do klasy Restauracje
	int iloscRestauracji();														//funkcja zwracajaca liczbe calkowita (ilosc restauracji w pliku)
	void wczytRestauracji(std::string s);										//funkcja wczytujaca restauracje z pliku
	void zapisRestauracji(Restauracje& dane, std::string nazwaPliku);			//funkcja zapisujaca restauracje do pliku
	void dodajRestauracje();													//funkja odpowiedzialna za dodanie nowej restauracji do wektora
	void wyswietlRestauracje();													//funkcja wyswietlajaca restauracje
	void wyszukajRestauracje(std::string s);									//funkcja wyszukujaca restauracje po nazwie/typie/minimalnej ocenie z wektora
	void usunRestauracje(Restauracje& dane);									//funkcja usuwajaca dane o wybranej restauracji z wektora
	void wyswietlUlub(std::string a);
};




#endif // !Restauracje_h


