#include "Clubs.h"
void Clubs::Resize(int NewCappacity)
{
	Club** NewArray = new Club * [NewCappacity];

	for (int i = 0; i < count; i++)
		NewArray[i] = clubs[i];
	delete[] clubs;
	clubs = NewArray;
	capacity = NewCappacity;
}
Clubs::Clubs()
{
	capacity = 8;
	count = 0;
	clubs = new Club * [capacity];
}
Clubs::Clubs(const Clubs& other)
{
	CopyFrom(other);
}
Clubs& Clubs::operator=(const Clubs& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

void Clubs::Free()
{
	for (int i = 0; i < count; i++)
		delete clubs[i];

	delete[] clubs;
}
void Clubs::CopyFrom(const Clubs& other)
{
	clubs = new Club * [other.capacity];
	capacity = other.capacity;
	count = other.count;
	for (int i = 0; i < count; i++)
		clubs[i] = other.clubs[i]->clone();
}
Clubs::~Clubs()
{
	Free();
}
bool Clubs::AddFolkClub(const char* name, double VodkaPrice, double WiskeyPrice, const  char* singer)
{
	if (count == capacity)
		Resize(capacity * 2);
	if (WiskeyPrice < 35)
	{
		return false;
	}
	if (VodkaPrice < 20)
	{
		return false;
	}
	PopFolkClub* newObj;
	newObj = new PopFolkClub(name, VodkaPrice, WiskeyPrice, singer);
	clubs[count++] = newObj;
	return true;
}
bool Clubs::AddHouseClub(const char* name, double VodkaPrice, double WiskeyPrice, const  char* dj)
{
	if (count == capacity)
		Resize(capacity * 2);
	if (WiskeyPrice < 40)
	{
		return false;
	}
	if (VodkaPrice < 30)
	{
		return false;
	}
	House* newObj;
	newObj = new House(name, VodkaPrice, WiskeyPrice, dj);
	clubs[count++] = newObj;
	return true;
}
bool Clubs::AddRockClub(const char* name, double VodkaPrice, double WiskeyPrice)
{
	if (count == capacity)
		Resize(capacity * 2);
	if (WiskeyPrice < 30)
	{
		return false;
	}
	if (VodkaPrice < 40)
	{
		return false;
	}
	Rock* newObj;
	newObj = new Rock(name, VodkaPrice, WiskeyPrice);
	clubs[count++] = newObj;
	return true;
}
Club& Clubs::SearchByName(const char* name)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(clubs[i]->GetName(), name) == 0)
		{
			return *clubs[i];
		}
	}
	throw "No club with that name!";
}
bool Clubs::AddToClub(User& user, const char* name)
{
	return this->SearchByName(name).AddUser(user);
}
bool Clubs::RemoveUser(User& user, const char* name)
{
	return this->SearchByName(name).RemoveUser(user);
}
