#include <fstream>
#include <algorithm>

#include <map>
#include <iomanip>
#include "evaluation.h"

using namespace std;

//wystawianie ocen (tylko calkowite) na podstawie punktow: >=55p ocena 3; >=70p ocena 4; >=85p ocena 5
const map<int, student::marks, greater<int>> evaluation::levels{{57, student::marks::TRZY},
                                                                {70, student::marks::CZTERY},
                                                                {85, student::marks::PIEC}};

//ETAP 1
evaluation::evaluation(const string& file_name)
{
    ifstream in(file_name);

    if (!in) throw "err while reading file";

    string t_name, t_surname;
    int point;
    std::list<int> points;
    while (!in.eof())
    {
        in >> t_name >> t_surname;
        if (!in) break;

        points.clear();
        while (in >> point)
        {
            points.push_back(point);
        }
        in.clear();
        this->students.push_back(student{t_name, t_surname, points});
    }

    in.close();
}

ostream& operator<<(ostream& out, const evaluation& e)
{
    //do wypisania danych kolejnych studentów zastosuj for_each oraz lambda
    //(w której wykorzystaj operator<< dla studenta)

    for_each(e.students.begin(), e.students.end(), [&out](student s)
    {
        out << s << std::endl;
    });

    return out;
}

//---------------------------------------------------------------
//ETAP 2
void evaluation::sort()    //sortowanie wg surname, name (studenta)
{
    //dla listy studentów wykonaj sortowanie wg surname oraz name
    //dla metody sort listy zdefiniuj odpowiednie lambda
    this->students.sort([](const student& a, const student& b) -> bool
                        {
                            if (a.surname > b.surname)
                            {
                                return false;
                            }
                            else if (a.surname == b.surname)
                            {
                                if (a.name > b.name)
                                    return false;
                                else
                                    return true;
                            }
                            else
                            {
                                return true;
                            }
                        });
}
//---------------------------------------------------------------
//ETAP 3

void evaluation::set_marks()
{
    //dla kolejnych studentów wystaw ocene (mark)
    //do przegl¹dania listy studentów zastosuj for_each
    //do ustalenia oceny studenta na podstawie sumy punktów, zastosuj find_if dla mapy levels (lub metode lower_bound)
    //zdefiniuj odpowiednie lambda
    for_each(this->students.begin(), this->students.end(), [](student& s)
    {
        int tmp = s.sum_of_points();
        // cout << "*******" << tmp;
        auto it = levels.lower_bound(tmp);
        if (it != levels.end())
        {
            s.mark = it->second;
        }
    });
}

void evaluation::reset_points(const int& p)
{
    //wszystkim studentom za kazde oddane zadanie (>0) podnieœ punkty o +p
    //(punkty dodajemy tylko do zadania ocenione go na wiecej niz 0)
    //dla listy kolejnych studentów zastosuj for_each
    //a do modyfukacji listy punktów zastosuj transform oraz odpowiednie lambda
    for_each(students.begin(), students.end(), [p](student& s)
    {
//        for_each(s.points.begin(), s.points.end(), [p](int & grade)
//        {
//            if (grade > 0)
//            {
//                grade += p;
//            }
//        });
        transform(s.points.begin(), s.points.end(), s.points.begin(), [p](int orginal_points)
        {
            if (orginal_points > 0)
            {
                return orginal_points + p;
            }
            else
            {
                return orginal_points;
            }
        });
    });
}

//---------------------------------------------------------------
//ETAP 4
void evaluation::clear_not_passing()
{
    //usun studentów, którzy nie uzyskuja zaliczenia
    //zastosuj metode remove_if dla listy students oraz lambda
    this->students.remove_if([](student& s)
                             {
                                 if (s.mark == student::marks::DWA)
                                 {
                                     return true;
                                 }
                                 else
                                 {
                                     return false;
                                 }
                             });
}

//---------------------------------------------------------------------
//ETAP 5
std::map<int, int> evaluation::histogram(ostream& out) const
{
    map<int, int> m;

    //wypelnij mape m
    //do listy studentów zastosuj for_each oraz lambda
    //dla kazdego wywolaj jego metode add_to_histogram
    for_each(this->students.begin(), this->students.end(), [&m](const student& s)
    {
        s.add_to_histogram(m);
    });


    //uzupelnij: wypisz histogram (liczba punktów oraz odp. im liczba zadan oznaczona *)
    //do mapy m zastosuj for_each oraz lambda
    for_each(m.begin(), m.end(), [&out](std::pair<int, int> p)
    {
        out << "pkt" << setw(4) << right << p.first << ": ";
        for (int i = 0; i < p.second; ++i)
        {
            out << "*";
        }
        out << endl;
    });

//    for_each(m.begin(), m.end(), [&out](std::pair<int, int> p)
//    {
//        out << "(" << p.first << "," << p.second << ")";
//    });
//    out << endl;

    return m;
}

//----------------------------------------------------------------

