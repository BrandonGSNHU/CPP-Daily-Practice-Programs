/* Practice Prompt: "Find Max and Min in an Array (Using Pointers)"
   Problem:
   Write a C++ program that:

   Asks the user to enter the size of an array and its values

   Stores those values in a dynamically allocated array (using new)

   Passes the array to a function that finds:

   The maximum value

   The minimum value

   Use pointers in the function to return the max and min values
   Use int* arr = new int[size]; to allocate the array

   Write a function:
   void findMinMax(int* arr, int size, int* min, int* max);
   In main(), print out the final min and max values

   Free the memory with delete[]

   This program dynamically creates an array using user input for the size and each value within the array.
   This is done by creating a pointer to an empty array by using NULL and then intializing an input variable for 
   the user. From here, we take that pointer and set that equal to the array size indicated by the user. We then loop
   the size of the array so the user can input each desired value until the array length is finished. With all of the 
   info gathered we can then pass the pointer to the function where it will loop through the array to find the minimum 
   and maximum values within the array. To find the min and max values we set two variables up to hold them and then 
   loop through the array comparing the index to the min and max values. These values are default set the arrays first
   index and from there we loop through index storing the smaller or bigger numbers by comparing each index and storing 
   that value if it is indeed bigger or smaller. That stored value becomes the new value to compare to as we continue looping
   through the array.
*/

#include <iostream>
#include <string>
using namespace std;

void minAndMax(int* pEmptyArray, int size, int* min, int* max);

int main()
{
	int* pEmptyArray = NULL;
	int arraySize;
	

	cout << "Please enter the size of the array: \n";
	cin >> arraySize;

	pEmptyArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		cout << "Please enter value #" << i + 1 << ": ";
		cin >> pEmptyArray[i];
	}

	int minValue, maxValue;
	minAndMax(pEmptyArray, arraySize, &minValue, &maxValue);

	cout << "The minimum value is: " << minValue << endl;
	cout << "The maximum value is: " << maxValue << endl;

	delete[] pEmptyArray;

	return 0;
}

void minAndMax(int* pEmptyArray, int size, int* min, int* max)
{
	*min = pEmptyArray[0];
	*max = pEmptyArray[0];

	for (int i = 0; i < size; i++)
	{
		if (pEmptyArray[i] < *min)
		{
			*min = pEmptyArray[i];
		}

		if (pEmptyArray[i] > *max)
		{
			*max = pEmptyArray[i];
		}
	}
	
}