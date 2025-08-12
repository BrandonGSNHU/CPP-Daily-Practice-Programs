/* This cpp file initializes the object with name type and power level
*  the constructor gives feedback when a creature is created 
*  the deconstructor gives feedback when the creature is deleted
*  The function PrintoInfo() displayus all of the stored info
*/

#include "MagicalCreatures.h"
#include <iostream>


MagicalCreature::MagicalCreature(std::string creatureName, std::string creatureType, int level)
	: name(creatureName), type(creatureType), powerLevel(level)
{
	std::cout << "A new " << type << " named " << name << " with power level " << powerLevel << " has entered the world!\n";
}

MagicalCreature::~MagicalCreature()
{
	std::cout << name << " has vanished into the mist.\n";
}

void MagicalCreature::PrintInfo() const
{
	std::cout << "Name: " << name << ", Type: " << type << ", Power level: " << powerLevel << "\n";
}