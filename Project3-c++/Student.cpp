#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(int id, string name, double gpa)
    : Person(name) {
    this->id = id;
    this->gpa = gpa;
}

int Student::getId() {
    return id;
}

double Student::getGpa() {
    return gpa;
}

void Student::addCourse(string course) {
    courses.insert(course); 
}

void Student::showCourses() {
    for (auto c : courses) {
        cout << c << endl;
    }
}