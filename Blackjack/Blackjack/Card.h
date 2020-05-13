#pragma once
#include <iostream>

class Card
{
private:
	char suit[10];
	char face[6];
	char SerialNumber[25];
public:
	bool CardIsValid();
	Card(const char* suit="0",const char* face="0",const char* SerialNumber="Default");

	void SetSuit(const char* suit);
	void SetFace(const char* face);
	void SetSerialNumber(const char* SerialNumber);

	char* GetSuit();
	char* GetFace();
	char* GetSerialNumber();

	int AssighnValue();
	void NameCard();
};

