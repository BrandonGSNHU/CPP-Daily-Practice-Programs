/* Brandon Gallagher
*  08/11/2025
* 
*  Stamina Drain and Regen with enum classes for unreal engine 5
*/

#include <iostream>

// This enum class defines out state whether we're draining stamina or regenerating
enum class EStaminaState
{
	Draining,
	Regenerating
};

int main()
{
	double maxStamina = 100.0;
	double stamina = maxStamina;
	double drainRate = 20.0;
	double regenRate = 15.0;

	EStaminaState state = EStaminaState::Draining;

	// Simulate updates for 200 ticks
	// One loop that checks the state ever iteration
	// If draining reduce to 0.0
	// If regenerating add until 100.0 or max stamina
	for (int tick = 0; tick < 200; ++tick)
	{
		if (state == EStaminaState::Draining)
		{
			stamina -= drainRate * 0.1; // Draining per 0.1s
			if (stamina <= 0.0)
			{
				stamina = 0.0;
				state = EStaminaState::Regenerating;
			}
			std::cout << "Drain: " << stamina << "\n";
		}
		else if (state == EStaminaState::Regenerating)
		{
			stamina += regenRate * 0.1; // Regen per 0.1s
			if (stamina >= maxStamina)
			{
				stamina = maxStamina;
				state = EStaminaState::Draining; // Switch back if you want to loop
			}
			std::cout << "Regen: " << stamina << "\n";
		}
	}
	return 0;
}