#include"Konta.h"
#include"Menu.h"
#include"Restauracje.h"

using namespace std;

int main()
{
	string a = "dane.txt", b = "restauracje.txt", c = "ulubione.txt";
	Konta k;
	Restauracje r;
	Uzytkownik uz;
	Admin ad;
	Menu *wsk;
	wsk = &uz;

	k.wczytKont(a);
	r.wczytRestauracji(b);

	char wybor;

	cout << "~~MENU~~\n1.) Nowe Konto.\n2.) Zaloguj.\n3.) Wyjdz" << endl;

	cin >> wybor;

	switch (wybor)
	{
	case '1':
	{
		k.noweKonto(a);
		k.zapisKont(k, a);
		cout << "Uruchom program ponownie!" << endl;
		Sleep(2000);
		exit(0);
	}
	break;
	case '2':
	{
		switch (k.zaloguj())
		{
		case 0:
		{
			exit(0);
		}
		break;
		case 1:
		{
			wsk = &uz;
		}
		break;
		case 2:
		{
			wsk = &ad;
		}
		break;
		}
	}
	break;
	default:
	{
		exit(0);
	}
	break;
	}
	wsk->menu( &r, b,c);



	system("pause");
	return 0;
}