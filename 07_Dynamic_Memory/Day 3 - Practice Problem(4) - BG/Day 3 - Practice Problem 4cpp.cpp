/* Prompt: Letter Grades Report
   Write a program that:

   Uses a Student struct with:

   string name

   int scores[3]

   double average

   char letterGrade

   Asks the user for the number of students.

   For each student:

   Inputs their name and 3 test scores.

   Calculates their average.

   Assigns a letter grade based on the average:

   A: 90–100

   B: 80–89

   C: 70–79

   D: 60–69

   F: below 60
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Create our student struct to store the values for each student that can then be called later in the program
// Struct is similar to a class but by default is public and is better for plain data structures (PODs)
// lightweight containers and small records. Classes are better for bigger programs with logic and encapsulation.
struct Student
{
	string name;
	int scores[3];
	double average;
	char letterGrade;
};

// Declare our two functions at the top so its easy to see what functions are here and being used
void studentAverageScore(Student* studentList, int size, double* average);
void printStudentInfo(Student* studentList, int size, double* averages);


int main()
{
	// User input for student numbers
	int numberOfStudents;

	cout << "Please enter the number of students.\n";
	cin >> numberOfStudents;
	// Struct pointer to dynamic array for students
	Student* studentList = new Student[numberOfStudents];

	// For loop to loop over the number of students so the user can enter names for each one.
	for (int i = 0; i < numberOfStudents; i++)
	{
		cout << "Student name: ";
		// This is the user input that places the desired name into the index each loop
		cin >> studentList[i].name;

		
		cout << "Please enter three test scores." << studentList[i].name << ":\n";
		// For loop to loop three times over the student list names and apply three user entered scores for each 
		// student they entered earlier
		for (int j = 0; j < 3; j++)
		{
			cout << "Test score #" << j + 1 << ": " << endl;
			// User input to apply the scores to the student list names
			cin >> studentList[i].scores[j];
		}
	}

	// Here we create a dynamic average array with a reference so it can be a pointer and therefor passed to another
	// function. New double numberOfStudents will dynamically set the average array number to that of the students. 
	// Then we call the average calculation function passing in the student array, the number of students the user 
	// entered and then the averages.
	double* averages = new double[numberOfStudents];
	studentAverageScore(studentList, numberOfStudents, averages);

	// Call the printStudentInfo function passing our student list array, the number of students the 
	// user entered, and then our averages array so the function has access to all of them
	printStudentInfo(studentList, numberOfStudents, averages);

}

void studentAverageScore(Student* studentList, int size, double* average)
{
	// For loop to loop over the size of student list
	for (int i = 0; i < size; i++)
	{
		// Initialize the sum variable and create a nested for loop to loop over each of the three
		// test scores. During each loop its adding the first of three test scores for each student. 
		// This happens once every loop so loop one will be 0 + 85 since sum is set to 0 initially. Then
		// second loop its 85 + 2 and so forth until the three scores are added. Then we store the average
		// score into the average array at the first index so it matches the list of names and the index
		// for those names. We divide by three because we know theres only ever going to be three scores
		double sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += studentList[i].scores[j];
		}
		average[i] = sum / 3.0;
	}

	// Create a for loop to loop of the numberOfStudents
	for (int i = 0; i < size; i++)
	{
		// Create a new variable to hold each index of average divided by 10.
		// We divide by 10 to get the grade so we can determine based on their average
		// if they earned an A or etc. For example, 95 / 10 = 9. We only care about the tens place to 
		// determine the letter grade.
		int gradeBucket = average[i] / 10;
		switch (gradeBucket)
		{
		case 10:
		case 9:
			studentList[i].letterGrade = 'A';
			break;
		case 8:
			studentList[i].letterGrade = 'B';
			break;
		case 7:
			studentList[i].letterGrade = 'C';
			break;
		case 6:
			studentList[i].letterGrade = 'D';
			break;
		default:
			studentList[i].letterGrade = 'F';
			break;
		}

	}
}

void printStudentInfo(Student* studentList, int size, double* averages)
{
	// Our print info function prints out all of the students and their corresponding info
	// This function formats all of it so it looks neat and pretty in the output
	cout << setw(23) << "Student report:\n"
		 << "---------------------------------------\n";

	// For loop to loop through the student list
	for (int i = 0; i < size; i++)
	{
		// We use left to left face the text and then set the width to 12 to format the spacing
		// This prints each student name in the array with our desired formatting.
		// We then loop throug each students three test scores with its own formatting. 
		// Outside of the test score looping we print out the averager grade from our averages
		// array using its index to line up with the student list index. We also print the grade on 
		// on the same line.
		cout << left << setw(12) << studentList[i].name;
		for (int j = 0; j < 3; j++)
		{
			cout << setw(4) << studentList[i].scores[j];
		}

		cout << " Avg: " << fixed << setprecision(2) << averages[i]
			 << " Grade: " << studentList[i].letterGrade << "\n";
	}
}