#pragma once

#include <string>
#include <vector>

struct Student
{
    int student_id;
    std::string name;
    std::vector<int> courses;

public:
    Student() = default;

    Student(int studentId, const std::string& name) : student_id(studentId), name(name) {}

    Student(int studentId, const std::string& name, std::vector<int> courses) :
            student_id(studentId), name(name), courses(courses) {}

    // TODO comparison operator
    friend bool operator<(const Student& s1, const Student& s2)
    {
        if (s1.student_id < s2.student_id)
        {
            return true;
        }
        return false;
    }

};

