/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the header file for the kitchen class
*********************************************************************************/



#include "Space.h"
class Kitchen :
	public Space
{
private:
	int userChoice;
	bool itemPossession;
	bool itemFound;
	std::string roomName;

public:
	Kitchen();
	~Kitchen();
	virtual bool viewEvent(int[]);
	virtual void addItem(int*);
	virtual std::string getRoom();
};

