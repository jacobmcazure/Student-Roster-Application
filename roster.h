#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;


class Roster {
private:
	Student* classRosterArray[5];
public:
	int i = 0; 
	Student* getClassRosterArray(int j);
	~Roster();
	void parse(string data);
	void add(string, string, string, string, int, int, int, int, DegreeProgram);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void remove(string studentID);
	void printByDegreeProgram(DegreeProgram);

};