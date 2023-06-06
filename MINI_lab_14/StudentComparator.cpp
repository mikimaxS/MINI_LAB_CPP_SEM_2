#include "StudentComparator.h"


bool StudentComparator::operator()(const Student& s1, const Student& s2)
{
    if (order == StudentComparator::OrderBy::COURSES_COUNT_DESCENDING)
    {
        if (s1.courses.size() > s2.courses.size())
        {
            return true;
        }
        return false;
    }
    else if (order == StudentComparator::OrderBy::NAME_ASCENDING)
    {
        if (s1.name < s2.name)
        {
            return true;
        }
        return false;
    }
    else
    {
        throw "sth wrong";
    }
}
