#include "Rock.h"
Rock::Rock(const char* name, double VodkaPrice, double WiskeyPrice) :Club(name)
{
	this->VodkaPrice = VodkaPrice;
	this->WiskeyPrice = WiskeyPrice;
}
bool Rock::AddUser(User& user)
{
	if (users.Size() >= 30)
	{
		return false;
	}
	if (user.GetTaste() == ListeningTo::House)
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
bool Rock::RemoveUser(User& user)
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
Club* Rock::clone()
{
	return new Rock(*this);
}