#ifndef Konta_H
#define Konta_H
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>

class Konta															//klasa odpowiedzialna za metody zwiazanymi z kontem uzytkownika/admina
{
public:
	std::vector<Konta> dane;										//stworzenie wektora do klasy Konta
	std::string login, haslo;
	Konta();														//konstruktor do klasy Konta
	Konta(std::string login1, std::string haslo1);					//konstruktor do klasy Konta
	int iloscKont();												//funkcja zwaracjaca liczbe calkowuta (ilosc kont w pliku)
	void wczytKont(std::string s);									//funkcja wczytujaca konta z pliku
	void zapisKont(Konta& daneKonta, std::string nazwaPliku);		//funkcja zapisujaca konta do pliku
	void noweKonto(std::string nazwaPliku);							//funkcja tworzaca nowe konto
	int zaloguj();													//funkcja odpowiedzialna za zalogowanie do konta
};
#endif // !Konta_H#pragma once
