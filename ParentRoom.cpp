/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the cpp file for the ParentRoom class. It has the
**		interactions a player will face while in the parent's room.
*********************************************************************************/

#include "ParentRoom.h"


/*************************************************************************************
**																					**
**								ParentRoom::ParentRoom()							**
**				Default constructor for ParentRoom class. Sets the name.			**
**																					**
**************************************************************************************/
ParentRoom::ParentRoom()
{
	roomName = "Parent's Room";
	itemFound = false;
	itemPossession = false;
}


/*************************************************************************************
**																					**
**								ParentRoom::~ParentRoom()							**
**				Default destructor for ParentRoom class.							**
**																					**
**************************************************************************************/
ParentRoom::~ParentRoom()
{
}



/*************************************************************************************
**																					**
**							bool ParentRoom::viewEvent(int[])						**
**				This function elicits the event for the ParentRoom class. This		**
**				event contains a win condition for the game and is important.		**
**				Namely, the player must collect the bat.							**
**																					**
**************************************************************************************/
bool ParentRoom::viewEvent(int inv[])
{
	std::cout << "You are now in your parents' room. It is dark, and difficult to see anything...what would you like to do?" << std::endl;
	std::cout << "1. Turn on the light." << std::endl;
	std::cout << "2. Search the room." << std::endl;
	std::cout << "3. Leave the room." << std::endl;
	std::cin >> userChoice;
	while ((userChoice != 1 && userChoice != 2 && userChoice != 3) || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Please enter a valid option!" << std::endl;
		std::cin >> userChoice;
		std::cout << std::endl;
	}

	if (itemFound != true)
	{

		if (userChoice == 1)
		{
			userChoice = 0;
			std::cout << "Much better! Now you can see around the room, what would you like to do?" << std::endl;
			std::cout << "1. Search the room." << std::endl;
			std::cout << "2. Leave the room." << std::endl;
			std::cin >> userChoice;
			while ((userChoice != 1 && userChoice != 2) || std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Please enter a valid option!" << std::endl;
				std::cin >> userChoice;
				std::cout << std::endl;
			}

			if (userChoice == 1)
			{
				std::cout << "You did not find your presents, but you found a bat. Would you like to carry the bat?" << std::endl;
				std::cout << "1. Yes." << std::endl;
				std::cout << "2. No." << std::endl;
				std::cin >> userChoice;
				while ((userChoice != 1 && userChoice != 2) || std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cout << "Please enter a valid option!" << std::endl;
					std::cin >> userChoice;
					std::cout << std::endl;
				}

				if (userChoice == 1)
				{
					itemFound = true;
				}
			}
			else
			{
				std::cout << "You have left the room." << std::endl;
				itemFound = false;
			}

		}
		else if (userChoice == 2)
		{
			std::cout << "You are unable to find anything with this lighting, and decide to leave the room!" << std::endl;
			itemFound = false;
		}
		else
		{
			std::cout << "You have left the room." << std::endl;
			itemFound = false;
		}
	}
	else
	{
		std::cout << "You've already found everything in this room!" << std::endl;
	}

	return false;
}



/*************************************************************************************
**																					**
**							void ParentRoom::addItem(int*)							**
**				This function will add the bat to the player's inventory if			**
**				it is successfully found (tracked by the itemFound variable).		**
**																					**
**************************************************************************************/
void ParentRoom::addItem(int* inv)
{
	if (itemFound == true)
	{
		inv[0] = 1;
	}
	return;
}



/*************************************************************************************
**																					**
**							std::string ParentRoom::getRoom()						**
**				This function will return the name of the room when called.			**
**																					**
**************************************************************************************/
std::string ParentRoom::getRoom()
{
	return roomName;
}