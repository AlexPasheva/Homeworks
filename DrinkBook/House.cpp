#include "House.h"
void House::CopyFrom(const House& other)
{
	dj = new char[strlen(other.dj) + 1];
	strcpy(dj, other.dj);
}
void House::Free()
{
	delete[] dj;
}
House::House(const House& other) :Club(other)
{
	CopyFrom(other);
}
House& House::operator=(const House& other)
{
	if (this != &other)
	{
		Club::operator=(other);
		Free();
		CopyFrom(other);
	}
	return *this;
}
House::House(const char* name, double WiskeyPrice, double VodkaPrice, const  char* dj) :Club(name)
{
	this->VodkaPrice = VodkaPrice;
	this->WiskeyPrice = WiskeyPrice;
	this->dj = new char[strlen(dj) + 1];
	strcpy(this->dj, dj);
}
bool House::AddUser(User& user)
{
	if (user.GetTaste() == ListeningTo::PopFolk)
	{
		return false;
	}
	double MoneyNeeded = user.GetVodka() * VodkaPrice + user.GetWiskey() * WiskeyPrice;
	if (user.GetAge() < 18)
	{
		return false;
	}
	if (MoneyNeeded > user.GetBudget())
	{
		return false;
	}
	return true;
	users.PushBack(user);
}
bool House::RemoveUser(User& user)
{
	for (int i = 0; i < users.Size(); i++)
	{
		if (users[i] == user)
		{
			users.RemoveElement(user);
			return true;
		}
	}
	return false;
}
Club* House::clone()
{
	return new House(*this);
}
