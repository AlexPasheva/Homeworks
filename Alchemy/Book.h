#include "FormulasAndEquations.h"
class Book
{
private:
	Formula* array;
	int current;
	int length;
	void CopyFrom(const Book& other);
	void Free();
	void Resize();
public:
	Book(Formula* array=0, int length=0);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	void Add(Formula& current);
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
void Book::Resize()
{
	Formula* temp =new Formula[length * 2];
	delete[] array;
	array = temp;
}

Book::Book(Formula* array, int length)
{
	int j = 0;
	this->array = new Formula[length];
	for (int i = 0; i < length; i++)
	{
		if (array[i].Valid())
		{
			this->array[j] = array[i];
			j++;
		}
	}
	this->length = j;
	this->current = j;
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

void Book::Add(Formula& current)
{
	if (this->current == length)
		Resize();
	array[this->current++] = current;
}

