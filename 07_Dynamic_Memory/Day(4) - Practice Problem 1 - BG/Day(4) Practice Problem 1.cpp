/* Day 4 Practice Problem – Dynamic Arrays + Functions
   Topic: Dynamic memory, arrays, and function reuse.

   Prompt:
   Write a program that:

   Asks the user how many test scores they want to enter.

   Dynamically allocates an array for that many scores.

   Allows the user to input the scores.

   Calculates and returns:

   The highest score

   The lowest score

   The average score

   Outputs all of that neatly.
*/

#include <iostream>
using namespace std;

void testScoresInput(double* testScores, int size);
double highestTestScore(double* testScores, int size);
double lowestTestScore(double* testScores, int size);
double averageTestScore(double* testScores, int size);

int main()
{
	int numberOfTestScores;
	
	cout << "How many test scores would you like to enter?\n";
	cin  >> numberOfTestScores;

	double* testScores = new double[numberOfTestScores];

	testScoresInput(testScores, numberOfTestScores);

	double highScore = highestTestScore(testScores, numberOfTestScores);

	cout << "The highest test score is: " // Output belongs in main if the function is only for calculations
		 << highScore << endl;			  // This follows single-responsibility principle

	double lowScore = lowestTestScore(testScores, numberOfTestScores);

	cout << "The lowest test score is: "
		 << lowScore << endl;

	double average = averageTestScore(testScores, numberOfTestScores);
	cout << "The average test score is: "
		 << average << endl;

	delete[] testScores;

	return 0;
}

void testScoresInput(double* testScores, int size)
{
	cout << "Please enter your test scores.\n";

	for (int i = 0; i < size; i++)
	{
		cout << "Testscore #" << i + 1 << ": ";
		cin >> testScores[i];
	}
}

double highestTestScore(double* testScores, int size)
{
	double highScore = testScores[0];

	for (int i = 1; i < size; i++)
	{
		if (testScores[i] > highScore)
		{
			highScore = testScores[i];
		}
	}

	return highScore;
}

double lowestTestScore(double* testScores, int size)
{
	double lowScore = testScores[0];

	for (int i = 1; i < size; i++)
	{
		if (testScores[i] < lowScore)
		{
			lowScore = testScores[i];
		}
	}

	return lowScore;
}

double averageTestScore(double* testScores, int size)
{
	double sum = 0.0;

	for (int i = 0; i < size; i++)
	{
		sum += testScores[i];
	}
	
	// No need to initialize average here since we're initializing and calculating on the same line.
	// We also dont need to create an average variable here if it isn't used elsewhere allowing us to 
	// simplify our code
	return sum / size;
}