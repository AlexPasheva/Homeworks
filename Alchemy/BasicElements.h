
#include <iostream>
int EarthArray[3] = { 2,3,4 };
int FireArray[3] = { 1,2,3 };
int WaterArray[2] = { 2,4 };
int HaveTheSameArray[4] = { 1,2,3,4 };
int CanReactWithG[2] = { 1,2 };
bool IsItSubarray(int* element1, int* element2, int n, int m);
class Elements
{
private:
	int ID;
	int length;
	int* ArrayOfIDs;
	int* ArrayCanReactWith;
	int ReactLength;
public:
	Elements(int* ArrayOfIDs = {0}, int* CanReactWith = { 0 }, int length=1, const int ID=0, int ReactLength=0);
	int GetID()const;
	int* GetArrayOfIDs()const;
	int* GetCanReactWith()const;
	int GetLength()const;
	int GetReactLength()const;
	virtual bool React(Elements& element);
};
Elements::Elements(int* ArrayOfIDs, int* CanReactWith, int length, const int ID , int ReactLength)
{
	this->ArrayOfIDs = ArrayOfIDs;
	this->length = length;
	this->ID = ID;
}
int* Elements::GetArrayOfIDs()const
{
	return ArrayOfIDs;
}
int* Elements::GetCanReactWith()const
{
	return ArrayCanReactWith;
}
int Elements::GetID()const
{
	return ID;
}
int Elements::GetLength()const
{
	return length;
}
int Elements::GetReactLength()const
{
	return ReactLength;
}
bool Elements::React(Elements& element)
{
	int n = this->GetReactLength();
	int m = element.GetReactLength();
	int* Arrayelement = new int[n];
	Arrayelement = element.GetCanReactWith();
	int* Array = new int[this->GetReactLength()];
	Array = this->GetCanReactWith();
	for (int i = 0; i < this->GetLength(); i++)
	{
		if (element.GetID() == this->GetCanReactWith()[i])
		{
			return true;
		}
	}
	if (m <= n)
	{
		return IsItSubarray(Array, Arrayelement, n, m);
	}
	else
	{
		return false;
	}
	delete[] Arrayelement;
	delete[] Array;
}
//////////////////////////////////

class Earth :public Elements
{
public:
	Earth();
};
Earth::Earth() :Elements(EarthArray, EarthArray, 3, 4)
{
}

//////////////////////////////////

class Fire :public Elements
{
public:
	Fire();
};
Fire::Fire() :Elements(FireArray, FireArray, 3, 2)
{
}

//////////////////////////////////

class Water :public Elements
{
public:
	Water();
};
Water::Water() :Elements(WaterArray, WaterArray, 2, 3)
{
}

//////////////////////////////////

class Air :public Elements
{
public:
	Air();
};
Air::Air() :Elements(HaveTheSameArray, HaveTheSameArray, 4, 4)
{
}

bool IsItSubarray(int* element1, int* element2, int n, int m)
{
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (element1[i] == element2[j])
		{
			i++;
			j++;
			if (j == m)
				return true;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	return false;
}
