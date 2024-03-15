#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
  string studentId;
  string firstName;
  string lastName;
  string emailAddress;
  int age;
  int daysInCourse[3];
  DegreeProgram degreeProgram;

public:
  Student(string newStudentID, string newFirstName, string newLastname,
          string newEmailAddress, int newAge, int newDaysInCourse1,
          int newDaysInCourse2, int newDaysInCourse3,
          DegreeProgram newDegreeProgram);

  void setStudentId(string newStudentId);
  void setFirstName(string newFirstName);
  void setLastname(string newLastname);
  void setEmailAddress(string newEmailAddress);
  void setAge(int newAge);
  void setDaysInCourse(int newDaysInCourse[]);
  void setDegreeProgram(DegreeProgram newDegreeProgram);
  void print();

  string getStudentId();
  string getFirstName();
  string getLastname();
  string getEmailAddress();
  int getAge();
  int *getDaysInCourse();
  DegreeProgram getDegreeProgram();
};
#endif