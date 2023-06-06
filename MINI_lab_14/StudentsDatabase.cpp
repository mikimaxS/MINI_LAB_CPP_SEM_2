#pragma once
#include <algorithm>
#include <list>
#include <map>
#include <fstream>

#include <iostream>

#include "StudentComparator.h"
#include "StudentDatabase.h"
using namespace std;

StudentDatabase::StudentDatabase(const std::list<Student>& students, const std::map<int, Course>& courses) :
        students(students), courses(courses) {}

std::ostream& operator<<(std::ostream& out, const StudentDatabase& database)
{
    for_each(database.students.begin(), database.students.end(), [&out, &database](const Student& s)
    {
        out << s.student_id << ": " << s.name << " - courses(" << s.courses.size() << "): ";

        for_each(s.courses.begin(), s.courses.end(), [&out, s, &database](const int c)
        {
            auto tmp = database.courses.find(c);

            if (database.courses.find(c) == database.courses.end()) {}
            else
            {
                out << (*tmp).second.course_name << " ";
            }
        });

        out << endl;
    });

    return out;
}

void StudentDatabase::addStudent(const Student& student)
{
    for_each(student.courses.begin(), student.courses.end(), [this, &student](const int i)
    {
        if (this->courses.find(i) == this->courses.end())
        {
            throw "Not a subject";
        }
        else
        {
            this->students.push_back(student);
        }
    });
}

void StudentDatabase::addCourse(const Course& course)
{
    if (this->courses.find(course.course_id) == this->courses.end())
        this->courses[course.course_id] = course;
}

void StudentDatabase::sort_students()
{
    this->students.sort();
}

void StudentDatabase::sort_students(StudentComparator::OrderBy order)
{
    StudentComparator comp = StudentComparator(order);

    this->students.sort(comp);
}

void StudentDatabase::save_to_file(const string& filename) const
{
    ofstream out(filename);

    if (!out) throw "cannot create such file\n";

    out << *this;

    out.close();
}

StudentDatabase StudentDatabase::load_from_file(const string& filename)
{
    ifstream in(filename);

    if (!in) throw "such file does not exist\n";

    StudentDatabase tmp_data;

    int iter;
    in >> iter; // how many iterations

    for (int i = 0; i < iter; ++i)
    {
        int id;
        string name;
        in >> id;
        in >> name;

        Course c_tmp(id, name);

        tmp_data.courses.insert(pair<int, Course>(id, c_tmp));
    }

    in >> iter; // how many iterations
    for (int i = 0; i < iter; ++i)
    {
        Student tmp_s;
        int iter_sbj;

        in >> tmp_s.student_id;
        in >> tmp_s.name;

        in >> iter_sbj;
        for (int j = 0; j < iter_sbj; ++j)
        {
            int id_sbj;
            in >> id_sbj;
            tmp_s.courses.push_back(id_sbj);
        }

        tmp_data.students.push_back(tmp_s);
    }

    in.close();

    return tmp_data;
}

Course StudentDatabase::course_with_most_students()
{
    map<int, int> how_many; // id | num

    for_each(this->students.begin(), this->students.end(), [&how_many](const Student& s)mutable
    {
        for_each(s.courses.begin(), s.courses.end(), [&how_many](const int& c_id)mutable
        {
            ++how_many[c_id];
        });
    });

    if (how_many.empty())
        throw logic_error("no courses\n");

    // finding the biggest element
    int max_el(0), max_el_id(0);
    for_each(how_many.begin(), how_many.end(), [&max_el_id, &max_el](const pair<int, int> p) mutable
    {
        if (p.second > max_el)
        {
            max_el = p.second;
            max_el_id = p.first;
        }
    });

    Course ret = this->courses[max_el_id];
    return ret;
}

void StudentDatabase::register_students_for_course(std::initializer_list<int> student_ids, int course_id)
{
    if (courses.find(course_id) == courses.end())
        throw logic_error("no such course exists");

    for_each(this->students.begin(), this->students.end(), [student_ids, course_id](Student& s)
    {
        bool is_in_the_students_{false};
        for (auto it: student_ids)
        {
            // the student is in the list
            if(it == s.student_id)
            {
                is_in_the_students_ = true;
                break;
            }
        }

        if (is_in_the_students_)
        {
            bool is_in_the_list_{false};
            for (auto it: s.courses)
            {
                if (it == course_id)
                    is_in_the_list_ = true;
                break;
            }

            if (!is_in_the_list_)
            {
                s.courses.push_back(course_id);
            }
        }
    });
}
