#pragma once
#include "Folk.h"
class House :public Club
{
private:
	char* dj;
	Vector<User> users;
	void CopyFrom(const House& other);
	void Free();
public:
	House(const House& other);
	House& operator=(const House& other);
	House(const char* name, double VodkaPrice, double WiskeyPrice, const  char* dj);
	bool AddUser(User& user);
	bool RemoveUser(User& user);
	Club* clone();
};
