#pragma once
#include "Card.h"

class Deck
{
private:
	Card* cards;
	unsigned int size;
	unsigned int CurrentCard;
	char DeckSerialNumber[10];
	void Free();
	void CopyFrom(const Deck& other);
public:
	//void Resize();
	Deck();
	Deck(unsigned int size,const char* DeckSerialNumber="Custom");
	Deck(const Deck& other);
	Deck& operator=(const Deck& other);
	~Deck();
/////////////////////////////////////////////////////////
	void Switch(unsigned int first,unsigned int second);
	Card& Draw();
	void SuitCount(const char* suit);
	void Shuffle(unsigned int size);
	unsigned int RankCount(unsigned int value);
	double Probability(int value);
////////////////////////////////////////////////////////
	//Getters, setters, print
	void PrintDeck(unsigned int size);
	void SetSize(unsigned int size);
	unsigned int GetSize();
	char* GetSerialNumber();
	void SetSerialNumber(const char* SerialNumber);
	void SetCurrentCard(unsigned int size);
	unsigned int GetCurrentCard();
};