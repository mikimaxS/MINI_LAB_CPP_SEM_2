
#include <iomanip>
using namespace std;
#include "slowko.h"

//----------------------------------------------------
slowko::slowko(string ang, string pol):pol(pol),ang(ang) { }

//---------------------------------------------------
bool operator==(const slowko& s1, const slowko& s2)
{
	return  (s1.pol==s2.pol && s1.ang==s2.ang );
}
//---------------------------------------------------
ostream& operator<<(ostream& out, const slowko& s)
{
	out<<setw(30)<<left<<s.ang;
	out<<setw(30)<<left<<s.pol;
	return out<<endl;
}
//---------------------------------------------------
istream& operator>>(istream& in,  slowko& s)
{
	// wypisz prompt tylko gdy czytamy z klawiatury
	if(&in==&cin)
		cout << "Podaj slowo ANGIELSKIE : ";
		
	in>>s.ang;

	// wypisz prompt tylko gdy czytamy z klawiatury
	if (&in == &cin)
		cout << "Podaj slowo POLSKIE : ";

	in>>s.pol;

	return in;
}
//---------------------------------------------------
