

#include <iomanip>
using namespace std;
#include "student.h"
#include "my_algorithm.h"


//-------------------------------------------------------------------
student::student(const std::string& n, const std::string& s, const std::list<int>& p) : name(n), surname(s), points(p) {}
//-------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const student& st)
{
	//wypisz surname, name, mark
	out << st.surname << " " << st.name << " " << st.mark << "    ";
	//do wypisania punktów zastosuj my_for_each oraz lambda

	auto lambda = [&out](int i) -> std::ostream& { out << i << " "; return out; };
	my_for_each(st.points.begin(), st.points.end(), lambda);

	return out;
}
//--------------------------------------------------------------------
int student::sum_of_points() const
{
	//uzupe³nij
	//do obliczenia sumy punktów zastosuj my_accumulate oraz lambda



	return 0; //jeœli lista punktów pusta
}

//------------------------------------------------------------------
void student::histogram(std::map<int, int>& m) const
{
	//uzupe³nij tworzenie mapy histogramu
	//dla listy punktów zastosuj my_for_each oraz lambda



}

//------------------------------------------------------------------

