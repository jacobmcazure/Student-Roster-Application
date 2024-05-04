#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;



class Student {
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	
	DegreeProgram degreeprogram;
public:
	
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeprogram);

	void setStudentID(string);
	void setFirstName(string);
	void setLastName(string);
	void setemailAddress(string);
	void setAge(int);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	void print();
	

};
