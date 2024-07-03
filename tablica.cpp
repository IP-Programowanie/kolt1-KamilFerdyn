
#include "tablica.h"


using namespace std;



bool porownajTablice(Struktura* tablica1, Struktura* tablica2, int rozmiar)
{
	for (int i = 0; i < rozmiar; i++)
	{
		if (tablica1[i].poleFloat != tablica2[i].poleFloat || tablica1[i].poleChar != tablica2[i].poleChar)
		{
			return false;
		}
	}
	return true;
}


Struktura* alokujTablice(int rozmiar, Struktura wzorcowy)
{
	Struktura* tablica = new Struktura[rozmiar + 1];
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = wzorcowy;

	}
	tablica[rozmiar].poleChar = rozmiar;
	return tablica;
}



void dealokujTablice(Struktura* tablica)
{
	int rozmiar = (int)tablica[rozmiar].poleChar;
	delete[] tablica;
}

void zapiszDoPliku(const char* nazwaPliku, Struktura* tablica)
{
	std::ofstream plik(nazwaPliku);
	if (!plik)
	{
		cerr << "Nie mozna uruchomic pliku" << endl;
	}
	int rozmiar = (int)tablica[rozmiar].poleChar;
	plik << rozmiar << '\n';
	for (int i = 0; i < rozmiar; i++) {
		plik << tablica[i].poleFloat << ' ' << tablica[i].poleChar << '\n';
	}
}

