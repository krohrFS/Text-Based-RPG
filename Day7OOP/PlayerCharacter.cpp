#include "PlayerCharacter.h"
#include <string>
#include <iostream>

class PlayerCharacter
{
	std::string characterName;
	int maxHealth;
	int currentHealth;
	int strength;
	int level;
public:
	PlayerCharacter()
	{
		characterName = "Tav";
		maxHealth = 5;
		currentHealth = 5;
		strength = 2;
		level = 1;
	}

	PlayerCharacter(std::string _name)
	{
		characterName = _name;
		maxHealth = 5;
		currentHealth = 5;
		strength = 2;
		level = 1;
	}

	// Getters
	std::string GetName()
	{
		return characterName;
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

	int GetLevel()
	{
		return level;
	}
	
	// Setters
	void SetCharacterName(std::string _name)
	{
		characterName = _name;
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

	void SetLevel(int _level)
	{
		level = _level;
	}

	void DisplayAll()
	{
		std::cout << "Character Name: " << characterName << std::endl;
		std::cout << "Level: " << level << std::endl;
		std::cout << "Health: " << currentHealth << "/" << maxHealth << std::endl;
		std::cout << "Strength: " << strength << std::endl;

	}

	void Rest()
	{
		std::cout << characterName << ", rests to regain health." << std::endl;
		currentHealth = maxHealth;
		DisplayAll();
	}


};