#include "Elements.h"

class Equation
{
private:
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
	void AddDerivatedElement(Type type);
	void AddBaseElement(Type type);
	bool IsValid();
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
void Equation::AddBaseElement(Type type)
{
	BaseElement* current = new BaseElement(type);
	Add(current);
}
void Equation::AddDerivatedElement(Type type)
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
bool Equation::IsValid()
{
	for (int j = 0; j < count; j++)
	{
		for (int i = 0; i < count; i++)
		{
			if (i == j)
				continue;
			if (array[i]->GetType()==Earth)
			{
				if (!array[j]->ReactsWithEarth() == false)
				{
					return false;
				}
			}
			else if (array[i]->GetType() == Air)
			{
				if (!array[j]->ReactsWithAir() == false)
				{
					return false;
				}
			}
			else if (array[i]->GetType() == Water)
			{
				if (!array[j]->ReactsWithWater() == false)
				{
					return false;
				}
			}
			else if (array[i]->GetType() == Fire)
			{
				if (!array[j]->ReactsWithFire() == false)
				{
					return false;
				}
			}
			else if (array[i]->GetType() == Metal)
			{
				if (!array[j]->ReactsWithMetal() == false)
				{
					return false;
				}
			}
			else if (array[i]->GetType() == Stone)
			{
				if (!array[j]->ReactsWithStone() == false)
				{
					return false;
				}
			}
			else if (array[i]->GetType() == Energy)
			{
				if (!array[j]->ReactsWithEnergy() == false)
				{
					return false;
				}
			}
			else if (array[i]->GetType() == Spirit)
			{
				if (array[j]->ReactsWithSpirit()==false)
				{
					return false;
				}
			}
			else if (array[i]->GetType() == Gold)
			{
				if (array[j]->ReactsWithGold() == false)
				{
					return false;
				}
			}
			else if (array[i]->GetType() == PhilosophersStone)
			{
				if (array[j]->ReactsWithPhilosophersStone() == false)
				{
					return false;
				}
			}
		}
	}
	return true;
}

class Formula
{
private:
	char op;
	Equation lhs;
	Equation rhs;

public:
	Formula(char op = '+', Type type = Air);
	Formula(Equation lhs, Equation rhs);

	char GetOp();

	bool Valid();
};
Formula::Formula(char op, Type type)
{
	if (op == '/' && (type == Earth || type == Fire || type == Water || type == Air))
	{
		rhs.AddBaseElement(type);
		rhs.AddBaseElement(type);
	}
	else if (op == '/' && (type == PhilosophersStone))
	{
		rhs.AddDerivatedElement(type);
		rhs.AddDerivatedElement(type);
	}
	else if (op == '/' && (type == Stone))
	{
		rhs.AddBaseElement(Fire);
		rhs.AddBaseElement(Water);
	}
	else if (op == '/' && (type == Metal))
	{
		rhs.AddBaseElement(Fire);
		rhs.AddBaseElement(Earth);
	}
	else if (op == '/' && (type == Energy))
	{
		rhs.AddBaseElement(Air);
		rhs.AddBaseElement(Water);
	}
	else if (op == '/' && (type == Spirit))
	{
		rhs.AddBaseElement(Air);
		rhs.AddBaseElement(Air);
	}
	else if (op == '/' && (type == Gold))
	{
		rhs.AddDerivatedElement(Metal);
		rhs.AddDerivatedElement(Metal);
	}
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
	return lhs.IsValid();
}
