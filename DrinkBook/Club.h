#pragma once
#include "Vector.h"
#include "User.h"
class Club
{
protected:
	char* name;
	double WiskeyPrice;
	double VodkaPrice;
	void CopyFrom(const Club& other);
	void Free();
public:
	Club();
	Club(const char* name);
	Club(const Club& other);
	Club& operator=(const Club& other);
	char* GetName();
	virtual bool AddUser(User& user) = 0;
	virtual bool RemoveUser(User& user) = 0;
	virtual Club* clone()=0;
};





