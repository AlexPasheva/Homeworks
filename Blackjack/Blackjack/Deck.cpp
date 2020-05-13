#include "Deck.h"
#include <time.h>
#pragma warning(disable : 4996)
///////////////////////////////////////////////
void Deck::Free()
{
	delete[] cards;
}
void Deck::CopyFrom(const Deck& other) {
	this->size = other.size;
	this->CurrentCard = other.CurrentCard;
	strcpy(this->DeckSerialNumber, other.DeckSerialNumber);
	this->cards = new Card[size];
	for (unsigned int i = 0; i < size; i++) 
	{
		cards[i] = other.cards[i];
	}
}
///////////////////////////////////////////////
Deck::Deck()
{
	size = 52;
	this->CurrentCard = 51;
	strcpy(this->DeckSerialNumber,"Default");
	char hearts[7] = "hearts";
	char spades[7] = "spades";
	char clubs[6] = "clubs";
	char diamonds[9] = "diamonds";
	char* suit[4] = { hearts,spades,clubs,diamonds };
	const char* face[13] = { "2","3","4","5","6","7","8","9","10" ,"Ace","Queen","King","Jack" };
	cards = new Card[52];
	int num = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			cards[i*13+j] = Card(suit[i], face[j],DeckSerialNumber);
		}
	}
}
Deck::Deck(unsigned int size,const char* DeckSerialNumber)
{
	this->size=size;
	strcpy(this->DeckSerialNumber, DeckSerialNumber);
	this->CurrentCard = size-1;
	char hearts[7] = "hearts";
	char spades[7] = "spades";
	char clubs[6] = "clubs";
	char diamonds[9] = "diamonds";
	char* suit[4] = { hearts,spades,clubs,diamonds };
	const char* face[13] = { "2","3","4","5","6","7","8","9","10" ,"Ace","Queen","King","Jack" };
	cards = new Card[size];
	int index = 0;
	int CustomSize = ((size - 1) / 52) + 1;
	if (size<52)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{			
				cards[index] = Card(suit[i], face[j], DeckSerialNumber);
				index++;
				if (index == size) break;
			}
			if (index == size) break;
		}
	}
	if (size==52)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				cards[i * 13 + j] = Card(suit[i], face[j], DeckSerialNumber);
			}
		}
	}
	if (size>52)
	{
		for (int i = 0; i < CustomSize; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 13; k++)
				{
					cards[index] = Card(suit[j], face[k], DeckSerialNumber);
					index++;
					if (index == size) break;
				}
				if (index == size) break;
			}
		   if (index == size) break;
		}
	}
}
Deck::Deck(const Deck& other) 
{
	CopyFrom(other);
}
Deck& Deck::operator=(const Deck& other) 
{
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
Deck:: ~Deck() 
{
	Free();
}

////////////////////////////////////////////////////////////////////////////////
Card& Deck::Draw()
{
	int CardOnTop = CurrentCard;
	Switch(size-CurrentCard-1, CurrentCard);
	CurrentCard--;
	return cards[CardOnTop];
}
void Deck::Switch(unsigned int first,unsigned int second)
{
	if (first > size || second > size) 
	{
		std::cout << "error" << std::endl;
	}
	else
	{
		Card temp;
		temp=cards[first];
		cards[first] = cards[second];
		cards[second] = temp;
	}
}
void Deck::Shuffle(unsigned int size)
{
	for (unsigned int first = 0; first < size; first++)
	{
		int second = (rand() + time(0)) % size;
		Card temp = cards[first];
		cards[first] = cards[second];
		cards[second] = temp;
	}
	CurrentCard = size-1;
}
void Deck::SuitCount(const char* suit)
{
	unsigned int count = 0;
	for (unsigned int i = 0; i < size; i++)
	{
		if (strcmp(cards[i].GetSuit(),suit)==0)
		{
			count++;
		}
	}
	std::cout << count;
}
unsigned int Deck::RankCount(unsigned int value)
{
	unsigned int count = 0;
	for (unsigned int i =0 ; i < CurrentCard+1; i++)
	{
		if (value==11 && (strcmp(cards[i].GetFace(), "Ace") == 0))
		{
			count++;
		}
		else if (value==1 && (strcmp(cards[i].GetFace(), "Ace") == 0))
		{
			count++;
		}
		else if (cards[i].AssighnValue() == value)
		{
			count++;
		}
	}
	 return count++;
}
double Deck::Probability(int value)
{
	double number = this->RankCount(value);
	double LeftCards = this->CurrentCard + 1.0;
	return (number /LeftCards);
	if (value>11)
	{
		return 0;
	}
}
///////////////////////////////////////////////////////////////////////////////
void Deck::PrintDeck(unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cards[i].NameCard();
	}
}
void Deck::SetSize(unsigned int size)
{
	this->size = size;
}
unsigned int Deck::GetSize()
{
	return size;
}
char* Deck::GetSerialNumber()
{
	return DeckSerialNumber;
}
void Deck::SetSerialNumber(const char* SerialNumber)
{
	strcpy(this->DeckSerialNumber, SerialNumber);
}
void Deck::SetCurrentCard(unsigned int size)
{
	this->CurrentCard = size;
}
unsigned int Deck::GetCurrentCard()
{
	return CurrentCard;
}