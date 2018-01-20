#ifndef Menu_H
#define Menu_H
#include <iostream>

#include "Konta.h"
#include "Restauracje.h"


class Menu																//wirtualna klasa, interfejs wykonywania funkcji uzytkowaika w zaleznosci od tego czy jest zwyklym uzytkownikiem czy adminem
{
public:
	virtual void menu( Restauracje *y, std::string s, std::string a) = 0;				//funkcja wirtualna nigdy nie bedzie wykonana gdy¿ zawesze bedzie przys³oniêta
};


class Uzytkownik : public Menu											//klasa dziedzicaca wirtualne finkcje od klasy Menu
{
public:
	virtual void menu( Restauracje *y, std::string s, std::string a);					//funkcja wykonujaca operacje na koncie uztkownika

};


class Admin : public Menu												//klasa dziedzicaca wirtualne finkcje od klasy Menu
{
public:
	virtual void menu( Restauracje *y, std::string s, std::string a);					//funkcja wykonujaca operacje na koncie admina
};


#endif // !Menu_H