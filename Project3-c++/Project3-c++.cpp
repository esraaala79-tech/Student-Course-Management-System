#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Student.h"

using namespace std;

vector<Student> students;


void addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";
    cin >> id;

    for (auto s : students) {
        if (s.getId() == id) {
            cout << "ID already exists!\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter GPA: ";
    cin >> gpa;

    if (gpa < 0 || gpa > 4) {
        cout << "Invalid GPA!\n";
        return;
    }

    students.push_back(Student(id, name, gpa));
    cout << "Student added!\n";
}

void removeStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            cout << "Removed!\n";
            return;
        }
    }

    cout << "Not found\n";
}

void searchStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto s : students) {
        if (s.getId() == id) {
            cout << s.getName() << " - GPA: " << s.getGpa() << endl;
            return;
        }
    }

    cout << "Not found\n";
}

void displayStudents() {
    for (auto s : students) {
        cout << s.getId() << " - "
            << s.getName() << " - "
            << s.getGpa() << endl;
    }
}

void enrollCourse() {
    int id;
    string course;

    cout << "Enter ID: ";
    cin >> id;

    for (auto& s : students) {
        if (s.getId() == id) {
            cout << "Enter Course: ";
            cin >> course;

            s.addCourse(course);
            cout << "Added course\n";
            return;
        }
    }

    cout << "Student not found\n";
}

void showCourses() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (auto s : students) {
        if (s.getId() == id) {
            s.showCourses();
            return;
        }
    }

    cout << "Student not found\n";
}

void sortStudents() {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.getGpa() > b.getGpa();
        });

    cout << "Sorted!\n";
}

void saveToFile() {
    ofstream file("students.txt");

    for (auto s : students) {
        file << s.getId() << " "
            << s.getName() << " "
            << s.getGpa() << endl;
    }

    file.close();
    cout << "Saved!\n";
}

void loadFromFile() {
    ifstream file("students.txt");

    int id;
    string name;
    double gpa;

    while (file >> id >> name >> gpa) {
        students.push_back(Student(id, name, gpa));
    }

    file.close();
    cout << "Loaded!\n";
}

//  Search by Name 
void searchByName() {
    string name;
    cout << "Enter Name: ";
    cin >> name;

    for (auto s : students) {
        if (s.getName() == name) {
            cout << s.getId() << " - "
                << s.getName() << " - "
                << s.getGpa() << endl;
        }
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n1.Add\n2.Remove\n3.Search\n4.Display\n";
        cout << "5.Enroll\n6.Show Courses\n7.Sort\n";
        cout << "8.Save\n9.Load\n10.Search by Name\n11.Exit\n";

        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) removeStudent();
        else if (choice == 3) searchStudent();
        else if (choice == 4) displayStudents();
        else if (choice == 5) enrollCourse();
        else if (choice == 6) showCourses();
        else if (choice == 7) sortStudents();
        else if (choice == 8) saveToFile();
        else if (choice == 9) loadFromFile();
        else if (choice == 10) searchByName();
        else break;
    }

    return 0;
}