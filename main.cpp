#include "degree.h"
#include "roster.h"
#include "student.h"
#include <iostream>
using namespace std;

int main() {

  string courseTitle = "Scripting and Programming Appication";
  string programmingLanguage = "C++";
  string wguID = "011415280";
  string name = "Shiv Patel";

  cout << courseTitle << endl;
  cout << programmingLanguage << endl;
  cout << "WGU ID: " << wguID << endl;
  cout << name << endl;
  cout << endl;

  Roster roster; // Creating an instance of the Roster class
  cout << "CALLING PRINT ALL:" << endl;
  roster.printAll();
  cout << endl;

  
  cout << "CALLING INVALID EMAILS:" << endl;
  roster.printInvalidEmails();
  cout << endl;
  
  /* cout << "CALLING AVERAGE DAYS:" << endl;
  for (int i = 0; i < 5; i++) {
    roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentId());
  }
 */
  
  cout << endl;

  // // Print students by degree by program
  cout << "CALLING STUDENTS BY DEGREE PROGRAMS:" << endl;
  roster.printByDegreeProgram(SOFTWARE);
  cout << endl;

  // Remove student from roster
  cout << "CALLING REMOVE STUDENT:" << endl;
  roster.remove("A3");
  cout << endl;

  roster.printAll();
  cout << endl;
  
  roster.remove("A3");

  return 0;
}