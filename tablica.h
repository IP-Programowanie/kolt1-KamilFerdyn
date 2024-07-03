#pragma once
#include "struktura.h"

Struktura* alokujTablice(int rozmiar, Struktura wzorcowy);
void dealokujTablice(Struktura* tablica);
bool porownajTablice(Struktura* tablica1, Struktura* tablica2, int rozmiar);