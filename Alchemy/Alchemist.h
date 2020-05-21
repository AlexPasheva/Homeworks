#pragma once
#include "Book.h"

class Alchemist
{
private:
	Book book;
	int length;
	int* NumberOfElements;
	void Free();
	void CopyFrom(const Alchemist& other);

public:
	Alchemist(int* NumberOfElements, int length);
	Alchemist(const Alchemist& other);
	Alchemist& operator=(const Alchemist& other);
	~Alchemist();
};
void Alchemist::CopyFrom(const Alchemist& other)
{
	this->NumberOfElements = new int[other.length];
	for (int i = 0; i < length; i++)
	{
		this->NumberOfElements[i] = other.NumberOfElements[i];
	}
}
void  Alchemist::Free()
{
	delete[] NumberOfElements;
}

Alchemist::Alchemist(int* NumberOfElements, int length)
{
	this->NumberOfElements = new int[length];
	this->NumberOfElements = NumberOfElements;
	this->length = length;
}
Alchemist::Alchemist(const Alchemist& other)
{
	CopyFrom(other);
}
Alchemist& Alchemist::operator=(const Alchemist& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Alchemist::~Alchemist()
{
	Free();
}
