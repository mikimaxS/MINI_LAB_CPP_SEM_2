#include <iomanip>
using namespace std;
#include "slownik.h"
#include "slowko.h"
#include "kryteria.h"

#include <algorithm>
#include <fstream>

//------------------------------------------------------
slownik::slownik(initializer_list<slowko> init)
{
    for (auto it: init)
    {
        this->S.insert(it);
    }
}

//------------------------------------------------------
bool slownik::slowka_zpliku(string nazwa_pliku)
{
    string ang, pol;
    ifstream in(nazwa_pliku);

    if (!in) { return false; }

    while (!in.eof())
    {
        in >> ang >> pol;
        this->S.insert(slowko(ang, pol));
    }

    in.close();
    return true;
}

//------------------------------------------------------
void slownik::sortowanie(Cmp::sortuj jak)
{
    if (this->S.value_comp().getKryterium() == jak)
        return;

    set<slowko, Cmp> S2{Cmp{jak}};

    for (auto it: this->S)
    {
        S2.insert(it);
    }

    this->S = S2;
}

//------------------------------------------------------
void slownik::wstaw()
{
    slowko tmp;

    cin >> tmp;
    this->S.insert(tmp);
}

//------------------------------------------------------
bool slownik::znajdz_slowko(slowko s) const
{
    if (this->S.find(s) == this->S.end()) // incorrect translation
    {
        return false;
    }
    else
    {
        return true;
    }
}

//------------------------------------------------------
void slownik::test() const
{
    int random = rand() % this->S.size() + 1;

    auto it = this->S.begin();
    advance(it, random);

    std::cout << random << " " << it->pol << std::endl;

    string s_ang;
    cin >> s_ang;

    slowko s(s_ang, it->pol);
    if (znajdz_slowko(s))
    {   // correct translation
        std::cout << "job well done!" << std::endl;
    }
    else
    {
        std::cout << "you're a failure and you shall live forever reminded of it" << std::endl;
    }
}

//------------------------------------------------------
bool slownik::zapisz_slowka() const
{
    std::cout << "save: ";
    string s;
    std::cin >> s;

    if (ifstream(s + ".txt"))
    {
        std::cout << "file not saved... file alerady exists" << std::endl;
        return false;
    }

    ofstream output(s + ".txt");
    if (!output) return false;

    for (auto it: this->S)
    {
        output << it;
    }

    output.close();
    return true;
}

//------------------------------------------------------
ostream& operator<<(ostream& out, const slownik& S)
{
    //zastosuj for_each  z lambd¹
    //uzupe³nij
    for_each(S.S.begin(), S.S.end(), [&out, i = 1](slowko tmp) mutable
    {
        out << i << ": " << tmp;
        ++i;
    });

    return out;
    //cwiczenia dodatkowe
    //cw1: zwyk³y for "na iteratorze"
    //cw2: zastosuj for "zakresowe" zamiast for
}

//------------------------------------------------------
