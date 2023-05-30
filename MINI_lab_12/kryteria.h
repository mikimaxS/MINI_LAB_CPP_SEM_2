#pragma once
#include "slowko.h"


//funktor - okreœla kryterium sortowania w slowniku
class Cmp {

public:
	enum class sortuj { ANG_POL, POL_ANG }; //dwa kryteria sortowania

private:
	sortuj kryterium;

public:
	Cmp(Cmp::sortuj kryterium=Cmp::sortuj::ANG_POL): kryterium{ kryterium } {}
	Cmp::sortuj getKryterium() const { return kryterium; }

	bool operator()(const slowko& s1, const slowko& s2) const
	{
		if (kryterium == Cmp::sortuj::POL_ANG)
		{
			if (s1.pol < s2.pol)  return true;
			if (s1.pol == s2.pol && s1.ang < s2.ang) return true;
			return false;
		}
		else
		{
			if (s1.ang < s2.ang)  return true;
			if (s1.ang == s2.ang && s1.pol < s2.pol) return true;
			return false;
		}
	}
};






