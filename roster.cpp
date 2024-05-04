#include <iostream>
#include <string>
#include "roster.h"
#include "degree.h"

using namespace std;


void Roster::parse(string data)
{
		//function to parse through studentdata string array
		size_t rhs = data.find(",");
		string studentID = data.substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string firstName = data.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string lastName = data.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string emailAddress = data.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int age = stoi(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = data.find(",", lhs);
		string strDegreeProgram = data.substr(lhs, rhs - lhs);

		DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
		if (strDegreeProgram == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
		}
		else if (strDegreeProgram == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}
		else if (strDegreeProgram == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}

		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
	i++;
}
Student* Roster::getClassRosterArray(int j) {
	return classRosterArray[j]; //return indexed student object
}
void Roster::printAll() {
	cout << "Displaying all Students: " << endl << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->print();
		}
		
		
	}
	cout << endl;
}
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails:" << endl << endl;
	for (int i = 0; i < 5; i++) {
		string currentEmail = classRosterArray[i]->getEmailAddress();
		if (currentEmail.find("@") != string::npos && currentEmail.find(".") != string::npos && currentEmail.find(" ") == string::npos) {
			
		}
		else {
			cout << currentEmail << " -  is invalid." << endl;
		}
	}
	cout << endl;
}
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		//string currStudID = classRosterArray[i]->getStudentID();
		//int currStudAvgDays = classRosterArray[i]->getDaysInCourse();
		if (classRosterArray[i]->getStudentID() == studentID) {
			
			int avgDays = (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]->getDaysInCourse()[2]) / 3;
			cout << "Student ID: " << studentID << ", average days in course is: " << avgDays << endl;
		}
	} 
	cout << endl;
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Showing students in degree program: SOFTWARE" << endl << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}
void Roster::remove(string studentID) {
	cout << "Removing " << studentID << ":" << endl << endl;
	bool sID = false;
	int i = 0;
	while ((sID == false) && (i < 5)) {
		//if (classRosterArray[i]->getStudentID() == "") {
		//}
		if (classRosterArray[i] != NULL && classRosterArray[i]->getStudentID() == studentID) {
			sID = true;
			delete classRosterArray[i];
			for (int j = i; j < 4; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			classRosterArray[4] = NULL;
			cout << "Student identified as A3 has been removed" << endl;
		}
		i++;	
	}
	if (sID == false) {
		cout << "The student with the ID: A3 was not found." << endl;
	}
	cout << endl;
}
Roster::~Roster() {

	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
	cout << "Destructor called";
}