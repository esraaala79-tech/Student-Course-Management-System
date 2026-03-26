#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <set>

class Student : public Person {
protected:
    int id;
    double gpa;
    set<string> courses;

public:
    Student(int id, string name, double gpa);

    int getId();
    double getGpa();

    void addCourse(string course);
    void showCourses();
};

#endif