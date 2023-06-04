#include <algorithm>
#include <numeric>

#include <iomanip>
using namespace std;
#include "student.h"


//-------------------------------------------------------------------
student::student(const std::string& n, const std::string& s, const std::list<int>& p) : name(n), surname(s),
                                                                                        points(p) {}

//-------------------------------------------------------------------
std::ostream& operator<<(std::ostream& out, const student& st)
{
    out << setw(12) << left << st.surname << setw(12) << left << st.name << ", ocena: ";

    switch (st.mark)
    {
        case student::marks::DWA:
            out << 2;
            break;
        case student::marks::TRZY:
            out << 3;
            break;
        case student::marks::CZTERY:
            out << 4;
            break;
        case student::marks::PIEC:
            out << 5;
            break;
    }

    out << ":  ";

    for_each(st.points.begin(), st.points.end(), [&out](int tmp) -> std::ostream&
    {
        out << tmp << " ";
        return out;
    });

    out << endl;
    return out;
}

//--------------------------------------------------------------------
int student::sum_of_points() const
{
    //do obliczenia sumy punktów zastosuj accumulate oraz lambda
    return std::accumulate(this->points.begin(), this->points.end(), 0);
}

//------------------------------------------------------------------
void student::add_to_histogram(std::map<int, int>& m) const
{
    //uzupelnij tworzenie mapy histogramu
    //dla listy punktów zastosuj for_each oraz lambda
    for (int i = 0; i < 20; ++i)
    {
        m.insert(std::pair<int, int>(i, 0));
    }

    for_each(this->points.begin(), this->points.end(), [&m](int p)
    {
        auto it = m.begin();
        advance(it, p);

        ++it->second;
    });

    for (auto it = m.begin(); it != m.end();)
    {
        if (it->second == 0)
            it = m.erase(it);
        else
            ++it;
    }
}

//------------------------------------------------------------------

