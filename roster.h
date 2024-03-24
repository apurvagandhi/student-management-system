#ifndef ROSTER_H
#define ROSTER_H

#include "degree.h" // Include the degree.h file where DegreeProgram is defined
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

class Roster {
private:
  int currentSize = 0;
  Student *classRosterArray[];

public:
  // Construtor
  Roster();
  ~Roster();
  void add(string studentID, string firstName, string lastName,
           string emailAddress, int age, int daysInCourse1, int daysInCourse2,
           int daysInCourse3, DegreeProgram degreeProgram);
  void remove(string studentID);
  void printAll(); /* not sure what to include*/
  void printAverageDaysInCourse(string studentID);
  void printInvalidEmails();
  void printByDegreeProgram(DegreeProgram degreeProgram);
  Student *getClassRosterArray();
  // Destructor to deallocate memory
  
};

#endif // ROSTER_H
