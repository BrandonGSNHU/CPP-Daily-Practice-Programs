// Daily Practice Problem(2) Day 2 - BG.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Practice Prompt: "Character Creator"
// You're making a basic text-based RPG character.
//
// Your task :
// Create a Character class
//
// It should have :
//
// A name(string)
//
// A level(int)
//
// A pointer to health(int*)
//
// Write:
// A constructor that sets default values
//
// A function to display the character info
//
// A destructor that deletes the health pointer
//
// In main(), create a character, show its info, and delete memory safely.
//
//

#include <iostream>
#include <string>
using namespace std;

class Character
{
private:
	int* health; // Pointer to dynamically allocated health value
public:
	string name;
	int level;

	Character()
	{
		name = "Unknown";
		level = 1;
		health = new int; // allocate memory
		*health = 10; // set value through pointer
	}

	void displayCharacterInfo()
	{
		cout << "Name: \n" << name;
		cout << "Level: \n" << level;
		cout << "Health: \n" << *health << endl;
	}

	// destructor
	~Character()
	{
		delete health; // free memory
		cout << "Memory for health has been freed.\n";

	}
};

int main()
{
	Character p1;
	p1.name = "June";
	p1.level = 2;
	
	p1.displayCharacterInfo();
	
	return 0;
}
