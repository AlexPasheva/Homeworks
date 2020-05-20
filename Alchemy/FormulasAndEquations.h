
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
public:
    Equation();
    Equation(const Equation&);
    Equation& operator=(const Equation&);
    ~Equation();

	int GetCapacity();
	Elements* GetArray();

	Elements& AtIndex(int index);
	void Resize(int NewCappacity);
	void AddShape(const char* element);
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
Equation::Equation()
{
	this->capacity = 4;
	array = new Elements[capacity];
	this->count = 0;
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
int Equation::GetCapacity()
{
	return capacity;
}
Elements* Equation::GetArray()
{
	return array;
}
void Equation::Resize(int NewCappacity)
{
	Elements* NewArray = new Elements [NewCappacity];
	for (int i = 0; i < count; i++)
		NewArray[i] = array[i];
	delete[] array;
	array = NewArray;
	capacity = NewCappacity;
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

class Formula: public Equation
{
private:
    Equation* lhs;
	int LHSCapacity;
    Equation rhs[2];
	void CopyFrom(const Formula& other);
	void Free();
public:
	Formula();
	Formula(const Formula&);
	Formula& operator=(const Formula&);
	~Formula();

	bool ValidLHS();
	bool ValidRHS();
};
Formula::Formula(Equation* lhs, int LHSCapacity)
{

}
void Formula::Free()
{
	delete[] lhs;
}
void Formula::CopyFrom(const Formula& other)
{
	this->lhs = new Equation[other.LHSCapacity];
	LHSCapacity = other.LHSCapacity;
	for (int i = 0; i < LHSCapacity; i++)
		lhs[i] = other.lhs[i];
}
Formula::Formula()
{
	this->LHSCapacity = 4;
	lhs = new Equation[LHSCapacity];
}
Formula::Formula(const Formula& other)
{
	CopyFrom(other);
}
Formula& Formula::operator=(const Formula& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}
Formula::~Formula()
{
	Free();
}
bool Formula::ValidLHS()
{
	for (int i = 0; i < LHSCapacity; i++)
	{
		for (int j = 0; j < lhs[i].GetCapacity(); j++)
		{
			if (lhs->GetArray()->React())
			{

			}
		}
	}
	
}
bool Formula::ValidRHS()
{

}
