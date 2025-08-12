// Daily Practice Prompt(4) Day 1 - BG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void calculator(double number1, char mathOperator, double number2);

int main()
{
	double userNumber1;
	double userNumber2;
	char userOperator;

	cout << "Please enter two decimal numbers and the math operation below.\n";
	cout << "Number One: \n";
	cin >> userNumber1;
	cout << "Math operator: \n";
	cin >> userOperator;
	cout << "Number Two: \n";
	cin >> userNumber2;

	calculator(userNumber1, userOperator, userNumber2);
}

void calculator(double number1, char mathOperator, double number2)
{
	double solution = 0;

	switch (mathOperator)
	{
	case '+':
		solution = number1 + number2;
		break;
	case '-':
		solution = number1 - number2;
		break;
	case '*':
		solution = number1 * number2;
		break;
	case '/':
		if (number2 == 0)
		{
			cout << "Error: cannot divide by 0.\n";
			return;
		}
		solution = number1 / number2;
		break;
	default:
		cout << "Error: invalid input.\n";
		return;
	}

	cout << "Solution: " << solution << endl;
}
