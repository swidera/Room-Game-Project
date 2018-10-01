/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the header file for the ParentRoom class
*********************************************************************************/


#include "Space.h"
class ParentRoom :
	public Space
{
private:
	int userChoice;
	bool itemFound;
	bool itemPossession;
	std::string roomName;

public:
	ParentRoom();
	~ParentRoom();
	virtual bool viewEvent(int[]);
	virtual void addItem(int*);
	virtual std::string getRoom();
};

