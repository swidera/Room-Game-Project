/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the head file for the YourRoom class
*********************************************************************************/


#include "Space.h"
class YourRoom :
	public Space
{
private:
	int userChoice;
	bool itemFound;
	bool itemPossession;
	std::string roomName;

public:
	YourRoom();
	~YourRoom();
	virtual bool viewEvent(int[]);
	virtual void addItem(int*);
	virtual std::string getRoom();
};

