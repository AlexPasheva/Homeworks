#pragma warning(disable : 4996)
#include "Card.h"
#include <cstring>

bool Card::CardIsValid()
{
	if (strcmp(this->GetFace(), "1") == 0 || strcmp(this->GetFace(), "2") == 0 || strcmp(this->GetFace(), "3") == 0 ||
		strcmp(this->GetFace(), "4") == 0 || strcmp(this->GetFace(), "5") == 0 || strcmp(this->GetFace(), "6") == 0 ||
		strcmp(this->GetFace(), "7") == 0 || strcmp(this->GetFace(), "8") == 0 || strcmp(this->GetFace(), "9") == 0 ||
		strcmp(this->GetFace(), "10") == 0 || strcmp(this->GetFace(), "Ace") == 0 || strcmp(this->GetFace(), "Jack") == 0 ||
		strcmp(this->GetFace(), "King") == 0 || strcmp(this->GetFace(), "Queen") == 0)
	{
		return true;
	}
	else
	{
		false;
	}
}

Card::Card(const char* suit, const char* face, const char* SerialNumber)
{
	if (strcmp(suit,"spades")==0 || strcmp(suit, "hearts")==0 || strcmp(suit, "clubs")==0 || strcmp(suit, "diamonds")==0)
	{
		strcpy(this->suit, suit);
	}
	else
	{
		strcpy(this->suit, "0");
	}
	if (this->CardIsValid())
	{
		strcpy(this->face, face);
	}
	else
	{
		strcpy(this->face, face);
	}

	strcpy_s(this->SerialNumber, SerialNumber);
}

//Setters
void Card::SetSuit(const char* suit)
{
	strcpy(this->suit,suit);
}
void Card::SetFace(const char* face)
{
	strcpy(this->face, face);
}
void Card::SetSerialNumber(const char* SerialNumber)
{
	strcpy_s(this->SerialNumber, SerialNumber);
}

//Getters
char* Card::GetSuit()
{
	return suit;
}
char* Card::GetFace()
{
	return face;
}
char* Card::GetSerialNumber()
{
	return SerialNumber;
}

//Methods

int Card::AssighnValue()
{
	if (strcmp(this->GetFace(), "Jack") == 0 || strcmp(this->GetFace(), "King") == 0 || strcmp(this->GetFace(), "Queen") == 0)
	{
		return 10;
	}
	else if (strcmp(this->GetFace(), "2") == 0)
	{
	return 2;
	}
	else if (strcmp(this->GetFace(), "3") == 0)
	{
	return 3;
	}
	else if (strcmp(this->GetFace(), "4") == 0)
	{
	return 4;
	}
	else if (strcmp(this->GetFace(), "5") == 0)
	{
	return 5;
	}
	else if (strcmp(this->GetFace(), "6") == 0)
	{
	return 6;
	}
	else if (strcmp(this->GetFace(), "7") == 0)
	{
	return 7;
	}
	else if (strcmp(this->GetFace(), "8") == 0)
	{
	return 8;
	}
	else if (strcmp(this->GetFace(), "9") == 0)
	{
	return 9;
	}
	else if (strcmp(this->GetFace(), "10") == 0)
	{
	    return 10;
	}
}
void Card::NameCard()
{
	
	std::cout<< this->GetFace()<<" of "<<this->GetSuit()<< std::endl;
}
 