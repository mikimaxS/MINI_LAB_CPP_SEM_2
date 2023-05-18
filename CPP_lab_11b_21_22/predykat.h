#pragma once
#include <string>

//Etap 3
class StringLongerThan
{
private:
	int minimum;
public:
	StringLongerThan(int minimum);
	bool operator() (const  std::string& s) const;
};

//Uzupełnij implementację