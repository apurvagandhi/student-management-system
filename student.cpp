#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Student::Student(string newStudentID, string newFirstName, string newLastname,
                 string newEmailAddress, int newAge, int newDaysInCourse1,
                 int newDaysInCourse2, int newDaysInCourse3,
                 DegreeProgram newDegreeProgram) {

  studentId = newStudentID;
  firstName = newFirstName;
  lastName = newLastname;
  emailAddress = newEmailAddress;
  age = newAge;
  daysInCourse[0] = newDaysInCourse1;
  daysInCourse[1] = newDaysInCourse2;
  daysInCourse[2] = newDaysInCourse3;
  degreeProgram = newDegreeProgram;
}

// Setters
void Student::setStudentId(string newStudentId) { studentId = newStudentId; }

void Student::setFirstName(string newFirstName) { firstName = newFirstName; }

void Student::setLastname(string newLastname) { lastName = newLastname; }

void Student::setEmailAddress(string newEmailAddress) {
  emailAddress = newEmailAddress;
}

void Student::setAge(int newAge) { age = newAge; }

void Student::setDaysInCourse(int newDaysInCourse[]) {
  for (int i = 0; i < 3; i++) {
    daysInCourse[i] = newDaysInCourse[i];
  }
}

void Student::setDegreeProgram(DegreeProgram newDegreeProgram) {
  degreeProgram = newDegreeProgram;
}

// Getters
string Student::getStudentId() { return studentId; }

string Student::getFirstName() { return firstName; }

string Student::getLastname() { return lastName; }

string Student::getEmailAddress() { return emailAddress; }

int Student::getAge() { return age; }

int *Student::getDaysInCourse() { return daysInCourse; }

DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

void Student::print() {
  cout << studentId << "\t";
  cout << "First Name: " << firstName << "\t";
  cout << "Last Name: " << lastName << "\t";
  cout << "Email: " << emailAddress << "\t";
  cout << "Age: " << age << endl;
  cout << "Days In Course: "
       << (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3.0 << "\t";
  switch (degreeProgram) {
  case 0:
    cout << "Degree Program: SECURITY " << endl;
    ;
    break;
  case 1:
    cout << "Degree Program: NETWORK" << endl;
    ;
    break;
  case 2:
    cout << "Degree Program: SOFTWARE  " << endl;
    ;
    break;
  default:
    cout << "Degree Program: UNKNOWN" << endl;
    ;
  }
}

// Student student5 = new Student("A5", "Shiv", "Patel", "patelshiv@gmail.com",
// 69, 30, 20, 50, SOFTWARE)
