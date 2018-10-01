/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the cpp file for the basement class, containing the 
**		events and important variables for the basement class
*********************************************************************************/



#include "Basement.h"


/*************************************************************************************
**																					**
**								Basement::Basement()								**
**				Default constructor for Basement class. Sets the name.				**
**																					**
**************************************************************************************/
Basement::Basement()
{
	roomName = "Basement";
	spiderAlive = true;
	itemFound = false;
	itemPossession = false;
}


/*************************************************************************************
**																					**
**								Basement::~Basement()								**
**				Default destructor for Basement class.								**
**																					**
**************************************************************************************/
Basement::~Basement()
{
}



/*************************************************************************************
**																					**
**							bool Basement::viewEvent(int[])							**
**				This function elicits the event for the Basement class. space		**
**				has win and lose conditions. It also has an item requirement		**
**				in order to proceed as well as an item to be collected.				**
**				This is the most important event in the game for winning.			**
**																					**
**************************************************************************************/
bool Basement::viewEvent(int inv[])
{

	if (itemFound != true)
	{
		std::cout << "It looks like the basement light was left on...babysitter must've invited her boyfriend over again." << std::endl;
		std::cout << "Anyways, how would you like to proceed in the basement?" << std::endl;
		std::cout << "1. Search around." << std::endl;
		std::cout << "2. Leave room." << std::endl;
		std::cin >> userChoice;
		while ((userChoice != 1 && userChoice != 2) || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter a valid option!" << std::endl;
			std::cin >> userChoice;
			std::cout << std::endl;
		}

		if (spiderAlive == true)
		{
			if (userChoice == 1)
			{
				userChoice = 0;
				std::cout << "Oh my! As you were searching, an enormous spider appeared. It looks dangerous!" << std::endl;
				std::cout << "1. Attack spider." << std::endl;
				std::cout << "2. Run away and leave the basement." << std::endl;
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
					userChoice = 0;
					//search inventory, if bat is present, spider dies, if not then game over
					if (inv[0] == 1)
					{
						spiderAlive = false;
						std::cout << "You have defeated the nasty spider, and it looks like it dropped something shiny..." << std::endl;
						std::cout << "It looks like a key! Would you like to pick it up?" << std::endl;
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
							std::cout << "You have picked up the key and left the basement." << std::endl;
							itemFound = true;
						}
						else
						{
							std::cout << "You leave the key in the basement...hopefully it's not important." << std::endl;
							itemFound = false;
						}
					}
					else
					{
						std::cout << "The spider killed you, it is too strong to take on without a weapon! You were unable to find your presents and now you're also dead." << std::endl;
						return true;
						itemFound = false;
					}
				}
				else
				{
					std::cout << "You manage to escape the basement...but you can't help but wonder if something important was there." << std::endl;
					itemFound = false;
				}

			}
			else
			{
				std::cout << "You leave the basement...but you can't help but wonder if omething important was there." << std::endl;
				itemFound = false;
			}
		}
		else
		{
			std::cout << "You still see something shiny on the ground, would you like to pick it up now?" << std::endl;
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
				std::cout << "You have picked up the key and left the basement." << std::endl;
				itemFound = true;
			}
			else
			{
				std::cout << "You leave the key in the basement...hopefully it's not important." << std::endl;
				itemFound = false;
			}

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
**							void Basement::addItem(int*)							**
**					This function will add the shed key item if found.				**
**																					**
**************************************************************************************/
void Basement::addItem(int* inv)
{
	if (itemFound == true)
	{
		inv[1] = 1;
	}
	return;
}



/*************************************************************************************
**																					**
**							std::string Basement::getRoom()							**
**				This function will return the name of the room when called.			**
**																					**
**************************************************************************************/
std::string Basement::getRoom()
{
	return roomName;
}