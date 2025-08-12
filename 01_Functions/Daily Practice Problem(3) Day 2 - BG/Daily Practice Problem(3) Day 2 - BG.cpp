/* Practice Prompt: "Swap Two Numbers"
   Problem:
   Write a C++ program that:

   Asks the user for two numbers

   Swaps the values using a function and pointers

   Displays the values before and after the swap

   Requirements:
   Use a function called swapNumbers(int* a, int* b)

   Pass the addresses of the two numbers to that function

   The function should swap the values at those addresses

   Use cin and cout to get and display values
*/

#include <iostream>

using namespace std;

void swapNumbers(int* a, int* b);

int main()
{
	int value1;
	int value2;

	int* pValue1 = &value1;
	int* pValue2 = &value2;

	cout << "Please enter two numbers to be swapped: \n";
	cin >> value1;
	cin >> value2;
	cout << "The values to be swapped are: " << value1 << " and " << value2 << endl;

	swapNumbers(pValue1, pValue2);

	cout << "After swap: value one = " << value1 << ", value two = " << value2 << endl;

	return 0;
}


void swapNumbers(int* a, int* b)
{
	int temp = *a; // temp = value at a's address
	*a = *b; // value at a = value at b
	*b = temp; // value at b = original value at a

}