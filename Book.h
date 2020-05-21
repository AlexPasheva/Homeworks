#pragma once
#include "FormulasAndEquations.h"
class Book
{
private:
	Formula* array;
	int length;
	void CopyFrom(const Book& other);
	void Free();
public:

	Book(Formula* array=0, int length=0);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();


};
void Book::CopyFrom(const Book& other)
{
	this->array = new Formula[other.length];
	for (int i = 0; i < length; i++)
	{
		this->array[i] = other.array[i];
	}
}
void  Book::Free()
{
	delete[] array;
}

Book::Book(Formula* array, int length)
{
	this->array = new Formula[length];
	this->length = length;
}
Book::Book(const Book& other)
{
	CopyFrom(other);
}
Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Book::~Book()
{
	Free();
}

