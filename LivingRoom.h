/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the header file for the LivingRoom class
*********************************************************************************/



#include "Space.h"
class LivingRoom :
	public Space
{
private:
	int userChoice;
	bool itemPossession;
	bool itemFound;
	std::string roomName;
	bool phonePlug;

public:
	LivingRoom();
	~LivingRoom();
	virtual bool viewEvent(int[]);
	virtual void addItem(int*);
	virtual std::string getRoom();
};

