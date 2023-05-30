#include <iomanip>
#include <fstream>
using namespace std;
#include "slownik.h"
#include "slowko.h"
#include "kryteria.h"
#include <algorithm>


//------------------------------------------------------
slownik::slownik(initializer_list<slowko> init)
{
	/*for (auto it = init.begin(); it != init.end(); ++it)
	{
		S.insert(*it);
	}*/
	for (slowko s : init)
	{
		S.insert(s);
	}
}
//------------------------------------------------------
bool slownik::slowka_zpliku(string nazwa_pliku)
{
	//ifstream in("Users\Miki\source\repos\MINI_LABY_12\MINI_LABY_12\slowka_dnia.txt");
	ifstream in(nazwa_pliku);
	if (!in)
	{
		return false;
	}

	while (!in.eof())
	{
		slowko a;
		in >> a;
		S.insert(a);
	}

	in.close();
	return true;
}
//------------------------------------------------------
void slownik::sortowanie(Cmp::sortuj jak)
{
	if (this->S.value_comp().getKryterium() == jak)
		return;

	set<slowko, Cmp> S2 {Cmp(jak)};

	for (auto s : this->S)
	{
		S2.insert(s);
	}

	this->S = S2;
}
//------------------------------------------------------
void slownik::wstaw()
{
	slowko s;
	cin >> s;

	this->S.insert(s);
}
//------------------------------------------------------
bool slownik::znajdz_slowko(slowko s) const
{
	auto search = slownik::S.find(s);
	if (search == slownik::S.end())
		return false;
	else
		return true;
}
//------------------------------------------------------
void slownik::test() const
{
	int r = rand() % this->S.size();

	auto it = this->S.begin();
	advance(it, r);

	cout << r << " " << it->pol << endl;
	string tmp;
	cin >> tmp;
	slowko s(tmp, it->pol);
	if (znajdz_slowko(s))
	{
		cout << "________ nice bby!" << endl;
	}
	else
	{
		cout << "________ you're a failure and you shell forever live reminded of your failure!" << endl;
	}
}
//------------------------------------------------------
bool slownik::zapisz_slowka() const
{
	cout << "the name of the file you want to save:\n";
	string tmp;
	cin >> tmp;
	ofstream output(tmp + ".txt");

	if(!output)	{ return false;	}

	for (slowko s : this->S)
	{
		output << s;
	}
	//for(set<slowko>::iterator it = this->S.begin(); it != this->S.end(); it++)

	output.close();
	return true;
}
//------------------------------------------------------
ostream& operator<<(ostream& out, const slownik& S)
{
	auto print = [&out, i = 1](slowko s) mutable { out << s; };	//mutable changes from default const to non const
	for_each(S.S.begin(), S.S.end(), print);

	//cwiczenia dodatkowe

	//cw1: zwykly for "na iteratorze"
	/*for (auto it = S.S.begin(); it != S.S.end(); ++it)
	{
		print(*it);
	}*/

	//cw2: zastosuj for "zakresowe" zamiast for
	/*for (auto s : S.S)
	{
		print(s);
	}*/

	return out;
}
//------------------------------------------------------