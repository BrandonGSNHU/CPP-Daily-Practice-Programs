/*Create a C++ program that manages magical creatures in a fantasy world.Each creature has :

A name(e.g., "Griffin", "Dragon", "Unicorn")

A type(e.g., "Beast", "Spirit", "Elemental")

A power level(an int from 1 to 100)

Your task is to :

Create a MagicalCreature class.

Define a constructor that :

Initializes the name, type, and power level.

Prints a message like : "A new Dragon named Smaug has entered the world!"

Define a destructor that :

Prints a message like : "Smaug has vanished into the mist."

In your main() function :

    Dynamically create at least 3 magical creatures using new.

    Store them in a vector<MagicalCreature*>.

    Print each creature’s details using a PrintInfo() method.

    Properly delete each creature using delete to trigger the destructor.

    Optional challenge :

Track how many magical creatures exist at a given time using a static variable.
*/


#include <iostream>
#include "MagicalCreatures.h"
using namespace std;

int main()
{
    MagicalCreature* creature1 = new MagicalCreature("Boonch", "Dragon", 95);
    MagicalCreature* creature2 = new MagicalCreature("Rachel", "Unicorn", 100);
    MagicalCreature* creature3 = new MagicalCreature("June", "Frog", 1);

    cout << "\nCreature Info:\n";
    creature1->PrintInfo();
    creature2->PrintInfo();
    creature3->PrintInfo();

    // Delete creatures to trigger destructors
    delete creature1;
    delete creature2;
    delete creature3;

    return 0;
}



