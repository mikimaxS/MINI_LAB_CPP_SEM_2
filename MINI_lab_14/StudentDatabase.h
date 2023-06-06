#pragma once

#include <list>
#include <map>
#include <ostream>
#include "Student.h"
#include "Course.h"
#include "StudentComparator.h"

class StudentDatabase {

    std::list<Student> students;
    std::map<int, Course> courses;

public:
    // ETAP 1 (2.5 pkt)
    StudentDatabase() = default;
    StudentDatabase(const std::list<Student>& students, const std::map<int, Course>& courses); // 0.5 pkt
    friend std::ostream& operator<<(std::ostream& out, const StudentDatabase& database); // 1 pkt
    void addStudent(const Student& student); // 0.5 pkt
    void addCourse(const Course& course); // 0.5 pkt

    // ETAP 2 (2 pkt)
    void sort_students(); // 0.5 pkt
    void sort_students(StudentComparator::OrderBy order); // 1.5 pkt

    // ETAP 3 (2.5 pts)
    void save_to_file(const std::string& filename) const; // 1 pkt
    static StudentDatabase load_from_file(const std::string& filename); // 1 pkt

    // ETAP 4 (3 pts)
    Course course_with_most_students(); // 1.5 pkt
    void register_students_for_course(std::initializer_list<int> student_ids, int course_id); // 1.5 pkt
};



