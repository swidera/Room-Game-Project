/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the cpp file for the BackyardShed class. This is 
**		where the presents are hidden and has the win conditions for the game
*********************************************************************************/



#include "BackyardShed.h"


/*************************************************************************************
**																					**
**							BackyardShed::BackyardShed()							**
**				Default constructor for BackyardShed class. Sets the name.			**
**																					**
**************************************************************************************/
BackyardShed::BackyardShed()
{
	roomName = "Backyard Shed";
	itemFound = false;
	itemPossession = false;
}



/*************************************************************************************
**																					**
**							BackyardShed::~BackyardShed()							**
**				Default destructor for BackyardShed class.							**
**																					**
**************************************************************************************/
BackyardShed::~BackyardShed()
{
}



/*************************************************************************************
**																					**
**							bool BackyardShed::viewEvent(int[])						**
**				This function elicits the event for the BackyardShed class.			**
**				If all preliminary events necessary are completed, then				**
**				the player should have the key to unlock the shed and win			**
**				the game by finding the presents.									**
**																					**
**************************************************************************************/
bool BackyardShed::viewEvent(int inv[])
{
	std::cout << "The moment of truth...this is the most likely spot my presents would be." << std::endl;
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Open the shed." << std::endl;
	std::cout << "2. Give up." << std::endl;
	std::cout << "3. Look elsewhere." << std::endl;
	std::cin >> userChoice;
	while ((userChoice != 1 && userChoice != 2 && userChoice != 3) || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Please enter a valid option!" << std::endl;
		std::cin >> userChoice;
		std::cout << std::endl;
	}
	if (userChoice == 1)
	{
		if (inv[1] == 1)
		{
			std::cout << "You unlocked the door with the key you found in the basement, and inside you found your presents!" << std::endl;
			itemFound = true;
			return false;
		}
		else
		{
			std::cout << "The door is locked...there has to be a key somewhere for this shed!" << std::endl;
			itemFound = false;
		}
	}
	else if (userChoice == 2)
	{
		std::cout << "Well, the adventure was fun while it lasted. Hopefully I wasn't too close to the presents!" << std::endl;
		itemFound = false;
		return true;
	}
	else
	{
		itemFound = false;
	}

	return false;
}



/*************************************************************************************
**																					**
**							void BackyardShed::addItem(int*)						**
**					This function will add the presents if found, winning the game	**
**																					**
**************************************************************************************/
void BackyardShed::addItem(int* inv)
{
	if (itemFound == true)
	{
		inv[2] = 1;
	}

	return;
}



/*************************************************************************************
**																					**
**							std::string BackyardShed::getRoom()						**
**				This function will return the name of the room when called.			**
**																					**
**************************************************************************************/
std::string BackyardShed::getRoom()
{
	return roomName;
}