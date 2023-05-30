#pragma once
#include <iostream>
#include <string>
using namespace std;

using std::string;
using std::ostream;
using std::istream;


class slowko
{
	string ang;	
	string pol;	

public:
	slowko() = default;
	slowko(string ang, string pol);
	    	
	friend bool operator==(const slowko& s1, const slowko& s2);

	friend ostream& operator<<(ostream& out, const slowko& s);
	friend istream& operator>>(istream& in, slowko& s);

	friend class slownik;
	friend class Cmp;	//funktor
	
};