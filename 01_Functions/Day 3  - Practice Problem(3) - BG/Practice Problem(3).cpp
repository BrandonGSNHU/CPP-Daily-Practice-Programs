/* Topic: Structs, Pointers, Functions, Arrays
   Write a program that:

   Defines a Student struct with:

   Dynamically allocates an array of Student.

   Asks for:

   Each student's name
  
   Their 3 scores

   Calculates each student’s average score and prints:

   Student with the highest average

   Student with the lowest average
*/

#include <iostream>
using namespace std;

struct Student {
    string name;
    int scores[3];
};

// Function declarations
void studentAverage(Student* students, int size, double* studentAverageScore);
void studentInfo(Student* students, double* averages, int size, int* highestIndex, int* lowestIndex);

int main()
{
    int numberOfStudents;

    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    // Dynamic allocation
    Student* studentList = new Student[numberOfStudents];

    // Input loop
    for (int i = 0; i < numberOfStudents; i++) {
        cout << "\nStudent name: ";
        cin >> studentList[i].name;

        cout << "Enter 3 scores for " << studentList[i].name << ":\n";
        for (int j = 0; j < 3; j++) {
            cout << "Score #" << j + 1 << ": ";
            cin >> studentList[i].scores[j];
        }
    }

    // Create dynamic array for averages
    double* averages = new double[numberOfStudents];

    // Calculate each student's average
    studentAverage(studentList, numberOfStudents, averages);

    // Display each student's average
    cout << "\n--- Student Averages ---\n";
    for (int i = 0; i < numberOfStudents; i++) {
        cout << studentList[i].name << "'s average: " << averages[i] << endl;
    }

    // Find top and lowest scoring student by average
    int highestIndex, lowestIndex;
    studentInfo(studentList, averages, numberOfStudents, &highestIndex, &lowestIndex);

    // Output top/bottom performers
    cout << "\nTop student: " << studentList[highestIndex].name << " with an average of " << averages[highestIndex] << endl;
    cout << "Lowest student: " << studentList[lowestIndex].name << " with an average of " << averages[lowestIndex] << endl;

    // Clean up memory
    delete[] studentList;
    delete[] averages;

    return 0;
}

// Calculates average score for each student
void studentAverage(Student* students, int size, double* studentAverageScore) {
    for (int i = 0; i < size; i++) {
        double sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].scores[j];
        }
        studentAverageScore[i] = sum / 3.0;
    }
}

// Finds indices of student with highest and lowest average
void studentInfo(Student* students, double* averages, int size, int* highestIndex, int* lowestIndex) {
    *highestIndex = 0;
    *lowestIndex = 0;

    for (int i = 1; i < size; i++) {
        if (averages[i] > averages[*highestIndex]) {
            *highestIndex = i;
        }
        if (averages[i] < averages[*lowestIndex]) {
            *lowestIndex = i;
        }
    }
}
