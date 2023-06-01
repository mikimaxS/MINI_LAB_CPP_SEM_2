#include <fstream>

#include <map>
#include <iomanip>
#include "evaluation.h"
#include "my_algorithm.h"
using namespace std;

//wystawianie ocen (tylko ca�kowite) na podstawie punkt�w: >=55p ocena 3; >=70p ocena 4; >=85p ocena 5
const map<int, int, greater<int>> evaluation::levels = { { 55, 3}, { 70, 4}, { 85, 5} };

//ETAP 1
evaluation::evaluation(const string& file_name)
{
	ifstream in(file_name);

	if (!in) return;

	string name, surname;
	list<int> tlist;
	static const int SIZE = 200;
	char tline[SIZE];

	while (!in.eof())
	{
		in >> name;
		in >> surname;

		in.getline(&tline[0], std::numeric_limits<int>::max(), '\n');

		//cout << "++" << tline << "**";
		int tmp(0), n(0);

		for (int i = SIZE - 1; i >= 0; --i)
		{
			if ('0' <= tline[i] && tline[i] <= '9')
			{
				while ('0' <= tline[i] && tline[i] <= '9')
				{
					//cout << tline[i];
					tmp += int(tline[i] - '0') * pow(10, n);

					--i;
					++n;
				}
				tlist.push_front(tmp);
				n = 0;
				tmp = 0;
			}
		}

		//cout << name << " " << surname << tline << " ******** " << endl;
		//for (auto it : tlist)
		//{
			//cout << it << " ";
		//}
		//cout << endl;

		this->students.push_back(student(name, surname, tlist));

		tlist.clear();
	}

	in.close();
}

ostream& operator<<(ostream& out, const evaluation& e)
{
	//uzupe�nij
	//do wypisania danych kolejnych student�w zastosuj my_for_each oraz lambda
	//(w kt�rej wykorzystaj operator<< dla studenta)
	auto lambda = [&out](const student s)->std::ostream& {out << s << endl; return out; };
	my_for_each(e.students.begin(), e.students.end(), lambda);

	return out;
}
//---------------------------------------------------------------
//ETAP 2
void evaluation::sort()	//sortowanie wg surname, name (studenta)
{
	//uzupe�nij
	//dla listy student�w wykonaj sortowanie wg surname oraz name
	//dla metody sort listy zdefiniuj odpowiednie lambda




}
//---------------------------------------------------------------
//ETAP 3

void evaluation::set_marks()
{
	//uzupe�nij
	//dla kolejnych student�w wystaw ocen� (mark)
	//do przegl�dania listy student�w zastosuj my_for_each
	//do ustalenia oceny studenta na podstawie sumy punkt�w, zastosuj my_find_if dla mapy levels
	//zdefiniuj odpowiednie lambda




}

void evaluation::reset_points(const int& p)
{
	//uzupe�nij
	//wszystkim studentom za ka�de oddane zadanie (>0) podnie� punkty o +p
	//dla listy kolejnych student�w zastosuj my_for_each
	//a do modyfukacji listy punkt�w zastosuj my_transform oraz odpowiednie lambda
	//(punkty dodajemy tylko do zadania ocenione go na wi�cej ni� 0)



}

//---------------------------------------------------------------
//ETAP 4
void evaluation::clear_not_passing()
{
	//uzupe�nij
	//usu� student�w, kt�rzy nie uzyskuj� zaliczenia
	//zastosuj metod� remove_if dla listy students oraz lambda



}
//---------------------------------------------------------------------
//ETAP 5
std::map<int, int> evaluation::histogram(ostream& out) const
{
	map<int, int> m;

	//uzupe�nij: wype�nij map� m
	//do listy student�w zastosuj my_for_each oraz lambda
	//dla ka�dego wywo�aj jego metod� histogram




	//uzupe�nij: wypisz histogram (liczba punkt�w oraz odp. im liczba zada� oznaczona *)
	//do mapy m zastosuj my_for_each oraz lambda





	return m;
}
//----------------------------------------------------------------

