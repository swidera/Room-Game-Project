/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the main cpp file for the game. The game itself is a 
**		young boy trying to find where his parents hid his Christmas presents
**		before the holiday, and the boy will face several encounters in an effort
**		to find the presents.
*********************************************************************************/

#include <iostream>
#include <string>
#include "BackyardShed.h"
#include "Basement.h"
#include "Kitchen.h"
#include "YourRoom.h"
#include "LivingRoom.h"
#include "ParentRoom.h"

void displayRules();
Space * makeSpace(int);

int main()
{
	bool gameOver;
	bool gameWon;
	int inventory[5];
	int initialSelection = 0;
	std::string boyName;
	int numberSteps = 0;
	int maxSteps = 10;

	//initiate the game with the rules for playing (function below main)
	displayRules();

	std::cout << "1. Play Game." << std::endl;
	std::cout << "2. Exit Game." << std::endl;
	std::cin >> initialSelection;
	while ((initialSelection != 1 && initialSelection != 2) || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Please enter a valid option!" << std::endl;
		std::cin >> initialSelection;
		std::cout << std::endl;
	}
	std::cout << std::endl;

	while (initialSelection == 1)
	{
		/*
		Inventory notes....
		1 = Bat
		2 = Basement Key
		3 = Presents
		4 = 
		5 = 
		*/

		//ensure inventory everything equals 0 at start of game
		for (int i = 0; i < 5; i++)
		{
			inventory[i] = 0;
		}


		//name will change each time the game officially begins (or have option to change)
		boyName = " ";
		numberSteps = 0;
		gameOver = false;
		gameWon = false;
		//initiate pointers for the space class & subclasses
		Space * currentRoom;
		Space * tempRoom;
		Space * playerRoom;
		
		

		//set up the game board and connections of the rooms
		currentRoom = makeSpace(1);
		currentRoom->top = NULL;
		currentRoom->left = NULL;
		currentRoom->bottom = NULL;
		tempRoom = currentRoom;
		playerRoom = currentRoom;
		

		currentRoom = makeSpace(2);
		tempRoom->right = currentRoom;
		currentRoom->left = tempRoom;
		currentRoom->top = NULL;
		currentRoom->bottom = NULL;
		tempRoom = currentRoom;
		

		currentRoom = makeSpace(3);
		tempRoom->right = currentRoom;
		currentRoom->left = tempRoom;
		currentRoom->top = NULL;
		currentRoom->bottom = NULL;
		tempRoom = currentRoom;
	

		currentRoom = makeSpace(4);
		tempRoom->right = currentRoom;
		currentRoom->left = tempRoom;
		currentRoom->top = NULL;
		currentRoom->bottom = NULL;
		tempRoom = currentRoom;


		currentRoom = makeSpace(5);
		tempRoom->right = currentRoom;
		currentRoom->left = tempRoom;
		currentRoom->top = NULL;
		currentRoom->bottom = NULL;
		tempRoom = currentRoom;
	

		currentRoom = makeSpace(6);
		tempRoom->right = currentRoom;
		currentRoom->left = tempRoom;
		currentRoom->top = NULL;
		currentRoom->bottom = NULL;
		currentRoom->right = NULL;

		//get character name and begin game
		std::cout << "Before we begin, what is the name of your character?" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, boyName);
		std::cout << std::endl;

		std::cout << boyName << ", your adventure begins now!" << std::endl;
		std::cout << "The babysitter is asleep and you want to find your Playstation present to play with your friends!" << std::endl;
		std::cout << "They are all currently playing, and your time is running out." << std::endl;
		std::cout << "Your adventure begins in Your Bedroom." << std::endl;
		std::cout << std::endl;

		//set this up so that it is easy to clear memory after each game
		tempRoom = playerRoom;

		//loop for the game that continues until either game is over or user wins
		while ((numberSteps < maxSteps) && (gameOver == false) && (gameWon == false))
		{
			int roomChoice = 0;

			currentRoom = playerRoom;
			

			//this was for item testing purposes throughout the game
			/*
			std::cout << "Array: ";
			for (int i = 0; i < 5; i++)
			{
				std::cout << inventory[i] << " ";
			}*/

			std::cout << std::endl;

			gameOver = currentRoom->viewEvent(inventory);
			currentRoom->addItem(inventory);
			numberSteps++;

			if (inventory[2] == 1)
			{
				gameWon = true;
			}

			if (gameWon == false && gameOver == false)
			{
				//after each iteration, add blank line for neater visual appearance
				std::cout << std::endl;
				if (currentRoom->right != NULL && currentRoom->left != NULL)
				{
					std::cout << "Where would you like to go next?" << std::endl;
					std::cout << "1. " << currentRoom->right->getRoom() << std::endl;
					std::cout << "2. " << currentRoom->left->getRoom() << std::endl;
					std::cin >> roomChoice;
					while ((roomChoice != 1 && roomChoice != 2) || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Please enter a valid option!" << std::endl;
						std::cin >> roomChoice;
						std::cout << std::endl;
					}
					if (roomChoice == 1)
					{
						playerRoom = playerRoom->right;
					}
					else
					{
						playerRoom = playerRoom->left;
					}
				}
				else if (currentRoom->right != NULL && currentRoom->left == NULL)
				{
					std::cout << "Where would you like to go next?" << std::endl;
					std::cout << "1. " << currentRoom->right->getRoom() << std::endl;
					std::cout << "There are no other rooms connected to this one!" << std::endl;
					std::cin >> roomChoice;
					while ((roomChoice != 1) || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Please enter a valid option!" << std::endl;
						std::cin >> roomChoice;
						std::cout << std::endl;
					}
					
					playerRoom = playerRoom->right;
					
				}
				else
				{
					std::cout << "Where would you like to go next?" << std::endl;
					std::cout << "1. " << currentRoom->left->getRoom() << std::endl;
					std::cout << "There are no other rooms connected to this one!" << std::endl;
					while ((roomChoice != 1) || std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Please enter a valid option!" << std::endl;
						std::cin >> roomChoice;
						std::cout << std::endl;
					}
				
					playerRoom = playerRoom->left;
					
				}
			}
		}



		if (gameWon == true)
		{
			std::cout << "You've done it! You've found your presents and get to play with your friends!" << std::endl;
		}

		if (numberSteps == maxSteps && gameWon == false)
		{
			std::cout << "You've run out of turns to play the game!" << std::endl;
		}

		if (gameWon == false)
		{
			std::cout << "It looks like you have lost. GAME OVER!" << std::endl;
		}

	
	
		
		//clear memory after game complete
		while (tempRoom->right != NULL)
		{
			playerRoom = tempRoom;
			tempRoom = tempRoom->right;
			playerRoom->right = NULL;
			playerRoom->left = NULL;
			tempRoom->left = NULL;
			delete playerRoom;
		}

		playerRoom = tempRoom;
		delete playerRoom;

		std::cout << "1. Play Again." << std::endl;
		std::cout << "2. Exit Game." << std::endl;
		std::cin >> initialSelection;
		while ((initialSelection != 1 && initialSelection != 2) || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter a valid option!" << std::endl;
			std::cin >> initialSelection;
			std::cout << std::endl;
		}
	}






	return 0;
}





/*************************************************************************************
**																					**
**									void displayRules()								**
**					This function is called at the beginning of the game			**
**					and explains the story and rules to the player.					**
**																					**
**************************************************************************************/
void displayRules()
{

	std::cout << "Welcome to Christmas Gift Scavenger Hunt!" << std::endl;
	std::cout << std::endl;
	std::cout << "In this game, you will play as a young child who is incredibly excited for the Christmas holiday!" << std::endl;
	std::cout << "Most years, you have waited patiently each time the holiday comes around for your gifts..." << std::endl;
	std::cout << "but this year is different. The newest Playstation has been released and you are anxiously" << std::endl;
	std::cout << "awaiting your opportunity to play with all your friends online." << std::endl;
	std::cout << std::endl;
	std::cout << "Based on information you've gathered so far, you know your present is somewhere in your house, " << std::endl;
	std::cout << "but you are not sure where. Finally, you have the opportunity to search the house. Your parents " << std::endl;
	std::cout << "have left you for the evening with a babysitter, and the babysitter has fallen asleep. You have " << std::endl;
	std::cout << "a few hours before your parents get home to search for your presents...but run into some unforeseen" << std::endl;
	std::cout << "challenges along the way!" << std::endl;
	std::cout << std::endl;
	std::cout << "In this game: " << std::endl;
	std::cout << "1. You will have 6 rooms to search including the Living Room, Parents Room, Your Room, Kitchen, Backyard Shed, Basement." << std::endl;
	std::cout << "2. In each room, there will be an event that occurs, and you will be given a series of options to interact with the event." << std::endl;
	std::cout << "3. You will have a limited number of turns, as you only have a few hours to search! (You will have 10 total turns to visit rooms)" << std::endl;
	std::cout << "4. In some instances, failure to interact with the environment properly or running out of time will result in a 'Game Over'" << std::endl;
	std::cout << std::endl;
	std::cout << "Are you ready?" << std::endl;
	std::cout << std::endl;

	return;
}








/*************************************************************************************
**																					**
**					Space * makeSpace(int, std::string)								**
**					This function creates Spaces dynamically.						**
**																					**
**************************************************************************************/
Space * makeSpace(int room)
{
	Space * roomSelection;

	switch (room)
	{
	case 1:
		roomSelection = new YourRoom;
		return roomSelection;
		break;

	case 2:
		roomSelection = new ParentRoom;
		return roomSelection;
		break;

	case 3:
		roomSelection = new LivingRoom;
		return roomSelection;
		break;

	case 4:
		roomSelection = new Basement;
		return roomSelection;
		break;

	case 5:
		roomSelection = new Kitchen;
		return roomSelection;
		break;

	case 6:
		roomSelection = new BackyardShed;
		return roomSelection;
		break;

	}

	roomSelection = new Space;

	return roomSelection;

}