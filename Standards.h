//-------------------------------------------------------------------------------------------------
//File Name: Standard.h
//Associated File: Standard.cpp
//Contains:
// This header file contains the standard header files needed for any basic program and the 
//	constants that will be printed as the header for the entire program
// This header file also includes the prototype for the PrintDivider, PrintCenteredMessage, 
//  PrintFileName, and PrintCourseHeading functions.
//
//-------------------------------------------------------------------------------------------------

#ifndef Standards_h
#define Standards_h

//Include header file for input and output streams
#include <iostream>

//Include header file for string variables
#include <string>

//Include header file for file streams
#include <fstream>

//Include header file for input and output manipulations
#include <iomanip>

using namespace std;

//Constant for the college name
const string COLLEGE = "SUNY Broome";

//Constant for the program name
const string PROGRAM = "CST 202 - Lab 1";

//Constant for the programmer's name
const string NAME = "Giovanni Coppola";

//Constant for the screen width
const int SCREEN_WIDTH = 100;

//Constant for the max size of the array
const int MAX_ELEMENTS = 10;

//Prototype for the PrintDivider function to the output file
void PrintDivider(ofstream& fout, char symbol, int width);

//Prototype for the PrintDivider function to the console
void PrintDivider(char symbol, int width);

//Prototype for the PrintCenteredMessage function to the output file
void PrintCenteredMessage(ofstream& fout, string message, int width);

//Prototype for the PrintCourseHeading function to the output file
void PrintCourseHeading(ofstream& fout, string college, string program, string name, int width);

//Prototype for the PrintCourseHeading function to the console
void PrintCourseHeading(string college, string program, string name, int width);

//Prototype for the PrintFileName function
void PrintFileName(string fileName);

#endif // !Standards_h