#include <iostream>
#include <list>
#include <map>

#include "Student.h"
#include "Course.h"
#include "StudentDatabase.h"

int main()
{

    std::cout << "******************** PART 1 ********************\n\n";

    std::map<int, Course> courses{
            {1, {1, "Calculus"}},
            {2, {2, "Algebra"}},
            {3, {3, "Programming"}},
            {4, {4, "Networking"}},
    };
    std::list<Student> students{
            {4, "John",  {1, 2}},
            {2, "Alice", {3, 2, 4}},
            {1, "Ben",   {2}},
            {3, "Emma",  {1, 2, 3, 4, 10}},
    };

    StudentDatabase database{students, courses};
    std::cout << database << std::endl;

    database.addCourse({10, "Databases"});
    database.addCourse({10, "DiscreteMaths"}); // NO EFFECT
    database.addStudent({10, "Jacob", {10}});

    std::cout << database << std::endl;

    std::cout << "******************** PART 2 ********************\n\n";

    std::cout << "Sorted by student ID (ascending)" << std::endl;
    database.sort_students();
    std::cout << database << std::endl;

    std::cout << "Sorted by student name (ascending)" << std::endl;
    database.sort_students(StudentComparator::OrderBy::NAME_ASCENDING);
    std::cout << database << std::endl;

    std::cout << "Sorted by course count (descending)" << std::endl;
    database.sort_students(StudentComparator::OrderBy::COURSES_COUNT_DESCENDING);
    std::cout << database << std::endl;

    std::cout << "******************** PART 3 ********************\n\n";

    std::cout << "Saving to my_output.txt" << std::endl;
    database.save_to_file("my_output.txt");

    StudentDatabase from_file = StudentDatabase::load_from_file("example_input.txt");
    std::cout << from_file << std::endl;

    std::cout << "******************** PART 4 ********************\n\n";

    Course result = database.course_with_most_students();
    std::cout << "Course with most students: " << result.course_name << std::endl << std::endl;

    database.register_students_for_course({10, 2}, 3); // PROGRAMMING
    database.register_students_for_course({1, 2, 3, 4, 10}, 1); // CALCULUS

    std::cout << database << std::endl;

    result = database.course_with_most_students();
    std::cout << "Course with most students: " << result.course_name << std::endl << std::endl;

    return 0;
}