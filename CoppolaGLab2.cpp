//-------------------------------------------------------------------------------------------------
//File Name: CoppolaGLab2.cpp
//Associated File: Standard.h
//Contains:
//  Task 0:
//      InputArrayElements - Function to scan in elements to a one dimensional array
//      OutputArrayElements - Function to output those elements
//      Input2DArrayElements - Function to scan in elements to a 2d array
//      Output2DArrayElements - Function to output those elements
//  Task 1:
//      StarPatternInput - Function to scan in a number and set it to an integer variable
//      StarPatternOutput - Function to Print asterisks recursively in the pattern of decrementing
//          the number and then incrementing when it gets to 1, back to it's original value, line 
//          by line
//  Task 3:
//      BuildingStringInput - Function to scan in the string that will be printed
//      BuildingStringOutput - Function to print the string scanned in, one character at a time, 
//          and line by line
//  Task 5:
//      PositiveAndNegative - Function to determine how many positive and negative numbers there are
//      PrintCountsTask5 - Function to output the number of positive and negative numbers
//  Task 7:
//      RecursiveCounts - Function to count the number of digits from 0-4 and 5-9
//      RecursiveOutput - Function to output the number of digits
//  Task 9:
//      FindValue - Function to scan through a 2d array to find a value and return what row and
//          column that value was found in
//      PrintValue - Function to print out if the number was found and where it was found
//
//-------------------------------------------------------------------------------------------------

#include "Standards.h"

//Task 0 - Prototype for the InputArrayElements function
void InputArrayElements(ifstream& fin, int array[]);
//Task 0 - Prototype for the OutputArrayElements function
void OutputArrayElements(ofstream& fout, const int array[], int taskNumber, string message);
//Task 0 - Prototype for the Input2DArrayElements function
void Input2DArrayElements(ifstream& fin, int array[][5]);
//Task 0 - Prototype for the Output2DArrayElements function
void Output2DArrayElements(ofstream& fout, int array[][5]);

//Task 1 - Prototype for the StarPatternInput function
void StarPatternInput(ifstream& fin, int& num);
//Task 1 - Prototype for the StarPatterOutput function
void StarPatternOutput(ofstream& fout, bool& headerFlag, int& num, bool& flag, int loopCheck);

//Task 3 - Prototype for the BuildingStringInput function
void BuildingStringInput(ifstream& fin, char message[]);
//Task 3 - Prototype for the BuildingStringOutput function
void BuildingStringOutput(ofstream& fout, bool& flag, int deliminator, char message[], 
	bool& numDelim, int& indexOfMessage);

//Task 5 - Prototype for the PositiveAndNegative function
void PositiveAndNegative(int array[], int& positives, int& negatives, int& tag);
//Task 5 - Prototype for the PrintCountsTask5 function
void PrintCountsTask5(ofstream& fout, int positives, int negatives);

//Task 7 - Prototype for the RecursiveOutput function
void RecursiveCounts(int array[], int& tag, int& count59, int& count04);
//Task 7 - Prototype for the RecursiveOutput function
void RecursiveOutput(ofstream& fout, int count59, int count04);

//Task 9 - Prototype for the FindValue function
void FindValue(int array[][5], bool& numFound, int& rowFound, int& colFound, int value);
//Task 9 - Prototype for the PrintValue function
void PrintValue(ofstream& fout, int array[][5], bool numFound, int rowFound, 
    int colFound, int value);

int main(void)
{

    //Input file stream
    ifstream fin;

    //Output file stream
    ofstream fout;

    //Open the input file stream
    fin.open("Lab2In.txt");

    //Open the output file stream
    fout.open("Lab2Out.txt");

    //Print the divider to the console
    PrintDivider('-', 100);
    //Output the course heading to the console
    PrintCourseHeading(COLLEGE, PROGRAM, NAME, 100);
    //Print the divider to the console
    PrintDivider('-', 100);
    //Print the file name to the console
    PrintFileName("Lab2In.txt");
    //Print the divider to the console
    PrintDivider('-', 100);

    //Print the divider to the output file
    PrintDivider(fout, '-', 100);
    //Print the course heading to the output file
    PrintCourseHeading(fout, COLLEGE, PROGRAM, NAME, 100);
    //Print the divider to the output file
    PrintDivider(fout, '-', 100);

    //Task 0 - count for the amount of calls of the function
    int countTask0 = 1;

    //Task 1 - count for the number that will be used in the recursive function
    int numTask1;
    //Task 1 - number that will be used as the limit in the for loop
    int loopCheckTask1;
    //Task 1 - create a boolean flag to determine if the lines are incrementing or decrementing
    bool flagTask1 = false;
	//Task 1 - create a boolean flag to determine if the header has been printed or not yet
	bool headerFlagTask1 = false;

    //Task 3 - create the first char array for the message that will be passed in and printed
    char array1Task3[100];
    //Task 3 - create the second char array for the message that will be passed in and printed
    char array2Task3[100];
    //Task 3 - create an integer to hold the value of where to print to
    int numDelimiter;
    //Task 3 - create a boolean flag to check if the header has been printed or not yet
    bool flagTask3 = false;
    //Task 3 - create a boolean flag to check and see if the delimiter was reached
    bool numDelimReachedTask3 = false;
    //Task 3 - create a count for which the string will be printed at
    int indexTask3 = 0;

	//Task 5 - create the first integer array that will be used
	int array1Task5[MAX_ELEMENTS];
	//Task 5 - create the second integer array that will be used
	int array2Task5[MAX_ELEMENTS];
	//Task 5 - create an integer variable to represent the count of positive numbers
	int numOfPositivesTask5 = 0;
	//Task 5 - create an integer variable to represent the count of negative numbers
	int numOfNegativesTask5 = 0;
	//Task 5 - create a tag for the array
	int tagTask5 = 0;

	//Task 7 - array for the first set of numbers
	int countsOneTask7[MAX_ELEMENTS];
	//Task 7 - array for the second set of numbers
	int countsTwoTask7[MAX_ELEMENTS];
    //Task 7 - tag for the array for the recursive function
    int tagTask7 = 0;
    //Task 7 - count for the digits between 5 and 9 inclusively
    int count59 = 0;
    //Task 7 - count for the digits between 0 and 4 inclusively
    int count04 = 0;

	//Task 9 - create a two dimensional integer array
	int arrayTask9[4][5];
	//Task 9 - create an integer for the row the number was found at
	int rowFound;
	//Task 9 - create an integer for the column the number was found at
	int columnFound;
	//Task 9 - create a tag for the array
	int tagFieldTask9 = 0;
	//Task 9 - create a flag to determine if the number has been found or not
	bool numberFound = false;

    //---------------------------------------------------------------------------------------------
    //Task 7 - InputArrayElements - Call 1
    //---------------------------------------------------------------------------------------------
    InputArrayElements(fin, countsOneTask7);

    //---------------------------------------------------------------------------------------------
    //Task 7 - OutputArrayElements - Call 1
    //---------------------------------------------------------------------------------------------
    OutputArrayElements(fout, countsOneTask7, 7, "Digit Array Counts");

    //---------------------------------------------------------------------------------------------
    //Task 7 - RecursiveCounts - Call 1
    //---------------------------------------------------------------------------------------------
    RecursiveCounts(countsOneTask7, tagTask7, count59, count04);

    //---------------------------------------------------------------------------------------------
    //Task 7 - RecursiveOutput - Call 1
    //---------------------------------------------------------------------------------------------
    RecursiveOutput(fout, count59, count04);

    //Set the tag back to zero
    tagTask7 = 0;

    //Set the count for 5-9 back to zero
    count59 = 0;

    //Set the count for 0-4 back to zero
    count04 = 0;

    //---------------------------------------------------------------------------------------------
    //Task 7 - InputArrayElements - Call 2
    //---------------------------------------------------------------------------------------------
    InputArrayElements(fin, countsTwoTask7);

    //---------------------------------------------------------------------------------------------
    //Task 7 - OutputArrayElements - Call 2
    //---------------------------------------------------------------------------------------------
    OutputArrayElements(fout, countsTwoTask7, 7, "Digit Array Counts");

    //---------------------------------------------------------------------------------------------
    //Task 7 - RecursiveCounts - Call 2
    //---------------------------------------------------------------------------------------------
    RecursiveCounts(countsTwoTask7, tagTask7, count59, count04);

    //---------------------------------------------------------------------------------------------
    //Task 7 - RecursiveOutput - Call 2
    //---------------------------------------------------------------------------------------------
    RecursiveOutput(fout, count59, count04);

    //---------------------------------------------------------------------------------------------
    //Task 1 - StarPatternInput - Call 1
    //---------------------------------------------------------------------------------------------
    StarPatternInput(fin, numTask1);

    //Set the loop check for the call
    loopCheckTask1 = numTask1;

    //---------------------------------------------------------------------------------------------
    //Task 1 - StarPatternOutput - Call 1
    //---------------------------------------------------------------------------------------------
    StarPatternOutput(fout, headerFlagTask1, numTask1, flagTask1, loopCheckTask1);

    //Set the flag back to false
    flagTask1 = false;

	//Set the header flag back to false
	headerFlagTask1 = false;

    //---------------------------------------------------------------------------------------------
    //Task 1 - StarPatternInput - Call 2
    //---------------------------------------------------------------------------------------------
    StarPatternInput(fin, numTask1);

    //Set the loop check for the call
    loopCheckTask1 = numTask1;

    //---------------------------------------------------------------------------------------------
    //Task 1 - StarPatternOutput - Call 2
    //---------------------------------------------------------------------------------------------
    StarPatternOutput(fout, headerFlagTask1, numTask1, flagTask1, loopCheckTask1);

    //---------------------------------------------------------------------------------------------
    //Task 3 - BuildingStringInput - Call 1
    //---------------------------------------------------------------------------------------------
    BuildingStringInput(fin, array1Task3);

    //For loop to loop through each character of the message
    for (int index = 0; index < 100; index++)
    {

        //If the character at the index is an !
        if (array1Task3[index] == '!')
        {

            //Set the index at which the ! was found
            numDelimiter = index;

        }

    }

    //---------------------------------------------------------------------------------------------
    //Task 3 - BuildingStringOutput - Call 1
    //---------------------------------------------------------------------------------------------
    BuildingStringOutput(fout, flagTask3, numDelimiter, array1Task3, numDelimReachedTask3, 
		indexTask3);

    //Set the flag for the header to false
    flagTask3 = false;

    //Set the flag for the number delimiter to false
    numDelimReachedTask3 = false;

    //Set the index back to zero
    indexTask3 = 0;

    //---------------------------------------------------------------------------------------------
    //Task 3 - BuildingStringInput - Call 2
    //---------------------------------------------------------------------------------------------
    BuildingStringInput(fin, array2Task3);

    //For loop to loop through each character of the message
    for (int index = 100; index > 0; index--)
    {

        //If the character at the index is a +
        if (array2Task3[index] == '+')
        {

            //Set the index at which the + was found
            numDelimiter = index;

            //End the for loop
            index = 0;

        }

    }

    //---------------------------------------------------------------------------------------------
    //Task 3 - BuildingStringOutput - Call 2
    //---------------------------------------------------------------------------------------------
    BuildingStringOutput(fout, flagTask3, numDelimiter, array2Task3, numDelimReachedTask3, 
		indexTask3);

	//---------------------------------------------------------------------------------------------
	//Task 5 - InputArrayElements - Call 1
	//---------------------------------------------------------------------------------------------
	InputArrayElements(fin, array1Task5);

	//---------------------------------------------------------------------------------------------
	//Task 5 - OutputArrayElements - Call 1
	//---------------------------------------------------------------------------------------------
	OutputArrayElements(fout, array1Task5, 5, "Positive and Negative Array Counts");

	//---------------------------------------------------------------------------------------------
	//Task 5 - PositiveAndNegative - Call 1
	//---------------------------------------------------------------------------------------------
	PositiveAndNegative(array1Task5, numOfPositivesTask5, numOfNegativesTask5, tagTask5);

	//---------------------------------------------------------------------------------------------
	//Task 5 - PositiveAndNegative - Call 1
	//---------------------------------------------------------------------------------------------
	PrintCountsTask5(fout, numOfPositivesTask5, numOfNegativesTask5);

	//Set the positive count back to zero
	numOfPositivesTask5 = 0;

	//Set the negative count back to zero
	numOfNegativesTask5 = 0;

	//Set the tag back to zero
	tagTask5 = 0;

	//---------------------------------------------------------------------------------------------
	//Task 5 - InputArrayElements - Call 2
	//---------------------------------------------------------------------------------------------
	InputArrayElements(fin, array2Task5);

	//---------------------------------------------------------------------------------------------
	//Task 5 - OutputArrayElements - Call 2
	//---------------------------------------------------------------------------------------------
	OutputArrayElements(fout, array2Task5, 5, "Positive and Negative Array Counts");

	//---------------------------------------------------------------------------------------------
	//Task 5 - PositiveAndNegative - Call 2
	//---------------------------------------------------------------------------------------------
	PositiveAndNegative(array1Task5, numOfPositivesTask5, numOfNegativesTask5, tagTask5);

	//---------------------------------------------------------------------------------------------
	//Task 5 - PositiveAndNegative - Call 2
	//---------------------------------------------------------------------------------------------
	PrintCountsTask5(fout, numOfPositivesTask5, numOfNegativesTask5);

    //---------------------------------------------------------------------------------------------
    //Task 9 - Input2DArrayElements - Call 1
    //---------------------------------------------------------------------------------------------
    Input2DArrayElements(fin, arrayTask9);

    //---------------------------------------------------------------------------------------------
    //Task 9 - Output2DArrayElements - Call 1
    //---------------------------------------------------------------------------------------------
    Output2DArrayElements(fout, arrayTask9);

    //---------------------------------------------------------------------------------------------
    // Task 9 - FindValue - Call 1
    //---------------------------------------------------------------------------------------------
    FindValue(arrayTask9, numberFound, rowFound, columnFound, 99);

    //-------------------------------------------------------------------------------------------------
    //Task 9 - PrintValue - Call 1
    //-------------------------------------------------------------------------------------------------
    PrintValue(fout, arrayTask9, numberFound, rowFound, columnFound, 99);

    //Set the flag back to false
    numberFound = false;

    //Set the row found back to 0
    rowFound = 0;

    //Set the column found back to 0
    columnFound = 0;

    //---------------------------------------------------------------------------------------------
    // Task 9 - FindValue - Call 2
    //---------------------------------------------------------------------------------------------
    FindValue(arrayTask9, numberFound, rowFound, columnFound, 18);

    //-------------------------------------------------------------------------------------------------
    //Task 9 - PrintValue - Call 2
    //-------------------------------------------------------------------------------------------------
    PrintValue(fout, arrayTask9, numberFound, rowFound, columnFound, 18);

    return 0;

}

//-------------------------------------------------------------------------------------------------
//Task 0 - InputArrayElements
//-------------------------------------------------------------------------------------------------
void InputArrayElements(ifstream& fin, int array[])
{

    //For loop to scan in the 10 elements of the array
    for (int index = 0; index < 10; index++)
    {

        //Scan in the integer at index into the array
        fin >> array[index];

    }

}

//-------------------------------------------------------------------------------------------------
//Task 0 - OutputArrayElements
//-------------------------------------------------------------------------------------------------
void OutputArrayElements(ofstream& fout, const int array[], int taskNumber, string message)
{

	//Create a static int to represent the count of the function call
	static int count = 1;

    //Call the print divider function
    PrintDivider(fout, '-', 100);

    //String for the message
    string header = "Task " + to_string(taskNumber) + " - Call " + to_string(count) + 
		" - " + message;

    //Print the header for the output to the output file
    PrintCenteredMessage(fout, header, 100);

    //Call the print divider function
    PrintDivider(fout, '-', 100);

    //Print the header for the numbers to the output file
    fout << right << setw(30) << "Numbers" << endl;

    //Call the print divider function
    PrintDivider(fout, '-', 100);

    //For loop to output the 10 elements of the array
    for (int index = 0; index < MAX_ELEMENTS; index++)
    {

        //Print the number to the output file
        fout << setw(30) << array[index] << endl;

    }

    //Call the print divider function
    PrintDivider(fout, '-', 100);

    //Increment the call count
    count++;

	//If the count is equal to 3
	if (count == 3)
	{

		//Set the count back to one
		count = 1;

	}

}

//-------------------------------------------------------------------------------------------------
//Task 0 - Input2DArrayElements
//-------------------------------------------------------------------------------------------------
void Input2DArrayElements(ifstream& fin, int array[][5])
{

	//For loop to loop through the rows of the 2d array
	for (int rows = 0; rows < 4; rows++)
	{

		//For loop to loop through the columns of the 2d array
		for (int columns = 0; columns < 5; columns++)
		{

			//Scan in the number at the current position in the 2d array
			fin >> array[rows][columns];

		}

	}

}

//-------------------------------------------------------------------------------------------------
//Task 0 - Output2DArrayElements
//-------------------------------------------------------------------------------------------------
void Output2DArrayElements(ofstream& fout, int array[][5])
{

	//Static integer variable to represent the number of calls
	static int count = 1;

	//Call the print divider function
	PrintDivider(fout, '-', 100);

	//Output the header to the output file
	PrintCenteredMessage(fout, "Task 9 - Call " + to_string(count) + 
		" - Search Two Dimensional Array", 100);

	//Call the print divider function
	PrintDivider(fout, '-', 100);

	//Call the print divider function
	PrintDivider(fout, '-', 100);

	//Print the row and column headers
	fout << right << setw(25) << setfill(' ') << "Columns" << endl;
	fout << "Rows" << setw(5) << "|" << setw(5) << "0" << setw(5) << "1" << setw(5) << "2" 
		<< setw(5) << "3" << setw(5) << "4" << endl;

	//Call the print divider function
	PrintDivider(fout, '-', 100);
	
	//For loop to loop through the rows
	for (int rows = 0; rows < 4; rows++)
	{

		//Print the header for row 0
		fout << rows << setw(8) << "|";

		//For loop to print all values at row 0
		for (int columns = 0; columns < 5; columns++)
		{

			//Print the value
			fout << setw(5) << array[rows][columns];

		}

		//Move the cursor down a line
		fout << endl;

	}
	
    //Call the print divider function
	PrintDivider(fout, '-', 100);

}

//-------------------------------------------------------------------------------------------------
//Task 1 - StarPatternInput
//-------------------------------------------------------------------------------------------------
void StarPatternInput(ifstream& fin, int& num)
{
    
    //Read in the number from the input file that will be used in the recursive function
    fin >> num;

    //Ignore the rest of the line
    fin.ignore(100, '\n');

}

//-------------------------------------------------------------------------------------------------
//Task 1 - StarPatternOutput
//-------------------------------------------------------------------------------------------------
void StarPatternOutput(ofstream& fout, bool& headerFlag, int& num, bool& flag, int loopCheck)
{

	//Create a static int for the count
	static int count = 1;

    //If statement to determine if this is the first call of the function
    if (headerFlag == false)
    {

        //Call the print divider function
        PrintDivider(fout, '-', 100);

        //Output the heading to the output file
        PrintCenteredMessage(fout, "Task 1 - Call " + to_string(count) + 
            " - Star Pattern with number of line set to: " + to_string(num), 100);

        //Call the print divider function
        PrintDivider(fout, '-', 100);

        //Set the count to 0 so the header will not be printed again
        headerFlag = true;

		//Increment the count
		count++;

    }

    //Determine if the lines are decrementing
    while (flag == false)
    {

        //Determine if the number is 0 yet
        if (num == 0)
        {

            //Set the flag to true
            flag = true;

        }
        else
        {

            //Output the line of asterisks
            fout << setfill('*') << setw(num) << '*' << endl;

            //Decrement the number
            num--;

            //-------------------------------------------------------------------------------------
            //Task 1 - StarPatternOutput - Recursive Call
            //-------------------------------------------------------------------------------------
            StarPatternOutput(fout, headerFlag, num, flag, loopCheck);

        }

    }

    //Determine if lines are incrementing
    while (flag == true && num < (loopCheck + 1))
    {

        //If the number is equal to 1
        if (num == 1)
        {

            //Increment the number
            num++;

        }
        else
        {

            //Output the line of asterisks
            fout << setfill('*') << setw(num) << '*' << endl;

            //If the last number has been reached
            if (num == loopCheck)
            {

                //Call the print divider function
                PrintDivider(fout, '-', 100);

                //Move the cursor down a line
                fout << endl;

            }

            //Increment the number
            num++;

            //-------------------------------------------------------------------------------------
            //Task 1 - StarPatternOutput - Recursive Call
            //-------------------------------------------------------------------------------------
            StarPatternOutput(fout, headerFlag, num, flag, loopCheck);

        }

    }

}

//-------------------------------------------------------------------------------------------------
//Task 3 - BuildingStringInput
//-------------------------------------------------------------------------------------------------
void BuildingStringInput(ifstream& fin, char message[])
{

    //Input the message from the input file
    fin.get(message, 100);

    //Ignore the rest of the line
    fin.ignore(100, '\n');

}

//-------------------------------------------------------------------------------------------------
//Task 3 - BuildingStringOutput
//-------------------------------------------------------------------------------------------------
void BuildingStringOutput(ofstream& fout, bool& flag, int deliminator, char message[],
	bool& numDelim, int& indexOfMessage)
{

	//Create a static int for the count
	static int count = 1;

    //Determine if the header has been printed or not yet
    if (flag == false)
    {

        //Call the print divider function
        PrintDivider(fout, '-', 100);

        //Print the header, centered, to the output file
        PrintCenteredMessage(fout, "Task 3 - Call " +to_string(count)+ " - Building String", 100);

        //Call the print divider function
        PrintDivider(fout, '-', 100);

        //Set the flag to true
        flag = true;

		//Increment the count
		count++;

    }

    //If the number delimiter has not been reached
    if (numDelim == false)
    {

        //Output the character array up until the count ends
        for (int index = 0; index < indexOfMessage; index++)
        {

            //If the delimiter has not been reached
            if (index <= deliminator)
            {

                //Print out the character
                fout << message[index];

            }

            //If the delimiter was reached
            if (index == deliminator)
            {

                //Set the flag to true
                numDelim = true;

                //Move the cursor down a line
                fout << endl;

                //Call the print divider function
                PrintDivider(fout, '-', 100);

            }

        }

        //Move the character to the next line
        fout << endl;

        //Increment the count
        indexOfMessage++;

        //-----------------------------------------------------------------------------------------
        //Task 3 - BuildingStringOutput - Recursive Call
        //-----------------------------------------------------------------------------------------
        BuildingStringOutput(fout, flag, deliminator, message, numDelim, indexOfMessage);

    }

}

//-------------------------------------------------------------------------------------------------
//Task 5 - PositiveAndNegative
//-------------------------------------------------------------------------------------------------
void PositiveAndNegative(int array[], int& positives, int& negatives, int& tag)
{

	//If statement to determine if the number is positive
	if (array[tag] > 0)
	{

		//Increment the positive count
		positives++;

	}
	else if (array[tag] < 0)
	{

		//Increment the negative count
		negatives++;

	}

	//Increment the tag
	tag++;

	//If the tag is less than 10
	if (tag < 10)
	{

		//-----------------------------------------------------------------------------------------
		//Task 5 - PositiveAndNegative - Recursive call
		//-----------------------------------------------------------------------------------------
		PositiveAndNegative(array, positives, negatives, tag);

	}

}

//-------------------------------------------------------------------------------------------------
//Task 5 - PrintCountsTask5
//-------------------------------------------------------------------------------------------------
void PrintCountsTask5(ofstream& fout, int positives, int negatives)
{

	//Call the print divider function
	PrintDivider(fout, '-', 100);

	//Print the positive count
	fout << "Positive Count: " << positives << endl;

	//Print the negative count
	fout << "Negative Count: " << negatives << endl;

	//Call the print divider function
	PrintDivider(fout, '-', 100);

	//Move the cursor down a line
	fout << endl;

}

//-------------------------------------------------------------------------------------------------
//Task 7 - RecursiveCounts
//-------------------------------------------------------------------------------------------------
void RecursiveCounts(int array[], int& tag, int& count59, int& count04)
{

    //Create an integer to store the current value of the array
    int currentNum = array[tag];

    //While loop to determine if the number is not zero
    while (currentNum != 0)
    {

        //If the current number mod 10 is between 5 and 9 inclusively
        if ((currentNum % 10) >= 5 && (currentNum % 10) <= 9)
        {

            //Increment the 5-9 count
            count59++;

        }
        //Else if the number mod 10 is between 0 and 4 inclusively
        else if ((currentNum % 10) >= 0 && (currentNum % 10) <= 4)
        {

            //Increment the 0-4 count
            count04++;

        }

        //Divide the current number by 10 
        currentNum /= 10;

    }

    //Increment the tag field
    tag++;

    //If the tag is less than 10
    if (tag < 10)
    {

        //---------------------------------------------------------------------------------------------
        //Task 7 - RecursiveCounts - Recursive Call
        //---------------------------------------------------------------------------------------------
        RecursiveCounts(array, tag, count59, count04);

    }
    

}

//-------------------------------------------------------------------------------------------------
//Task 7 - RecursiveOutput
//-------------------------------------------------------------------------------------------------
void RecursiveOutput(ofstream& fout, int count59, int count04)
{

    //Call the print divider function
    PrintDivider(fout, '-', 100);

    //Print the digit count for the 0-4 count
    fout << "Digit Count for 0 to 4: " << count04 << endl;
    
    //Print the digit count for the 5-9 count
    fout << "Digit Count for 5 to 9: " << count59 << endl;

    //Call the print divider function
    PrintDivider(fout, '-', 100);

    //Move the cursor to the next line
    fout << endl;

}

//-------------------------------------------------------------------------------------------------
//Task 9 - FindValue
//-------------------------------------------------------------------------------------------------
void FindValue(int array[][5], bool& numFound, int& rowFound, int& colFound, int value)
{

    //Static integer variable for the row
    static int row = 0;

    //Static integer variable for the column
    static int column = 0;

    //If statement to determine if the row is still less than 4
    if (row <= 4)
    {

        //If the column is greater than 5
        if (column > 5)
        {

            //Set the column to 0
            column = 0;

            //Increment the row
            row++;

        }
        else if (array[row][column] == value)
        {

            //Set the row found
            rowFound = row;

            //Set the column found
            colFound = column;

            //Set the boolean to be true
            numFound = true;

        }

        //Increment the column
        column++;

        //-----------------------------------------------------------------------------------------
        //Task 9 - FindValue - Recursive Call
        //-----------------------------------------------------------------------------------------
        FindValue(array, numFound, rowFound, colFound, value);

    }

}

//-------------------------------------------------------------------------------------------------
//Task 9 - PrintValue
//-------------------------------------------------------------------------------------------------
void PrintValue(ofstream& fout, int array[][5], bool numFound, int rowFound,
    int colFound, int value)
{

    //Call the print divider function
    PrintDivider(fout, '-', 100);

    //If the number was found
    if (numFound == true)
    {

        //Output the number was found
        fout << "The search Value " << value << " was found in the two dimensional array." << endl;

        //Print where the value was found
        fout << "It is in Row " << rowFound << " and Column " << colFound << 
            " of the array." << endl;

    }
    else
    {

        //Print that the value was not found
        fout << "The value " << value << " was not found in the two dimensional array." << endl;

    }

    //Call the print divider function
    PrintDivider(fout, '-', 100);

    //Move the cursor down a line
    fout << endl;

}