/********************************************************************************
**	Name: Alex Swider
**	Date: June 12, 2018
**	Description: This is the header file for the space class
*********************************************************************************/

#ifndef SPACE_H
#define SPACE_H


#include <iostream>
#include <string>


class Space
{
private:
	bool itemFound;
	bool itemPossession;
	std::string roomName;

public:
	Space * top;
	Space * left;
	Space * right;
	Space * bottom;
	Space();
	~Space();
	virtual bool viewEvent(int[]);
	virtual void addItem(int*);
	virtual std::string getRoom();

};

#endif // !SPACE_H