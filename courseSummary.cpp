// This program will show a menu-driven interface that provides the user with two options:
// 1. Process Grades Summary report.
// 2. Quit.
// 
// Jazmin Even Dorra


//Header Files
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	// Definitions
	const int SUMMARY = 1;			//Menu Options
	const int QUIT = 2;

	int choice;						//User's Choice
	int count;

	ifstream courseSummary;			// File stream Object
	
	string filename;
	string course_number_and_description;
	string instructor_name;
	string term;
	string stdName;
	int grade;
	
	double total = 0.0,
		average;
	
	int times = 0,
		highgrade = 0,
		lowgrade = 9999;
				

	//Average Grade precision
	cout << fixed << showpoint << setprecision(1);

	cout << "\nCourse Summary App ...\n";
	
	// Menu		
	do
	{
		//Intro and ask for option
		cout << "Choose one of the following options\n"
			<< "\t1. Process Grades Summary report.\n"
			<< "\t2. Quit.\n"
			<< "Option: ";
		cin >> choice;

		// Drive menu options
		switch (choice)
		{
		case SUMMARY: // Read and display course summary
			cout << "\nGrades Summary Report ...\n" << endl << "Enter name of file: ";
			cin >> filename;

			// Open File for display
			courseSummary.open("COP1334C.txt");

			
			// Display course data
			if ("COP1334C.txt")		// Opened successfully
			{
				// Read data from the file and store into variables
				getline(courseSummary, course_number_and_description);
				getline(courseSummary, instructor_name);
				getline(courseSummary, term);

				
				cout << endl << "--------------------------------------------------\n\n";
				cout << course_number_and_description << endl << endl;
				cout << setw(33) << left << instructor_name;
				cout << left << "Term: " << term << endl;
				cout << "\n\nList of Students\n";
				cout << "--------------------------------------------------\n";
													

				for (int i = 1; i <= 37; i++)
					while (courseSummary >> stdName) // Read data till end of File
					{
						courseSummary.ignore();		// Flush buffer	

					
						// Read and Display student records				
						getline(courseSummary, stdName);
						cout << setw(20) << left << stdName;
						courseSummary >> grade;
						cout << setw(10) << left << grade << endl;

						// Update accumulator
						total += grade;

						// Increment counter
						times++;

						// Update lowest grade	
						if (grade < lowgrade)
							lowgrade = grade;
					}
				
				// Update highest grade
				if (grade > highgrade)
					highgrade = grade;
															
				// Calculations 
				cout << endl << "Highest Grade: " << highgrade << endl;
				cout << "Lowest Grade: " << lowgrade << endl;
				average = total / times;
				cout << "Average Grade: " << average << endl;
				
				cout << "\n--------------------------------------------------\n\n";

				//Close the file
				courseSummary.close();
			}
			
			else
				//Display error message.
				cout << "Error ... Cannot open " << filename << ".\n";
			break;
				
		case QUIT:	// Quit
			cout << "\nGood Bye ...";
			break;
						
		default: // Invalid
			cout << "Error ... Incorrect option. Try again.\n";
		}
	} while (choice != QUIT);
	 
	return 0;
}