#include "Monster.h"
#include <string>
#include <iostream>

class Monster
{
	std::string monsterName;
	int maxHealth;
	int currentHealth;
	int strength;

public:

	// Default Monster is going to be a goblin
	Monster()
	{
		monsterName = "Goblin";
		maxHealth = 3;
		currentHealth = 3;
		strength = 1;
	}

	// We can then overload the constructor and we could different monsters because of this
	Monster(std::string _name, int _maxHealth, int _currentHealth, int _strength)
	{
		monsterName = _name;
		maxHealth = _maxHealth;
		currentHealth = _currentHealth;
		strength = _strength;

	}

	// Getters
	std::string GetName()
	{
		return monsterName;
	}

	int GetMaxHealth()
	{
		return maxHealth;
	}

	int GetCurrentHealth()
	{
		return currentHealth;
	}

	int GetStrength()
	{
		return strength;
	}
	
	// Setters
	void SetMonsterName(std::string _name)
	{
		monsterName = _name;
	}

	void SetMaxHealth(int _maxHealth)
	{
		maxHealth = _maxHealth;
	}

	void SetCurrentHealth(int _currentHealth)
	{
		currentHealth = _currentHealth;
	}

	void SetStrength(int _strength)
	{
		strength = _strength;
	}

	// display all
	void DisplayAll()
	{
		std::cout << "Monster Name: " << monsterName << std::endl;
		std::cout << "Health: " << currentHealth << "/" << maxHealth << std::endl;
		std::cout << "Strength: " << strength << std::endl;

	}
};