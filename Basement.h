/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the basement header file
*********************************************************************************/


#include "Space.h"

class Basement:
	public Space
{
private:
	int userChoice;
	bool itemFound;
	bool itemPossession;
	std::string roomName;
	bool spiderAlive;

public:
	Basement();
	~Basement();
	virtual bool viewEvent(int[]);
	virtual void addItem(int*);
	virtual std::string getRoom();
};

