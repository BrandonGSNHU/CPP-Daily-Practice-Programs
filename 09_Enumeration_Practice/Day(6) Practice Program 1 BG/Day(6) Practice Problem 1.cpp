/* Brandon Gallagher
*  08/13/2025
*  Enumeration and Structs:
*  Create a console program that -
*  1. Uses an enum for ability state (Ready, OnCooldown, Disabled)
*  2. Uses a struct to store ability data
*  3. Simulates a simple loop where abilities go on cooldown after use and tick down each turn
*/

#include <iostream>
#include <vector>
#include <string>

// enum class to track and read abilities easily
// enum class is used over enum to ensure its type safe and there isn't any accidental conversions
enum class AbilityState 
{ 
	Ready,		// Ability is ready
	OnCooldown, // Ability is on cooldown
	Disabled	// Locked ability
};

// We use a struct to hold custom, different data types 
// We can then create abilites using these variables like a fireball or etc.
struct Ability
{
	std::string  Name;
	float		 CooldownTime;
	float		 CurrentCooldown;
	AbilityState State;
};

// We add const to our print and update functions since print is only ever printing and we dont want updates
//and we don't want to modify the delta time.
//adasd
void printAbilityInfo(const Ability& ability);
void updateAbility(Ability& ability, const float deltaTime);

int main()
{
	// We use a vector so the array stays dynamic and then we initialize each 
	// field according to our struct.
	std::vector<Ability> abilities =
	{
		{"Fireball",	   5.0f, 0.0f, AbilityState::Ready},
		{"Lightning Bolt", 8.0f, 0.0f, AbilityState::Ready},
		{"Orbital Strike", 12.0f, 0.0f, AbilityState::Ready}
	};

	// This for loop simulates 10 turns and we cast fireball on the first and fifth turn.
	// This demonstrates the cooldown for the ability and the output displays the cooldown
	// timer.
	for (int turn = 1; turn <= 10; ++turn)
	{
		std::cout << "\nTurn " << turn << ":\n";

		if (turn == 1 || turn == 5)
		{
			abilities[0].State = AbilityState::OnCooldown;
			abilities[0].CurrentCooldown = abilities[0].CooldownTime;
			std::cout << "Used " << abilities[0].Name << "!\n";
		}

		// This is a range based for loop over the vector.
		// " auto& ability " simply means for ech ability object inside the vector give me a reference named " ability
		// The auto& lets the compiler deduce the element type and we pass a reference so the original is changed.
		// Overall this for loop updates the ability and then prints the information
		for (auto& ability : abilities)
		{
			updateAbility(ability, 1.0f); // Tick by one second
			printAbilityInfo(ability);
		}
	}

	return 0;
}

// The print function prints the ability information such as name and the cooldown.
// We don't want tot change the ability so we pass a const reference
void printAbilityInfo(const Ability& ability)
{
	std::cout << ability.Name << " - ";
	if (ability.State == AbilityState::Ready)
	{
		std::cout << "Ready";
	}
	else if (ability.State == AbilityState::OnCooldown)
	{
		std::cout << "On Cooldown (" << ability.CurrentCooldown << "'s) left";
	}
	else
	{
		std::cout << "Disabled";
	}

	std::cout << "\n";
}

// We pass " Ability& " because we want to pass the ability by reference so the change affects the original
// If its OnCooldown subtract time and when it reaches 0 set it to ready again
// This function updates the cooldown timers and changes the ability state back to ready when the timer 
// reaches 0
void updateAbility(Ability& ability, float deltaTime)
{
	if (ability.State == AbilityState::OnCooldown)
	{
		ability.CurrentCooldown -= deltaTime;

		if (ability.CurrentCooldown <= 0)
		{
			ability.CurrentCooldown = 0;
			ability.State = AbilityState::Ready;
		}
	}
}