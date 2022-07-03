// BowlingArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace::std;

//declaring the bariables we will need
char selection;
string line;
string word;
float sum = 0;
int i = 0;
int j = 0;
const int BOWLERS = 10;
const int SCORES = 5;
string Names[BOWLERS] = {};
int Scores[BOWLERS][SCORES] = {};
float Average[BOWLERS] = {};


// function to show the usage of the program
void ShowUsage()
{
	cout << "To show program usage 'S'" << endl;
	cout << "To input a file press 'G'" << endl;
	cout << "To average player scores press 'A'" << endl;
	cout << "To display player data press 'P'" << endl;
	cout << "To quit the program press 'Q'" << endl;
}

// function to get data from a user input file and enter this data into two arrays
// Displays a success or failure based on if there is data in the array.
void GetBowlingData(int argc, char* argv[])
{
	if (argc < 2)
	{

		cout << "Error with input args.." << endl;
	
	}

	ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile)
	{
		cout << "Error with file name.." << endl;
		
	}


		for (int i = 0; i < BOWLERS; i++)
		{

			inFile >> Names[i];

			for (int j = 0; j < SCORES; j++)
			{
				inFile >> Scores[i][j];
			}
			
		}

		if (Scores[i][j] != NULL)
			cout << "Success!" << endl;
		else
			cout << "Failure" << endl;
	

	

	

}











// Takes the scores of the players and averages them, then puts the averages into a new array.
void GetAverageScore()
{
	
	for (i = 0; i < BOWLERS; i++)
	{
		for (j = 0; j < SCORES; j++)
		{
			sum = sum + Scores[i][j];

			
		}
		sum = sum / SCORES;
		Average[i] = sum;
		sum = 0;


	}
	if (Average[i] != NULL)
		cout << "Success!" << endl;
	else
		cout << "Failure" << endl;



}

// takes the results and prints them out for the user to see. Includes names, scores, and the average score of the bowlers.
void PrettyPrintResults()
{
	cout << endl;
	cout << "Name " << setw(30) << "Scores" << setw(35) << " Average Score" << endl;

	size_t longestName = 0;

	for (i = 0; i < BOWLERS; i++)

	{

		if (Names[i].size() > longestName)

			longestName = Names[i].size();

	}




	for (i = 0; i < BOWLERS; i++)

	{


		const size_t fillLength = (longestName + 1) - Names[i].size();



		cout << right << Names[i];



		cout << setfill('.') << setw(fillLength) << '.';



		for (j = 0; j < SCORES; j++)

		{


			cout << left << "\t" << Scores[i][j];

		}
		cout << left << "\t" << fixed << setprecision(2) << Average[i];



		cout << endl;

	}
	
}

// prints out the options and lets the user pick which ones to use, and to quit the program when they are done
int main(int argc, char* argv[])
{
	ShowUsage();

	do{
	
		cout << "Please enter selection: ";
		cin >> selection;

		if (selection == 's' || selection == 'S')
		{
			system("cls");
			ShowUsage();
		}
		else if (selection == 'g' || selection == 'G')
			GetBowlingData(argc, argv);
		else if (selection == 'a' || selection == 'A')
			GetAverageScore();
		else if (selection == 'p' || selection == 'P')
			PrettyPrintResults();
		else if (selection == 'q' || selection == 'Q')
		{
			cout << "Thank You";

			break;
		}


	} while (1);



  
}


