#pragma once

#include <string>

struct Course {
    int course_id;
    std::string course_name;

    Course() = default;
    Course(int courseId, const std::string& courseName)
            : course_id(courseId), course_name(courseName) {}
};
