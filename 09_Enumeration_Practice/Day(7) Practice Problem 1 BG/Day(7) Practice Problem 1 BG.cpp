/* Brandon Gallagher
*  08/18/2025
*
*  C++ Practice Task - Player Stamina System
*  Write a program that:
*  1. Defines a player class with:
*		a. maxStamina, currentStamina, staminaDrainRate, and
*		   staminaRegenRate.
*		b. An enum State { Idle, Sprinting, Exhausted }
*  2. Uses a function that:
*		a. Drains stamina while sprinting
*		b. Regenerates stamina while idle
*		c. Switches to exhausted if stamina hits zero
*  3. Demonstrates stamina updates in a loop
*/

#include <iostream>  // This library is necessary for std::cout and endl
#include <iomanip>   // This library is necessary for std::fixed and formatting
#include <string>    // This library is necessary for std::string
#include <algorithm> // This library is necessary for std::clamp

enum class State
{
	Idle,
	Sprinting,
	Exhausted
};

class Player
{
	// The constructor sets the intial values via an initialization list
	// Start Sprinting and Stop Sprinting act like input handlers
	// Update(deltaTime) is the per frame logic (drain / regen and state changes) 
	// The accessors stamina, maxStamina, and state are const meaning the only return read only
public:
	Player(double max, double drainPerSec, double regenPerSec);

	void StartSprinting();
	void StopSprinting();
	void Update(double deltaTime);

	double stamina() const { return currentStamina_; }
	double maxStamina() const { return maxStamina_; }
	State state() const { return state_; }

	static const char* ToString(State s);

private:
	double maxStamina_{ 100.0 };
	double currentStamina_{ 100.0 };
	double drainPerSecond_{ 10.0 };
	double regenPerSecond_{ 5.0 };
	State state_{ State::Idle };
};

Player::Player(double max, double drainPerSec, double regenPerSec)
	: maxStamina_(max),
	currentStamina_(max),
	drainPerSecond_(drainPerSec),
	regenPerSecond_(regenPerSec),
	state_(State::Idle) {
}

void Player::StartSprinting()
{
	// We only want to start sprinting from the Idle state and if we have stamina
	if (state_ == State::Idle && currentStamina_ > 0.0)
	{
		state_ = State::Sprinting;
	}
}

void Player::StopSprinting()
{
	if (state_ == State::Sprinting)
	{
		state_ = State::Idle;
	}
}

void Player::Update(double dt)
{
	// The switch / case statements for handling the stamina and state logic
	// dt is time step per tick ( units in seconds ) and we set dt = 0.1 in this program
	// Rate X Time = Amount:
	// If the drain is 20 per second and dt = 0.1 then we drain 20 * 0.1 = 2 stamin this tick
	// Doing thiss each tick is the simplest integeration (Euler) 
	switch (state_)
	{
	case State::Sprinting:
	{
		// When sprinting we want to drain the stamina and change the state to exhausted
		// once stamina reaches 0
		currentStamina_ -= drainPerSecond_ * dt;
		if (currentStamina_ <= 0.0)
		{
			currentStamina_ = 0.0;
			state_ = State::Exhausted;
		}
		break;
	}
	case State::Idle:
	{
		// In the Idle state we want to regen stamina until we hit the max
		currentStamina_ += regenPerSecond_ * dt;
		currentStamina_ = std::clamp(currentStamina_, 0.0, maxStamina_);
		break;
	}
	case State::Exhausted:
	{
		// In the Exhausted state we want to regenerate stamina and only allow sprinting
		// once the stamina reaches a minimum of thirty percent full
		// std::clamp prevents any under or overflow
		// std::clamp ( x, lo, hi) returns x bounded to [lo, hi]
		// if x < lo you get lo
		// if x > hi you get hi
		// else you get x unchanged
		// This is used to keep the stamina in a valid range
		currentStamina_ += regenPerSecond_ * dt;
		currentStamina_ = std::clamp(currentStamina_, 0.0, maxStamina_);
		const double readyThreshold = 0.30 * maxStamina_;
		if (currentStamina_ >= readyThreshold)
		{
			state_ = State::Idle;
		}
		break;
	}
	}
}

// A helper to print the state
const char* Player::ToString(State s)
{
	switch (s)
	{
	case State::Idle:	   return "Idle";
	case State::Sprinting: return "Sprinting";
	case State::Exhausted: return "Exhausted";
	}
	return "?";
}

int main()
{
	// We want to simulate ten seconds with a fixed time step of 
	// dt = 0.1s and the sprinting window of 3.0 - 6.0 seconds
	// I placed drain and regen in line to help clarify which one is drain rate
	// and which one is regen rate
	Player p(100.0, /*drain*/ 20.0, /*regen*/ 15.0);

	const double dt = 0.1;
	double t = 0.0;

	std::cout << std::fixed << std::setprecision(1);

	// This simulates ten seconds total one hundred ticks at 0.1s
	for (int i = 0; i < 100; ++i)
	{
		if (t >= 3.0 && t < 6.0)
		{
			p.StartSprinting();
		}
		else
		{
			p.StopSprinting();
		}

		p.Update(dt);

		if (i % 10 == 0)
		{
			// Print once per second every ten ticks
			std::cout << "Tick = " << std::setw(4) << t << "s "
				<< "state = " << Player::ToString(p.state()) << " "
				<< "stamina = " << std::setw(5) << p.stamina()
				<< "/" << p.maxStamina() << "\n";
		}

		t += dt;
	}
	return 0;
}