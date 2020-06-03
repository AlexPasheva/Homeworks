#include "User.h"
void User::Free()
{
	delete[] name;
}
void User::CopyFrom(const User& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

User::User(const char* name, unsigned int age, unsigned int budget, unsigned int wiskey, unsigned int vodka, ListeningTo taste)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
	this->budget = budget;
	this->wiskey = wiskey;
	this->vodka = vodka;
	this->taste = taste;
}
User::User(const User& other)
{
	CopyFrom(other);
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
User::~User()
{
	Free();
}

ListeningTo User::GetTaste()
{
	return taste;
}
unsigned int User::GetAge()
{
	return age;
}
unsigned int User::GetBudget()
{
	return budget;
}
unsigned int User::GetWiskey()
{
	return wiskey;
}
unsigned int User::GetVodka()
{
	return vodka;
}
bool User::operator==(const User& other)
{
	if (strcmp(name, other.name) == 0 && age == other.age && budget == other.budget && wiskey == other.wiskey && vodka == other.vodka && taste == other.taste)
	{
		return true;
	}
	return false;
}