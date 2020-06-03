#pragma once
#include "Rock.h"
class Clubs
{
private:
	Club** clubs;

	int capacity;
	int count;

	void Resize(int NewCappacity);
	void CopyFrom(const Clubs& other);
	void Free();

public:
	Clubs();
	Clubs(const Clubs& other);
	Clubs& operator=(const Clubs& other);
	~Clubs();

	bool AddFolkClub(const char* name, double VodkaPrice, double WikseyPrice, const  char* singer);
	bool AddHouseClub(const char* name, double VodkaPrice, double WikseyPrice, const  char* dj);
	bool AddRockClub(const char* name, double VodkaPrice, double WikseyPrice);
	Club& SearchByName(const char* name);
	bool AddToClub(User& user, const char* name);
	bool RemoveUser(User& user, const char* name);
	
};

