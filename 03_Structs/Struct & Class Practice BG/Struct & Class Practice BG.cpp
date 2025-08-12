// Struct & Class Practice BG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
using namespace std;

class GameCharacter
{
private:
    string name = "";
    int level = 1;
    int health = 100;
    int strength = 5;

public:
    void set_name(string);
    string get_name();
    void set_level(int);
    int get_level();
    void set_health(int);
    int get_health();
    void set_strength(int);
    int get_strength();
    void level_up();
    void print_stats();
};

int main()
{
    GameCharacter player1;
    GameCharacter player2;

    player1.set_name("Rachel");
    player1.set_level(100);
    player1.set_level(100);
    player1.set_health(100);
    player1.set_strength(10);

    player2.set_name("Brandon");
    player2.set_level(1);
    player2.set_health(100);
    player2.set_strength(1);

    cout << "\nPlayer 1 Stats:\n";
    player1.print_stats();
    cout << "\nPlayer 2 Stats:\n";
    player2.print_stats();

    player1.level_up();
    cout << "\nPlayer 1 after level up:\n";
    player1.print_stats();
    
    player2.level_up();
    cout << "\nPlayer 1 after level up:\n";
    player2.print_stats();
}

void GameCharacter::set_name(string name)
{
    this->name = name;
}

string GameCharacter::get_name()
{
    return name;
}

void GameCharacter::set_level(int level)
{
    if (level < 1)
    {
        throw invalid_argument("Level must be 1 or greater.\n");
    }

    this->level = level;
}

int GameCharacter::get_level()
{
    return level;
}

void GameCharacter::set_health(int health)
{
    if (health < 1 || health > 100)
    {
        throw invalid_argument("Health must be between one and one hundred.\n");
    }

    this->health = health;
}

int GameCharacter::get_health()
{
    return health;
}

void GameCharacter::set_strength(int strength)
{
    if (strength < 1 || strength > 10)
    {
        throw invalid_argument("Strength must be between one and ten.\n");
    }

    this->strength = strength;
}

int GameCharacter::get_strength()
{
    return strength;
}

void GameCharacter::level_up()
{
    this->level += 1;
    
    if (this->strength < 10)
    {
        this->strength += 1;
    }

    this->health = 100;
    
}

void GameCharacter::print_stats()
{
    cout << "Name: " << name << "\nLevel: " << level 
         << "\nHealth: " << health 
         << "\nStrength: " << strength << endl;
}
