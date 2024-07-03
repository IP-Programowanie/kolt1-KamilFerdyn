#include <iostream>
#include <fstream>
#include "struktura.h"
#include "tablica.h"
#include "plik.h"
#define _CRT_SECURE_NO_WARNINGS



using namespace std;




int main()
{

	Struktura wzorcowy = { 3.14, 'a' };
	int rozmiary[3] = { 5, 7, 9 };
	Struktura* tablice[3];
	for (int i = 0; i < 3; i++) {
		tablice[i] = alokujTablice(rozmiary[i], wzorcowy);
	}

	zapiszDoPliku("najmniejsza.txt", tablice[0]);
	zapiszDoPliku("najwieksza.txt", tablice[2]);

	Struktura* najmniejsza = odczytajZPliku("najmniejsza.txt");
	Struktura* najwieksza = odczytajZPliku("najwieksza.txt");

	if (porownajTablice(tablice[0], najmniejsza, rozmiary[0])) {
		std::cout << "Najmniejsza tablica jest identyczna z pierwowzorem.\n";
	}
	else {
		std::cout << "Najmniejsza tablica nie jest identyczna z pierwowzorem.\n";
	}

	if (porownajTablice(tablice[2], najwieksza, rozmiary[2])) {
		std::cout << "Największa tablica jest identyczna z pierwowzorem.\n";
	}
	else {
		std::cout << "Największa tablica nie jest identyczna z pierwowzorem.\n";
	}

	for (int i = 0; i < 3; i++) {
		dealokujTablice(tablice[i]);
	}
	dealokujTablice(najmniejsza);
	dealokujTablice(najwieksza);

	return 0;

}
