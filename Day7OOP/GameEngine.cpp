#include "GameEngine.h"
#include <iostream>
#include "PlayerCharacter.cpp"
#include "Monster.cpp"
#include <fstream> // allows for file i/o

class GameEngine
{
	PlayerCharacter pc;
	Monster monster;
	bool characterCreated = false; // this used for a check in the game loop so we don't continually prompt them for their name
	bool isGameEnded = false; // used for an endgame condition, stops the loop
	bool isGameNew = true;

public:

	GameEngine()
	{
		std::cout << "Game Made " << std::endl;
	}

	void GameRun()
	{
		std::string userInput = ""; // moved this so we don't make another string for user input

		// This will end up being changed quite a bit but for now (the start of this method) we're going to leave its signature alone

		// This is where the bulk of the game code or game method calls will happen
		if (isGameNew == true)
		{
			do
			{
				std::cout << "1) Start New Game\n 2) Load Game\n 3)Exit" << std::endl;
				std::cin >> userInput;
			} while (userInput != "1" && userInput != "2" && userInput != "3");
		}

		if (userInput == "1")
		{
			// This is for creating a new character
			if (characterCreated == false)
			{
				CharacterCreate();
				pc.DisplayAll();
			}
		}
		else if (userInput == "2")
		{
			// this is for loading a character
			//std::string characterName;
			//int maxHealth;
			//int currentHealth;
			//int strength;
			//int level;
			// we need to write to a file the fields of the player character
			// this will happen below in the GameRun method as part of that menu
			// HERE however we need to load the playercharacter from the text file
			// Things that we need to make sure are done before doing this
			// Make sure there is a constructor for player character that can handle all of these
			// Make sure there is a file to read
			// and alter the menu in GameRun
		}
		else if (userInput == "3")
		{
			// This is for exiting the game
			isGameEnded = true;

		}
		//Pause();





		




		while (isGameEnded == false) // this condition may change - we could end up making a bool field that contains context if the game is ended or not
		{



			// Game menu
			// 3 options - fight, rest, quit and we're going to start with quit
			// Prompt the user for their option - display the menu
			Line();
			std::cout << "Menu Options" << std::endl;
			Line();

			// This is going to end up changing to have another option save character
			// We'll need to alter the menu, alter the if statement, create a save method
			std::cout << "1) Fight a Monster \n2)Rest\n3)Save Character\n4)Quit" << std::endl;

			// Create a local string for userinput and allow the user to type
			
			std::cin >> userInput;

			// Based off userInput we can run the appropriate methods

			if (userInput == "1")
			{
				// Fight a monster
				Combat();
			}
			else if (userInput == "2")
			{
				// Rest
				//pc.SetCurrentHealth(pc.GetMaxHealth());
				pc.Rest();
			}
			else if (userInput == "3")
			{
				// This is where we are going to call the save method
				SaveGame();
			}
			else if (userInput == "4")
			{
				// Quit Game
				QuitGame();
			}
			else
			{
				// They typed something else
				std::cout << "You did not provided an accepted response, please try again..." << std::endl;
			}



			

			// We'll end up getting rid of these lines later one
			std::cout << "Please press any key followed by enter to continue..." << std::endl;
			std::string pause;
			std::cin >> pause;
		}

	}

	void SaveGame()
	{
		// we need to write the player stats and name to a file
		//std::string characterName;
		//int maxHealth;
		//int currentHealth;
		//int strength;
		//int level;

		// the goal here is to write each piece of info about the character to a file on it's own line
		// This creates and opens the saveFile.txt file, I'm going to assume this will always overwrite
		// So there always only be one save file we're currently not checking if it exists
		std::ofstream MyGame("saveFile.txt");

		// Write to the file
		MyGame << pc.GetName() << std::endl;
		MyGame << pc.GetMaxHealth() << std::endl;
		MyGame << pc.GetCurrentHealth() << std::endl;
		MyGame << pc.GetStrength() << std::endl;
		MyGame << pc.GetLevel(); // note no new line because this is the last line of info for the character

	



	}

	void QuitGame()
	{
		// The reason we're making this a method is so we have one method that can encapsulate all end of game reasons
		// for now it's a menu option or the player being slain hp is 0 or less
		// Decision on if the player is slain or if they chose to quit game
		// And we're going to base off of the players current health
		if (pc.GetCurrentHealth() > 0)
		{
			// They chose to quit
			std::cout << "Good bye for now, " << pc.GetName() << std::endl;
		}
		else
		{
			// They were slain
			std::cout << "YOU DIED" << std::endl;
		}

		isGameEnded = true;
	}

	void Line()
	{
		std::cout << "==============================" << std::endl;
	}

	void CharacterCreate()
	{
		// Our goal is to call the overloaded constructor or default based on player input
		// And if they want to name their character we're going to call the overloaded

		// Prompt the user if they want name
		std::cout << "Greetings traveler, what do you wish to be called? For Default type 1 (Tav)" << std::endl;
		std::string userInput;
		std::cin >> userInput;

		if (userInput == "1")
		{
			// Create a default PlayerCharacter
			PlayerCharacter newPlayer;
			pc = newPlayer;
			pc.SetCharacterName("Tav");

		}
		else
		{
			// This is for naming the character
			std::cout << "Please enter your name" << std::endl;
			std::cin >> userInput;
			PlayerCharacter newPlayer(userInput);
			pc = newPlayer;
			pc.SetCharacterName(userInput);
		}

		characterCreated = true;
	}

	void Combat()
	{
		// we are going to assume for now they are fighting a new goblin
		Monster goblin; // new monster object goblin - default constructor
		monster = goblin; // assign the monster field the goblin monster object

		while (pc.GetCurrentHealth() > 0 && monster.GetCurrentHealth() > 0)
		{
			// while both the monster and player still hp remaining we continue combat

			// We're going to assume the monster goes first

			// Then the player goes

			// Damage is their strength stat

			// the output arrangement should be fixed if you care to
			if (pc.GetCurrentHealth() <= 0)
			{
				QuitGame();
			}
			else
			{
				Line();
				pc.SetCurrentHealth(pc.GetCurrentHealth() - monster.GetStrength()); // sets pc current health to current health - monster strength

				std::cout << monster.GetName() << ", hit's " << pc.GetName() << " for " << monster.GetStrength() << " points of damage! " << std::endl;
				pc.DisplayAll();

				Line();
				monster.SetCurrentHealth(monster.GetCurrentHealth() - pc.GetStrength()); // sets monster current health to current health - player strength
				std::cout << pc.GetName() << ", hit's " << monster.GetName() << " for " << pc.GetStrength() << " points of damage! " << std::endl;
				monster.DisplayAll();
				Line();
			}






		}
	}

	void Pause()
	{
		std::string pause = "";
		std::cout << "Pause" << std::endl;
		std::cin >> pause;
	}

	
};

