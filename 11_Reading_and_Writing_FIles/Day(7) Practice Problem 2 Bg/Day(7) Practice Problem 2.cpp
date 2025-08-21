/* Brandon Gallagher
*  08/18/2025
* 
*  Learning fstream:
*  
*  fstream is the file stream library and it contains three main classes:
*  1. std::ofstream - > output file stream (writing to a file)
*  2. std::ifstream - > input file stream (reading from a file)
*  3. std::fstream  - > both input and output (read + write)
*  
*  CSV Files:
*  
*  A CSV file is a file with text separated by commas ( comma separated values )
*  Ex - outFile << time << "," << PLayer::ToString(p.state()) << "," << p.stamina() << "\n"
* 
*  This program updates Day(7) Practice Problem 1 - Stamina enumeration to write the stamina info to
*  a CSV file stored in the Visual Studio project folder.
*/

#include <iostream> // Used for std cout
#include <iomanip> // Library for setw and precision a.k.a formating
#include <string> // Library for string functions
#include <algorithm> // Library for std clamp to prevent under or overflow
#include <fstream> // Library for writing and reading files

// Enum class creation to store our different states and allow us to swap between them
// based on different factors 
enum class State
{
	Idle,
	Sprinting,
	Exhausted
};

// Our class Player and the constructor to set and hold default data variables until
// they are changed in main when an object is created.
// We want different variables for stamina to be public so they can be edited and changed 
// We also keep some simple functions in public such as Start and Stop sprinting to easily enable 
// changes between the states 
class Player
{
public:
	// This is our constructor where we create the member initializer list.
	// The constructor has the same name as the class and initializes the objects data members
	// AKA this sets the default values of the data members if we desire. Here we have them set to
	// variables that we can then change when we create a player object in main.
	// We also use an underscore in the naming convention so its easy to tell apart variables within
	// class members
	Player(double max, double drainPerSec, double regenPerSec)
		: maxStamina_(max),
		  currentStamina_(max),
		  drainPerSecond_(drainPerSec),
		  regenPerSecond_(regenPerSec),
		  state_(State::Idle) {}

	void StartSprinting()
	{
		if (state_ == State::Idle && currentStamina_ > 0.0)
		{
			state_ = State::Sprinting;
		}
	}

	void StopSprinting()
	{
		if (state_ == State::Sprinting)
		{
			state_ = State::Idle;
		}
	}

	void Update(double dt)
	{
		switch (state_)
		{
		case State::Sprinting:
		{
			// currentStamina = currentStamina - (drainPerSecond * dt)
			currentStamina_ -= drainPerSecond_ * dt; // Drain = Rate * Time
			if (currentStamina_ <= 0.0)
			{
				currentStamina_ = 0.0;
				state_ = State::Exhausted;
			}
			break;
		}
		case State::Idle:
		{
			currentStamina_ += regenPerSecond_ * dt; // Regen = Rate * Time
			currentStamina_  = std::clamp(currentStamina_, 0.0, maxStamina_);
			break;
		}
		case State::Exhausted:
		{
			// Reminder: += is shorthand for a = a = b or 
			// currentStamina = currentStamina + ( regenPerSecond_ * dt)
			// This doesn't replace currentStamina it adds whatever regenPerSecond * dt is to currentStamina
			// I.E increase += or decrease -= by this amount 
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

	double stamina() const { return currentStamina_; }
	double maxStamina() const { return maxStamina_; }
	State state() const { return state_; }

	static const char* ToString(State s)
	{
		switch (s)
		{
		case State::Idle: return "Idle";
		case State::Sprinting: return "Sprinting";
		case State::Exhausted: return "Exhausted";
		}
		
		return "?";
	}

private:
	double maxStamina_{ 100.0 };
	double currentStamina_{ 100.0 };
	double drainPerSecond_{ 10.0 };
	double regenPerSecond_{ 5.0 };
	State state_{ State::Idle };
};

int main()
{
	Player p(100.0, 20.0, 15.0);

	// std::ofstream = output file stream or writing to files.
	// This line opens and or creates the "Stamina_log.csv" in the programs working directory.
	std::ofstream log("Stamina_Log.csv");

	// Always check the stream and place validation checks if the file opening fails throw an error
	if (!log)
	{
		// std::cerr is the standard error stream 
		std::cerr << "Failed to open Stamina_log.csv\n";
		// Non zero return indicates failure
		return 1;
	}

	// CSV Header
	// Space after commas is okay but most CSV files omit them
	log << "Time, State, Stamina\n";

	const double dt = 0.1;
	double t = 0.0;

	std::cout << std::fixed << std::setprecision(1);

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

		// Print log once per second ( since dt = 0.1 - > 10 ticks = 1 second)
		// Reminder: " % " Is the modulo operator the remainder of division 
		if (i % 10 == 0)
		{
			std::cout << "Tick = " << std::setw(4) << t << "s "
					  << "State = " << Player::ToString(p.state()) << " "
					  << "Stamina = " << std::setw(5) << p.stamina()
					  << "/" << p.maxStamina() << "\n";

			// This line writes one CSV record (row): Time, State, Stamina, and a newline
			// Using operator << just like with std::cout
			log << t << "," << Player::ToString(p.state()) << "," << p.stamina() << "\n";
		}

		// This line increases simulated time by 0.1s each loop
		t += dt;
	}

	log.close(); // Optional, closes automatically at scope end
	return 0;
}
