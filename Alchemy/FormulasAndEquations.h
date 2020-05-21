
#include "DerivativeElements.h"
#include <cassert>
#include <string>

class Equation
{
protected:
    Elements* array;
    int current;
    int count;
    int capacity;
    void CopyFrom(const Equation& other);
    void Free();
	void Resize(int NewCappacity);
public:
    Equation(Elements* array, int count);
    Equation(const Equation&);
    Equation& operator=(const Equation&);
    ~Equation();

	int GetCount();
	Elements* GetArray();

	Elements& AtIndex(int index);
	void AddShape(const char* element);
	bool ReactWithEachOther();
};

void Equation::Free()
{
    delete[] array;
}
void Equation::CopyFrom(const Equation& other)
{
    array = new Elements[other.capacity];
    capacity = other.capacity;
    count = other.count;
    for (int i = 0; i < count; i++)
        array[i] = other.array[i];
}
void Equation::Resize(int NewCappacity)
{
	Elements* NewArray = new Elements[NewCappacity];
	for (int i = 0; i < count; i++)
		NewArray[i] = array[i];
	delete[] array;
	array = NewArray;
	capacity = NewCappacity;
}

Equation::Equation(Elements* array = { 0 }, int count=1)
{
	this->capacity = 16;
	this->array = new Elements[capacity];
	this->array = array;
	this->count = count;
	this->current = 0;
}
Equation::Equation(const Equation& other)
{
	CopyFrom(other);
}
Equation& Equation::operator=(const Equation& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Equation::~Equation()
{
	Free();
}

int Equation::GetCount()
{
	return count;
}
Elements* Equation::GetArray()
{
	return array;
}

Elements& Equation::AtIndex(int index)
{
	return array[index++];
}
void Equation::AddShape(const char* element)
{
	if (count == this->capacity)
		Resize(capacity * 2);
	Elements newObj;

	if (strcmp(element, "Fire") == 0)
		newObj = Fire();
	else if (strcmp(element, "Air") == 0)
		newObj = Air();
	else if (strcmp(element, "Earth") == 0)
		newObj = Earth();
	else if (strcmp(element, "Water") == 0)
		newObj = Water();
	else if (strcmp(element, "PhilosophersStone") == 0)
		newObj = PhilosophersStone();
	else if (strcmp(element, "Metal") == 0)
		newObj = Metal();
	else if (strcmp(element, "Stone") == 0)
		newObj = Stone();
	else if (strcmp(element, "Energy") == 0)
		newObj = Energy();
	else if (strcmp(element, "Spirit") == 0)
		newObj = Spirit();
	else if (strcmp(element, "Gold") == 0)
		newObj = Gold();
	array[this->count++] = newObj;
}
bool Equation::ReactWithEachOther()
{
	for (int j = 0; j < count; j++)
	{
		for (int i = 0; i < count; i++)
		{
			if (i == j)
				continue;
			if (!this->GetArray()[j].React(this->GetArray()[i]))
				return false;
		}
	}
	return true;
}

class Formula: public Equation
{
private:
	char op;
    Equation lhs;
    Elements rhs;

public:
	Formula(Elements rhs);
	Formula(Equation lhs = { 0 }, Elements rhs = 0);

	char GetOp();

	bool Valid();
};

Formula::Formula(Elements rhs)
{
	op = '/';
	lhs = 0;
	this->rhs = rhs;
}
Formula::Formula(Equation lhs, Elements rhs)
{
	op = '+';
	this->lhs = lhs;
	this->rhs = rhs;
}


char Formula::GetOp()
{
	return op;
}

bool Formula::Valid()
{
	return lhs.ReactWithEachOther();
}
