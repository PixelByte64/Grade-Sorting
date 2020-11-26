///////////////////////////////////////////////////////////////////////
//
// Header: Lab05_Header                                          
//                                                                   
// Description:
//    Holds function protoypes to be used by Lab05 files      
//
//    List of member functions:
//	  void dataInput()
//    void calculateGrade()
//    void selectionSort()
//    void sort() : Uses template for the arrayToSort and minValue
//	  void dataOutput()
// 
///////////////////////////////////////////////////////////////////////

#pragma once

#include<fstream>
#include<string>

using namespace std;

namespace manipulation {

	void dataInput(ifstream& inFile, string names[], int tests[][5]);
	
	void calculateGrade(int tests[][5], double averages[], string letterGrades[]);
	
	void selectionSort(string names[], int tests[][5], double averages[], string letterGrades[]);
	
	template <typename T>
	void sort(T arrayToSort[] ,T& minValue, int& minIndex, int& swapIndex);
	
	void dataOutput(const string names[], const int tests[][5], const double averages[], const string letterGrades[]);

};