/* Daily C++ Practice Problem - Day 1
   Topic: Functions, Arrays, Pointers, and Min/Max Logic
   Write a program that:

   Prompts the user to enter the number of students.

   Dynamically creates an array to store test scores.

   Uses a function to:

   Accept the array and number of students as arguments.

   Find and return the highest and lowest score using pointers.

   Displays the highest and lowest score.
*/

#include <iostream>

using namespace std;

void highAndLowScore(int* pTestScores, int size, int* low, int* high, int* average);

int main()
{
	int* pTestScores = nullptr;
	int numberOfStudents;

	cout << "How many students are there?\n";
	cin >> numberOfStudents;

	pTestScores = new int[numberOfStudents];

	cout << "Please enter the students test scores:\n";
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << "Test score #" << i + 1 << ": ";
		cin >> pTestScores[i];
	}

	int lowScore, highScore, averageScore;
	highAndLowScore(pTestScores, numberOfStudents, &lowScore, &highScore, &averageScore);

	cout << "The lowest score is " << lowScore << endl;
	cout << "The highest score is " << highScore << endl;
	cout << "The average of the scores is " << averageScore << endl;

	delete[] pTestScores;
	pTestScores = nullptr; // Reset the array to nullptr since deleting the array removes it but the ptr still points to
						   // deleted memory causing a crash.

	return 0;
}

void highAndLowScore(int* pTestScores, int size, int* low, int* high, int* average)
{
	 *low = pTestScores[0];
	 *high = pTestScores[0];
	 *average = 0;
	 int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (pTestScores[i] < *low)
		{
			*low = pTestScores[i];
		}

		if (pTestScores[i] > *high)
		{
			*high = pTestScores[i];
		}

		// Use sum += the index of the array instead of sum = pTestScores[i] + i
		// That just adds the index to the next number in line
		sum += pTestScores[i];
	}

	// Keep average out of the loop otherwise the math is being run every loop
	*average = sum / size;
}