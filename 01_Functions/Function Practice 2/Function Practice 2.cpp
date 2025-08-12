/* Brandon Gallagher
*  Function practice 2
*  07/21/2025
* 
*  This program asks the user to enter the total number of test scores 
*  Afterwards the sum, average, minimum, and maximum values are stored,
*  calculated and then returned for the user to see. These are all done
*  in separate functions with the array being filled during runtime.
*/

#include <iostream>
using namespace std;

void readScores(int scores[], int size);
int sumScores(const int scores[], int size);
double averageScore(const int scores[], int size);
int findMinScore(const int scores[], int size);
int findMaxScore(const int scores[], int size);
int numScores;


int main()
{
    cout << "Please enter how many test scores you would like to enter: \n";
    cin >> numScores;

    // Pointer to fill the array during runtime based off of the desired users test scores
    int* scores = new int[numScores];

    // Call each function and initalize each local variable to get return values on each of them
    readScores(scores, numScores);

    int totalSum = sumScores(scores, numScores);
    double average = averageScore(scores, numScores);
    int minScore = findMinScore(scores, numScores);
    int maxScore = findMaxScore(scores, numScores);

    cout << "Sum: " << totalSum << "\n"
         << "Average: " << average << "\n"
         << "Mininum score: " << minScore << "\n"
         << "Maximum score: " << maxScore << "\n";

    // Delete the array afterwards 
    delete[] scores;
    return 0;
  
} 

void readScores(int scores[], int size)
{
    // For loop to read each score by number as the user enters it and stores them into the array
    for (int i = 0; i < size; ++i)
    {
        cout << "Enter score # " << (i + 1) << ": ";
        cin >> scores[i];
    }
}

int sumScores(const int scores[], int size)
{
    int totalSum = 0;
    
    // For loop to loop through the array and then add each score at the next index into totalSum
    for (int i = 0; i < size; ++i)
    {
        totalSum += scores[i];
    }
    return totalSum;
}

double averageScore(const int scores[], int size)
{
    // Error check to ensure size never equals 0
    if (size == 0) 
        return 0.0;

    double totalAverage = 0.0;

    // For loop to iterate through the array adding each score at each index
    // afterwards divide by the total size to get the average
    for (int i = 0; i < size; ++i)
    {
        totalAverage += scores[i];
    }
    return totalAverage / size;
           
}

int findMinScore(const int scores[], int size)
{
    if (size == 0) 
        return 0;

    // Initialize minScore to the index at scores. Using i is wrong since thats just the index not
    // the actual score at the index
    int minScore = scores[0];

    // For loop to loop through the array checking for the minimum value and storing it in minScore
    for (int i = 1; i < size; ++i)
    {
        // Similar to before, compare the value at the index in scores to minScore
        // not the index itself
        if (scores[i] < minScore)
        {
            minScore = scores[i];
        }
    }

        return minScore;
}

int findMaxScore(const int scores[], int size)
{
    if (size == 0)
        return 0;

    // Initializes maxScore to the first element
    int maxScore = scores[0];

    // For loop to check the score at each index storing the largest one in maxScore
    for (int i = 1; i < size; ++i) 
    {

        if (scores[i] > maxScore)
        {
            maxScore = scores[i];
        }
    }
    return maxScore;
}

