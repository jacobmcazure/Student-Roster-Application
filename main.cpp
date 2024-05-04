#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;


int main() {
	//Print course title, language used, wgu id, full name
	cout << "C867-Scripting and Programming\nLanguage: C++\nStudent ID: #001510647\nName: Jacob McEwen" << endl << endl;
	//studentdata input data
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jacob,McEwen,jmcewe8@wgu.edu,22,44,48,60,SOFTWARE" };


	Roster classRoster;

	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}
	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray(i)->getStudentID());
	}
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	return 0;
}