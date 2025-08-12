// Pointer Practice 2 BG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void showChests(int* chests, int size);
void addCoins(int* chests, int index, int amount);


int main()
{
	int treasureChests[5] = { 0, 0, 0, 0, 0 };

	string choice;
	do
	{
		int userChestCount, amount;

		cout << "Which chest would you like to add coins to?\n"
			 << "Choose from one through five.\n";
		cin  >> userChestCount;

		while (userChestCount < 1 || userChestCount > 5)
		{
			cout << "Please enter a valid chest from one through five.\n";
			cin  >> userChestCount;
		}

		cout << "How many coins would you like to add?\n";
		cin >> amount;

		addCoins(treasureChests, userChestCount - 1, amount);
		showChests(treasureChests, 5);

		cout << "\nWould you like to add more coins?\n";
		cin  >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	}

	while (choice == "yes");
	
	cout << "\nFinal coin count: \n";
	showChests(treasureChests, 5);

	return 0;
	
}


void showChests(int* chests, int size)
{
	cout << "\nCurrent Chests: \n";

	for (int i = 0; i < size; ++i)
	{
		cout << "Chest " << (i + 1) << ": " << *(chests + i) << endl;
	}
}

void addCoins(int* chests, int index, int amount)
{
	*(chests + index) += amount;
}