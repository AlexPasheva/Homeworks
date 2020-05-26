
#include "Elements.h"
#include <cassert>
#include <string>

class Equation
{
protected:
    Elements** array;
    int count;
    int capacity;
    void CopyFrom(const Equation& other);
    void Free();
	void Resize();
public:
    Equation();
    Equation(const Equation&);
    Equation& operator=(const Equation&);
    ~Equation();

	int GetCount();

	Elements* AtIndex(int index);
	void Add(Elements* current);
	void AddDerivatedElement(DerivedType type);
	void AddBaseElement(BaseType type);
};

Equation::Equation()
{
	count = 0;
	capacity = 8;
	array = new Elements * [capacity];
}
void Equation::Free()
{
	for (int i = 0; i < count; i++)
		delete array[i];

	delete[] array;
}
void Equation::Resize()
{
	Elements** temp = new Elements * [capacity * 2];
	capacity *= 2;
	for (int i = 0; i < count; i++)
		temp[i] = array[i];
	delete[] array;
	array = temp;
}
void Equation::CopyFrom(const Equation& other)
{
	array = new Elements* [other.count];
	capacity = other.capacity;
	count = other.count;
	for (int i = 0; i < other.count; i++)
		array[i] = other.array[i]->clone();

}
Equation::Equation(const Equation& other)
{
	CopyFrom(other);
}
Equation& Equation::operator = (const Equation& other)
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

Elements* Equation::AtIndex(int index)
{
	if (count>=index)
		return array[index];
	return 0;
}
void Equation::AddBaseElement(BaseType type)
{
	BaseElement* current = new BaseElement(type);
	Add(current);

}
void Equation::AddDerivatedElement(DerivedType type)
{
	DerivedElement* current = new DerivedElement(type);
	Add(current);
}
void Equation::Add(Elements* current)
{
	if (count == capacity)
		Resize();
	array[count++] = current;
}


class Formula: public Equation
{
private:
	char op;
    Equation lhs;
    Equation rhs;

public:
	Formula(Equation rhs);
	Formula(Equation lhs, Equation rhs);

	char GetOp();

	bool Valid();
};

Formula::Formula(Equation rhs)
{
	op = '/';
	this->rhs = rhs;
}
Formula::Formula(Equation lhs, Equation rhs)
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
	
}
