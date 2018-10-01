/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the cpp file for the YourRoom class. It lists the 
**		actions that can be done while in your room for the player
*********************************************************************************/

#include "YourRoom.h"



/*************************************************************************************
**																					**
**								YourRoom::YourRoom()								**
**				Default constructor for YourRoom class. Sets the name.				**
**																					**
**************************************************************************************/
YourRoom::YourRoom()
{
	roomName = "Your Room";
	itemFound = false;
	itemPossession = false;
}


/*************************************************************************************
**																					**
**								YourRoom::~YourRoom()								**
**				Default destructor for YourRoom class.								**
**																					**
**************************************************************************************/
YourRoom::~YourRoom()
{
}



/*************************************************************************************
**																					**
**							bool YourRoom::viewEvent(int[])							**
**				This function elicits the event for the YourRoom class. This		**
**				event has an option to lay around. There are no win or lose			**
**				conditions in this event.											**
**																					**
**************************************************************************************/
bool YourRoom::viewEvent(int inv[])
{
	std::cout << "From your bedroom, what would you like to do?" << std::endl;
	std::cout << "1. Leave room." << std::endl;
	std::cout << "2. Lay down." << std::endl;
	std::cin >> userChoice;
	while ((userChoice != 1 && userChoice != 2) || std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Please enter a valid option!" << std::endl;
		std::cin >> userChoice;
		std::cout << std::endl;
	}

	while (userChoice == 2)
	{
		std::cout << "You laid down...but there are still presents to find. What would you like to do?" << std::endl;
		std::cout << "1. Leave room." << std::endl;
		std::cout << "2. Lay down." << std::endl;
		std::cin >> userChoice;
		while ((userChoice != 1 && userChoice != 2) || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter a valid option!" << std::endl;
			std::cin >> userChoice;
			std::cout << std::endl;
		}
	}

	return false;
}


/*************************************************************************************
**																					**
**							void YourRoom::addItem(int*)							**
**					There are no items to be added in this room.					**
**																					**
**************************************************************************************/
void YourRoom::addItem(int*)
{
	return;
}



/*************************************************************************************
**																					**
**							std::string YourRoom::getRoom()							**
**				This function will return the name of the room when called.			**
**																					**
**************************************************************************************/
std::string YourRoom::getRoom()
{
	return roomName;
}