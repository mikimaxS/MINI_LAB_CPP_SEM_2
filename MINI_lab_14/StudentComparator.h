#pragma once
#include "Student.h"

class StudentComparator
{
public:
    enum class OrderBy
    {
        NAME_ASCENDING,
        COURSES_COUNT_DESCENDING,
    };

    StudentComparator::OrderBy order;

    bool operator()(const Student& s1, const Student& s2);

    StudentComparator(StudentComparator::OrderBy order) : order(order) {};
};