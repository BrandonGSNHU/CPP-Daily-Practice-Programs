/* Daily C++ Practice Prompt – Day 3
   Topic: Structs, Arrays of Structs, Functions
   You're going to use a struct to store each student's name and score.

   🔧 Requirements:

   Prompt the user for the number of students.

   Dynamically create an array of Student structs.

   Ask the user to input each student's name and score.

   Create a function to find and return:

   The student with the highest score

   The student with the lowest score
*/

#include <iostream>
using namespace std;

struct Student
{
	string name;
	int score;

};

void highAndLow(Student* students, int size, Student* lowest, Student* highest);

int main()
{
	int students;
	
	cout << "Please enter the number of students.\n";
	cin  >> students;
	Student* studentList = new Student[students];

	cout << "Please enter the name and score of each student.\n";

	for (int i = 0; i < students; i++)
	{
		cout << "Student name: ";
		cin >> studentList[i].name;
		cout << "Student score: ";
		cin >> studentList[i].score;
	}

	Student highest, lowest;
	highAndLow(studentList, students, &highest, &lowest);

	// Use a . dot operator when working with a struct variable
	cout << "\nTop scroring student: " << highest.name << " with the score of " << highest.score << endl;
	cout << "\nLowest scoring student: " << lowest.name << " with the score of " << lowest.score << endl;

	delete[] studentList;
	studentList = nullptr;
}

void highAndLow(Student* students, int size, Student* lowest, Student* highest)
{
	*highest = students[0];
	*lowest = students[0];

	for (int i = 0; i < size; i++)
	{
		// Use the -> arrow operator when working witha pointer to a struct
		if (students[i].score > highest->score)
		{
			*highest = students[i];
		}

		if (students[i].score < lowest->score)
		{
			*lowest = students[i];
		}
	}
}
