#pragma once
#include "House.h"
class Rock :public Club
{
private:
	Vector<User> users;

public:
	Rock(const char* name, double VodkaPrice, double WiskeyPrice);
	bool AddUser(User& user);
	bool RemoveUser(User& user);
	Club* clone();
};
