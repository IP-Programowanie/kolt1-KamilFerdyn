#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cassert>
#include <cmath> 


class Wlasciciel
{
};


class Samochod
{
protected:
	char numerRejestracyjny[10]; 
	int stanLicznika; 
	bool stanDopuszczenia; 
	Wlasciciel* wlasciciel; 
	double warPocz;

public:
	

	static Samochod* wzorzec;
	Samochod(const char* nr, int licznik, bool dopuszczony, Wlasciciel* wl, double wartosc)
	{
		this->setNumerRejestracyjny(nr);
		this->setStanLicznika(licznik);
		this->setStanDopuszczenia(dopuszczony);
		this->setWlasciciel(wl);
		this->setWarPocz(wartosc);
	}

	Samochod()
	{
		assert(this->getWzorzec() != nullptr);

		this->setNumerRejestracyjny(this->getWzorzec()->getNumerRejestracyjny());
		this->setStanLicznika(this->getWzorzec()->getStanLicznika());
		this->setStanDopuszczenia(this->getWzorzec()->getStanDopuszczenia());
		this->setWlasciciel(this->getWzorzec()->getWlasciciel());
		this->setWarPocz(this->getWzorzec()->getWarPocz());
	}

	void setWzorzec(Samochod* samochod)
	{
		wzorzec = samochod;
	}

	static Samochod* getWzorzec()
	{
		return wzorzec;
	}

	void setStanLicznika(int licznik)
	{
		if (licznik < 0)
		{
			throw std::invalid_argument("Stan licznika nie może być ujemny");
		}
		stanLicznika = licznik;
	}

	int getStanLicznika()
	{
		return stanLicznika;
	}

	void setStanDopuszczenia(bool dopuszczony)
	{
		stanDopuszczenia = dopuszczony;
	}

	bool getStanDopuszczenia()
	{
		return stanDopuszczenia;
	}

	void setWlasciciel(Wlasciciel* wl)
	{
		wlasciciel = wl;
	}

	Wlasciciel* getWlasciciel()
	{
		return wlasciciel;
	}

	void setWarPocz(double wartosc)
	{
		warPocz = wartosc;
	}

	double getWarPocz()
	{
		return warPocz;
	}

	char* getNumerRejestracyjny()
	{
		return numerRejestracyjny;
	}

	void setNumerRejestracyjny(const char* nr)
	{
		strncpy(numerRejestracyjny, nr, sizeof(numerRejestracyjny));
	}

	
	operator double()
	{
		double wspSparw = this->getStanDopuszczenia() ? 1.0 : 0.2;
		double wartosc = (this->getWarPocz() - 0.2 * getStanLicznika()) * wspSparw;
		return wartosc > 400 ? wartosc : 400;
	}

	
	bool operator!=(Samochod& other)
	{
		return std::abs(this->getStanLicznika() - other.getStanLicznika()) > 20 || this->getStanDopuszczenia() != other.getStanDopuszczenia();
	}
};


class SamochodElektryczny : public Samochod
{
private:
	int stanBaterii; 

public:

	SamochodElektryczny(Samochod& samochod, int bateria) : Samochod(samochod)
	{
		this->setStanBaterii(bateria);
		this->setWarPocz(samochod.getWarPocz() * 0.7);
	}

	void setStanBaterii(int bateria)
	{
		if (bateria < 0 || bateria > 100)
		{
			throw std::invalid_argument("Stan baterii musi być w zakresie od 0 do 100");
		}
		stanBaterii = bateria;
	}

	int getStanBaterii()
	{
		return stanBaterii;
	}
};

Samochod* Samochod::wzorzec = nullptr;

int main()
{
}
