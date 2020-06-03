#include "Folk.h"
void PopFolkClub::CopyFrom(const PopFolkClub& other)
{
	singer = new char[strlen(other.singer) + 1];
	strcpy(singer, other.singer);
}
void PopFolkClub::Free()
{
	delete[] singer;
}
PopFolkClub::PopFolkClub(const PopFolkClub& other) :Club(other)
{
	CopyFrom(other);
}
PopFolkClub& PopFolkClub::operator=(const PopFolkClub& other)
{
	if (this != &other)
	{
		Club::operator=(other);
		Free();
		CopyFrom(other);
	}
	return *this;
}
PopFolkClub::PopFolkClub(const char* name, double VodkaPrice, double WiskeyPrice, const char* singer) :Club(name)
{
	this->VodkaPrice = VodkaPrice;
	this->WiskeyPrice = WiskeyPrice;
	this->singer = new char[strlen(singer) + 1];
	strcpy(this->singer, singer);
}
bool PopFolkClub::AddUser(User& user)
{
	if (users.Size() >= 70)
	{
		return false;
	}
	if (user.GetTaste() == ListeningTo::Rock)
	{
		return false;
	}
	double MoneyNeeded = user.GetVodka() * VodkaPrice + user.GetWiskey() * WiskeyPrice;
	if (user.GetAge() < 18)
	{
		MoneyNeeded -= 20;
	}
	if (MoneyNeeded > user.GetBudget())
	{
		return false;
	}
	return true;
	users.PushBack(user);
}
bool PopFolkClub::RemoveUser(User& user)
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
Club* PopFolkClub::clone()
{
	return new PopFolkClub(*this);
}
