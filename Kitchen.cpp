/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the cpp file for the kitchen class. It contains a lose
**		condition for the game (overeating cookies, darn cookies!)
*********************************************************************************/

#include "Kitchen.h"


/*************************************************************************************
**																					**
**									Kitchen::Kitchen()								**
**				Default constructor for Kitchen class. Sets the name.				**
**																					**
**************************************************************************************/
Kitchen::Kitchen()
{
	roomName = "Kitchen";
	itemFound = false;
	itemPossession = false;
}


/*************************************************************************************
**																					**
**									Kitchen::~Kitchen()								**
**				Default destructor for Kitchen class. Sets the name.				**
**																					**
**************************************************************************************/
Kitchen::~Kitchen()
{
}



/*************************************************************************************
**																					**
**							bool Kitchen::viewEvent(int[])							**
**				This function elicits the event for the Kitchen class.				**
**				This event only has a lose condition.								**
**																					**
**************************************************************************************/
bool Kitchen::viewEvent(int inv[])
{
	std::cout << "I doubt they hid the presents in the kitchen, but do I want a snack?" << std::endl;
	std::cout << "1. Eat all the cookies." << std::endl;
	std::cout << "2. Explore elsewhere." << std::endl;
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
		std::cout << "Oh no...I see why I am not in control of what I eat on a day to day basis. I suddenly feel too sick to continue..." << std::endl;
		return true;
	}

	return false;
}



/*************************************************************************************
**																					**
**								void Kitchen::addItem(int*)							**
**					There are no items to add in the kitchen class.					**
**																					**
**************************************************************************************/
void Kitchen::addItem(int*)
{
	return;
}



/*************************************************************************************
**																					**
**							std::string Kitchen::getRoom()							**
**				This function will return the name of the room when called.			**
**																					**
**************************************************************************************/
std::string Kitchen::getRoom()
{
	return roomName;
}