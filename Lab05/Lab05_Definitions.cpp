///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Lab05_Definitions.cpp
// Date: November 14, 2019
// Programmer: Samir Williams           
//
// Description:
//    Holds the function definitions for Lab 05
//                                                                  
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "Lab05_Header.h"

using namespace std;
using namespace manipulation;

//Function Definitions
///////////////////////////////////////////////////////////////////////
//
// Function: dataInput                                          
//                                                                   
// Description:
//    Extracts data from the given file
//
// Parameters:  
//    inFile  : Reference to the input file         
//    names[] : Array to hold the input file names               
//    tests[][5] : Multi-Dimensional Array to hold the input file test scores                                                                   
//                                            
///////////////////////////////////////////////////////////////////////
void manipulation::dataInput(ifstream& inFile, string names[], int tests[][5]) {

	int counter = 0;

	while (!inFile.eof() && counter < 10) {
		inFile >> names[counter];
		for (int i = 0; i < 5; i++) {
			inFile >> tests[counter][i];
		}
		counter++;
	}
}

///////////////////////////////////////////////////////////////////////
//
// Function: calculateGrade                                         
//                                                                   
// Description:
//    takes data from the arrays and finds the average grade as well as
//		the corresponding letter grade
//
// Parameters:  
//    tests[][5] : Multi-Dimensional Array of test score data          
//    averages[] : Array to hold the average grade found from test scores               
//    letterGrades[] : Array to hold the letter grade of the average found                                                                  
//                                            
///////////////////////////////////////////////////////////////////////
void manipulation::calculateGrade(int tests[][5], double averages[], string letterGrades[]) {

	double averageGrade = 0;

	for (int i = 0; i < 10; i++) {
		averageGrade = 0;
		for (int j = 0; j < 5; j++) {
			averageGrade += tests[i][j];
		}
		
		averageGrade /= 5.0;

		averages[i] = averageGrade;

		if (averageGrade >= 90) {
			letterGrades[i] = "A";
		}
		else if (averageGrade > 80 && averageGrade < 90) {
			letterGrades[i] = "B";
		}
		else if (averageGrade > 70 && averageGrade < 80) {
			letterGrades[i] = "C";
		}
		else if (averageGrade > 60 && averageGrade < 70) {
			letterGrades[i] = "D";
		}
		else if (averageGrade < 60) {
			letterGrades[i] = "F";
		}
	}
	
}

///////////////////////////////////////////////////////////////////////
//
// Function: selectionSort                                          
//                                                                   
// Description:
//    Sorts all of the arrays given by data in the name array
//
// Parameters:  
//    names[] : Array of names to be sorted        
//    tests[][5] : Multi-Dimensional Array of tests to be sorted               
//    averages[] : Array of averages to be sorted
//	  letterGrades[] : Array of letter grades to be sorted
//                                            
///////////////////////////////////////////////////////////////////////
void manipulation::selectionSort(string names[], int tests[][5], double averages[], string letterGrades[]) {
	
	int minIndex;
	string minNameValue;
	int minTestValue;
	double minAvgValue = 0;
	string minGradeValue;

	for (int i = 0; i < 10; i++) {
		minIndex = i;
		
		for (int j = i + 1; j < 10; j++) {
			
			if (names[j] < names[minIndex]) {
				minIndex = j;
			}
		}	
		sort(names, minNameValue, minIndex, i);
		for (int j = 0; j < 5; j++) {
			minTestValue = tests[minIndex][j];
			tests[minIndex][j] = tests[i][j];
			tests[i][j] = minTestValue;
		}
		sort(averages, minAvgValue, minIndex, i);
		sort(letterGrades, minGradeValue, minIndex, i);
	}
}

///////////////////////////////////////////////////////////////////////
//
// Function: sort                                          
//                                                                   
// Description:
//    Swaps the elements in the array given
//
// Parameters:  
//    arrayToSort[] : Array of data to swap elements in          
//    minValue : Temporary minimum value              
//    minIndex : Current minimum index to sort by      
//	  swapIndex : Current index to swap with
//                                            
///////////////////////////////////////////////////////////////////////
template <typename T>
void manipulation::sort(T arrayToSort[] ,T& minValue, int& minIndex, int& swapIndex) {

	minValue = arrayToSort[minIndex];
	arrayToSort[minIndex] = arrayToSort[swapIndex];
	arrayToSort[swapIndex] = minValue;

}

///////////////////////////////////////////////////////////////////////
//
// Function: dataOutput                                          
//                                                                   
// Description:
//    Outputs the data given and also finds each grades count
//
// Parameters:  
//    names[] : Array of names to output          
//    tests[][5] : Multi-Dimensional Array of tests to output               
//    averages[] : Array of averages to output
//    letterGrades[] : Arrat of letterGrades to manipulate
//                                            
///////////////////////////////////////////////////////////////////////

void manipulation::dataOutput(const string names[], const int tests[][5], const double averages[], const string letterGrades[]) {

	int gradeACounter = 0;
	int gradeBCounter = 0;
	int gradeCCounter = 0;
	int gradeDCounter = 0;
	int gradeFCounter = 0;

	//Output Array Data
	cout.setf(ios_base::left);
	cout << setw(12) << "Name" << setw(10) << "Test1" << setw(10) << "Test2" << setw(10) << "Test3" << setw(10) << "Test4" 
		<< setw(10) << "Test 5" << setw(10) << "Average" << setw(10) << "Grade" << endl;

	for (int i = 0; i < 10; i++) 
	{
		cout << setw(12) << names[i];
		for (int j = 0; j < 5; j++) {
			cout << setw(10) << tests[i][j];
		}
		cout << setw(10) << averages[i];
		cout << setw(10) << letterGrades[i] << endl;
	}

	//Count Grades
	for (int i = 0; i < 10; i++) {
		string gradeToCheck = letterGrades[i];
		if (gradeToCheck == "A") {
			gradeACounter++;
		}
		else if (gradeToCheck == "B") {
			gradeBCounter++;
		}
		else if (gradeToCheck == "C") {
			gradeCCounter++;
		}
		else if (gradeToCheck == "D") {
			gradeDCounter++;
		}
		else if (gradeToCheck == "F") {
			gradeFCounter++;
		}
	}

	//Output Counter Data
	if (gradeACounter == 1) {
		cout << "There is " << gradeACounter << " person with letter grade \"A\"" << endl;
	}
	else {
		cout << "There are " << gradeACounter << " people with letter grade \"A\"" << endl;
	}

	if (gradeBCounter == 1) {
		cout << "There is " << gradeBCounter << " person with letter grade \"B\"" << endl;
	}
	else {
		cout << "There are " << gradeBCounter << " people with letter grade \"B\"" << endl;
	}

	if (gradeCCounter == 1) {
		cout << "There is " << gradeCCounter << " person with letter grade \"C\"" << endl;
	}
	else {
		cout << "There are " << gradeCCounter << " people with letter grade \"C\"" << endl;
	}

	if (gradeDCounter == 1) {
		cout << "There is " << gradeDCounter << " person with letter grade \"D\"" << endl;
	}
	else {
		cout << "There are " << gradeDCounter << " people with letter grade \"D\"" << endl;
	}

	if (gradeFCounter == 1) {
		cout << "There is " << gradeFCounter << " person with letter grade \"F\"" << endl;
	}
	else {
		cout << "There are " << gradeFCounter << " people with letter grade \"F\"" << endl;
	}

}

