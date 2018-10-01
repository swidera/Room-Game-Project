/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the cpp file for the space class. It is not meant for use
*********************************************************************************/

#include "Space.h"


/*************************************************************************************
**																					**
**									Space::Space()									**
**				Default constructor for space class. Sets the name.					**
**																					**
**************************************************************************************/
Space::Space()
{
	roomName = "Space";
	itemFound = false;
	itemPossession = false;
}



/*************************************************************************************
**																					**
**									Space::~Space()									**
**				Default destructor for space class.									**
**																					**
**************************************************************************************/
Space::~Space()
{

}



/*************************************************************************************
**																					**
**							bool Space::viewEvent(int[])							**
**				This function is not used by the program directly.					**
**																					**
**************************************************************************************/
bool Space::viewEvent(int inv[])
{
	return false;
}



/*************************************************************************************
**																					**
**							void Space::addItem(int*)								**
**				This function is not used by the program directly.					**
**																					**
**************************************************************************************/
void Space::addItem(int*)
{
	return;
}



/*************************************************************************************
**																					**
**							std::string Space::getRoom()							**
**				This function is not used by the program directly.					**
**																					**
**************************************************************************************/
std::string Space::getRoom()
{
	return roomName;
}