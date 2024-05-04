#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;


//all function calls (sets, gets, and constructors)

Student::Student(string stdID, string fn, string ln, string email, int a, int courseDays[], DegreeProgram degreeprog) {
	setStudentID(stdID);
	setFirstName(fn);
	setLastName(ln);
	setemailAddress(email);
	setAge(a);
	setDaysInCourse(courseDays);
	setDegreeProgram(degreeprog);
}
void Student::setStudentID(string stdID) {
	studentID = stdID;
}
void Student::setFirstName(string fn) {
	firstName = fn;
}
void Student::setLastName(string ln) {
	lastName = ln;
}
void Student::setemailAddress(string email) {
	emailAddress = email;
}
void Student::setAge(int a) {
	age = a;
}
void Student::setDaysInCourse(int courseDays[]) {
	daysInCourse[0] = courseDays[0];
	daysInCourse[1] = courseDays[1];
	daysInCourse[2] = courseDays[2];
	
}
void Student::setDegreeProgram(DegreeProgram degreeprog) {
	degreeprogram = degreeprog;
}
//get functions
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getDaysInCourse() {
	return daysInCourse;
}
DegreeProgram Student::getDegreeProgram() {
	return degreeprogram;
}

void Student::print() {
	string degreeProgramStr;
	if (degreeprogram == DegreeProgram::NETWORK) {
		degreeProgramStr = "NETWORK";
	}
	else if (degreeprogram == DegreeProgram::SECURITY) {
		degreeProgramStr = "SECURITY";
	}
	else if (degreeprogram == DegreeProgram::SOFTWARE) {
		degreeProgramStr = "SOFTWARE";
	}
	
	cout << studentID << "\t" << firstName << "\t" << lastName << "\t" << emailAddress << "\t"
		<< age << "\t" << "{" << daysInCourse[0] << "," << daysInCourse[1] << "," <<daysInCourse[2] << "}" << "\t" << degreeProgramStr << endl;

}


