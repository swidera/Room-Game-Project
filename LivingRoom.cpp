/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the cpp file for the LivingRoom class. It contains
**		a lose condition for the game as well as a fun side activity (REVENGE
**		on that baby sitter...even if it is mild)
*********************************************************************************/


#include "LivingRoom.h"


/*************************************************************************************
**																					**
**							LivingRoom::LivingRoom()								**
**				Default constructor for LivingRoom class. Sets the name.			**
**																					**
**************************************************************************************/
LivingRoom::LivingRoom()
{
	roomName = "Living Room";
	phonePlug = false;
	itemFound = false;
	itemPossession = false;
}



/*************************************************************************************
**																					**
**								LivingRoom::~LivingRoom()							**
**					Default constructor for LivingRoom class.						**
**																					**
**************************************************************************************/
LivingRoom::~LivingRoom()
{
}



/*************************************************************************************
**																					**
**							bool LivingRoom::viewEvent(int[])						**
**				This function elicits the event for the LivingRoom class.			**
**				This event only has a lose condition. It also has a fun				**
**				side event for the player.											**
**																					**
**************************************************************************************/
bool LivingRoom::viewEvent(int inv[])
{
	if (phonePlug == false)
	{
		std::cout << "You see your babysitter alone on the couch...vulnerable." << std::endl;
		std::cout << "She's usually pretty mean to you...how would you like to proceed?" << std::endl;
		std::cout << "1. Unplug her cell phone she's charging; she always seems to be on it." << std::endl;
		std::cout << "2. Smack her on the head!" << std::endl;
		std::cout << "3. Just leave the room, it's not worth the risk." << std::endl;
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
			userChoice = 0;
			phonePlug = true;
			std::cout << "Ha! That'll show her. Good luck getting on instagram now!" << std::endl;
			std::cout << "She appears to still be asleep, luckily the prank didn't wake her." << std::endl;
			std::cout << "How would you like to proceed?" << std::endl;
			std::cout << "1. Smack her on the head!" << std::endl;
			std::cout << "2. Just leave the room, it's not worth the risk." << std::endl;
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
				std::cout << "Oh no, that woke her up. Looks like I'll be stuck in my room the rest of the night..." << std::endl;
				return true;
			}


		}
		else if (userChoice == 2)
		{
			std::cout << "Oh no, that woke her up. Looks like I'll be stuck in my room the rest of the night..." << std::endl;
			return true;
		}
	}
	else
	{
		std::cout << "What would you like to do now in the living room?" << std::endl;
		std::cout << "1. Smack my babysitter on the head!" << std::endl;
		std::cout << "2. Just leave the room, it's not worth the risk." << std::endl;
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
			std::cout << "Oh no, that woke her up. Looks like I'll be stuck in my room the rest of the night..." << std::endl;
			return true;
		}

	}
	return false;
}



/*************************************************************************************
**																					**
**							void LivingRoom::addItem(int*)							**
**					There are no items to add in the LivingRoom class.				**
**																					**
**************************************************************************************/
void LivingRoom::addItem(int*)
{
	return;
}



/*************************************************************************************
**																					**
**							std::string LivingRoom::getRoom()						**
**				This function will return the name of the room when called.			**
**																					**
**************************************************************************************/
std::string LivingRoom::getRoom()
{
	return roomName;
}