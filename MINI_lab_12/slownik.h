#pragma once

#include <set>
#include "slowko.h"
#include "kryteria.h"

using std::set;


class slownik
{
	set<slowko,Cmp> S;

public:
	slownik() = default;
	slownik(initializer_list<slowko> init);

	bool slowka_zpliku(string nazwa_pliku);

	void sortowanie(Cmp::sortuj jak);

	void wstaw();

	bool znajdz_slowko(slowko s) const;
	void test() const;

	bool zapisz_slowka() const;
	
	friend ostream& operator<<(ostream& out, const slownik& S);
};

