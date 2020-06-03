#include "Club.h"
Club::Club()
{
	name = 0;
	WiskeyPrice = 0;
	VodkaPrice = 0;
}
void Club::CopyFrom(const Club& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
void Club::Free()
{
	delete[] name;
}
Club::Club(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Club::Club(const Club& other)
{
	CopyFrom(other);
}
Club& Club::operator=(const Club& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
char* Club::GetName()
{
	return name;
}
