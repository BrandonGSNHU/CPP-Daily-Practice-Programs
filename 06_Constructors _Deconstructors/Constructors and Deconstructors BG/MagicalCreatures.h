/* This header file declares the class and the members.
*  The private members store data inside the object
*  The public members allow outside code to call the constructor, deconstructor
*  and the PrintInfo() function
*/

#pragma once
#include <string>

class MagicalCreature
{
private:
	std::string name;
	std::string type;
	int powerLevel;

public:
	MagicalCreature(std::string creatureName, std::string creatureType, int level); // constructor
	~MagicalCreature(); // deconstructor

	void PrintInfo() const;
	
};