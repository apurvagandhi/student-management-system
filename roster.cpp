#include "roster.h"
#include "degree.h" // Include degree.h before including student.h
#include "student.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector> // Added include directive for vector

using namespace std;

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Shiv,Patel,spatel@wgu.edu,22,14,15,16,SOFTWARE"};

Roster::Roster() {
  for (int i = 0; i < sizeof(studentData) / sizeof(studentData[0]); i++) {
    vector<string> v;
    char *temp = new char[studentData[i].length() + 1];
    strcpy(temp, studentData[i].c_str());
    char *token = strtok(temp, ",");
    while (token != NULL) {
      v.push_back(token);
      token = strtok(NULL, ",");
    }

    if (v[8] == "NETWORK") {
      classRosterArray[i] =
          new Student(v[0], v[1], v[2], v[3], stoi(v[4]), stoi(v[5]),
                      stoi(v[6]), stoi(v[7]), DegreeProgram::NETWORK);
    } else if (v[8] == "SECURITY") {
      classRosterArray[i] =
          new Student(v[0], v[1], v[2], v[3], stoi(v[4]), stoi(v[5]),
                      stoi(v[6]), stoi(v[7]), DegreeProgram::SECURITY);
    } else if (v[8] == "SOFTWARE") {
      classRosterArray[i] =
          new Student(v[0], v[1], v[2], v[3], stoi(v[4]), stoi(v[5]),
                      stoi(v[6]), stoi(v[7]), DegreeProgram::SOFTWARE);
    }
    currentSize++;
  }
}

void Roster::printAll() {
  for (int i = 0; i < currentSize; i++) {
    if (classRosterArray[i] != nullptr) {
      cout << "Student " << i + 1 << ":" << endl;
      cout << "test";
      cout << classRosterArray[i]->getStudentId() << endl;
      classRosterArray[i]->print();
    }
  }
  cout << currentSize;
}

void Roster::remove(string id) {
  for (int i = 0; i < currentSize; i++) {
    if (classRosterArray[i] != nullptr &&
        classRosterArray[i]->getStudentId() == id) {
      delete classRosterArray[i];
      classRosterArray[i] = nullptr;
      cout << "Student removed with id number " << id << endl;
      return;
    }
  }
  cout << "Student with id number " << id << " not found" << endl;
}

void Roster::add(string studentId, string firstName, string lastName,
                 string email, int age, int daysInCourse1, int daysInCourse2,
                 int daysInCourse3, DegreeProgram degreeProgram) {

  classRosterArray[currentSize] =
      new Student(studentId, firstName, lastName, email, age, daysInCourse1,
                  daysInCourse2, daysInCourse3, degreeProgram);
  currentSize++;
}

void Roster::printAverageDaysInCourse(string studentId) {
  for (int i = 0; i < currentSize; i++) {
    if (studentId == classRosterArray[i]->getStudentId()) {
      cout << "Average days in course for student " << studentId << ": "
           << ((classRosterArray[i]->getDaysInCourse()[0] +
                classRosterArray[i]->getDaysInCourse()[1] +
                classRosterArray[i]->getDaysInCourse()[2]) /
               3)
           << endl;
    }
  }
}

void Roster::printInvalidEmails() {
  for (int i = 0; i < currentSize; i++) {
    size_t at = classRosterArray[i]->getEmailAddress().find("@");
    if (at == std::string::npos) {
      cout << classRosterArray[i]->getEmailAddress() << endl;
    }

    size_t dot = classRosterArray[i]->getEmailAddress().find(".");
    if (dot == std::string::npos) {
      cout << classRosterArray[i]->getEmailAddress() << endl;
    }

    size_t space = classRosterArray[i]->getEmailAddress().find(" ");
    if (space != std::string::npos) {
      cout << classRosterArray[i]->getEmailAddress() << endl;
    }
  }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
  for (int i = 0; i < currentSize; i++) {
    if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
      classRosterArray[i]->print();
    }
  }
}

Roster::~Roster() {
  cout << "Destructor called to deallocate memory taken up by student roster"
       << endl;
  for (int i = 0; i < currentSize; i++) {
    cout << "Student " << i + 1 << " destroyed!" << endl;
    if (classRosterArray[i] != nullptr) {
      delete classRosterArray[i]; // we delete the memory at classrosterarray[i]
      classRosterArray[i] =
          nullptr; // we make that memory point to nothing no address
    }
  }
};
