#include "Player.h"
#pragma warning(disable : 4996)
#include <iostream>
#include <cstring>
//For BIG4
void Player::CopyFrom(const Player& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name); 
	this->age = other.age;
	this->GamesPlayed = other.GamesPlayed;
	this->wins = other.wins;
	this->WinsCoefficient = other.WinsCoefficient;
	this->CurrentPoints = other.CurrentPoints;
}
void Player::Free()
{
	delete[] name;
}
//The actual BIG4
Player::Player()
{
	this->name = new char[30];
	this->age = 18;
	this->GamesPlayed = 0;
	this->wins = 0;
	this->WinsCoefficient =0;
	this->CurrentPoints = 0;
}
Player::Player(const char* name, unsigned int age ,unsigned int GamesPlayed=0, unsigned int wins=0, double WinsCoefficient=0)
{
	int len = strlen(name);
	strcpy(this->name, "Invalid Name");
	if (name[0] >= 'A' && name[0] <= 'Z')
	{
		for (int i = 0; i < len; i++)
		{
			if (name[i] == ' ' && name[i + 1] <= 'A' && name[i + 1]>='Z')
			{
				this->name = new char[len + 1];
				strcpy(this->name, name);
			}
		}

	}
	this->name = new char[len + 1];
	strcpy(this->name, name);
	if (age>=18)
	{
		this->age = age;
	}
	else
	{
		this->age = 18;
	}
	this->GamesPlayed = GamesPlayed;
	this->wins = wins;
	this->WinsCoefficient = WinsCoefficient;
	this->CurrentPoints = 0;
}
Player::Player(const Player& other)
{
	CopyFrom(other);
}
Player& Player::operator=(const Player& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Player::~Player()
{
	Free();
}
/////////////////////// Getters, setters
char* Player::GetName()
{
	return name;
}
void Player::SetName(const char* name)
{
	strcpy(this->name, name);
}
unsigned int Player::GetAge()
{
	return age;
}
void Player::SetAge(unsigned int age)
{
	this->age = age;
}
unsigned int Player::GetGamesPlayed()
{
	return GamesPlayed;
}
void Player::SetGamesPlayed(unsigned int GamesPlayed)
{
	this->GamesPlayed = GamesPlayed;
}
unsigned int Player::GetWins()
{
	return wins;
}
void Player::SetWins(unsigned int wins)
{
	this->wins = wins;
}
double Player::GetWinsCoefficient()
{
	return WinsCoefficient;
}
void Player::SetWinsCoefficient(double WinsCoefficient)
{
	this->WinsCoefficient = WinsCoefficient;
}
int Player::GetCurrentPoints()
{
	return CurrentPoints;
}
void Player::SetCurrentPoints(int CurrentPoints)
{
	this->CurrentPoints = CurrentPoints;
}
//Printing Player
void Player::Print()
{
	std::cout << this->GetName()<<" ";
	std::cout << this->age << ", " << this->wins << ", " << this->WinsCoefficient << std::endl; 
}
