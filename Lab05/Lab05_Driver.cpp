///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab05_Driver.cpp
// Date: November 14, 2019
// Programmer: Samir Williams
//
// Description:
//		Sort student names, calculate student's average test scores
//			and letter grades. Counts the number of students recieving 
//			a particular letter grade.
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>
#include "Lab05_Header.h"

using namespace std;
using namespace manipulation;

int main() {

	ifstream inFile;
	string names[10];
	int tests[10][5];
	double averages[10];
	string letterGrades[10];
	
	inFile.open("inputFile.txt", ios::in);

	if (inFile.is_open()) {
		dataInput(inFile, names, tests);
		calculateGrade(tests, averages, letterGrades);
		selectionSort(names, tests, averages, letterGrades);
		dataOutput(names, tests, averages, letterGrades);
	}
	else {
		cout << "Error: File Not Found" << endl;
	}

	system("pause");
	return 0;
}
