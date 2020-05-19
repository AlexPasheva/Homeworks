#pragma once
#include <iostream>
class Elements
{
private:
	int* ArrayOfIDs;
	int length;
	int ID;
public:
	Elements(int* ArrayOfIDs = {0}, int length=1, const int ID=0);
	int* GetArrayOfIDs()const;
	int GetLength()const;
	int GetID()const;
};
Elements::Elements(int* ArrayOfIDs = { 0 }, int length = 1, const int ID = 0)
{
	this->ArrayOfIDs = ArrayOfIDs;
	this->length = length;
	this->ID = ID;
}
int* Elements::GetArrayOfIDs()const
{
	return ArrayOfIDs;
}
int Elements::GetLength()const
{
	return length;
}
int Elements::GetID()const
{
	return ID;
}
//////////////////////////////////

int EarthArray[3] = { 2,3,4 };
class Earth :public Elements
{
	Earth();
};
Earth::Earth() :Elements(EarthArray, 3, 4)
{

}
//////////////////////////////////

int FireArray[3] = { 1,2,3 };
class Fire :public Elements
{
	Fire();
};
Fire::Fire() :Elements(FireArray, 3, 2)
{

}
//////////////////////////////////

int WaterArray[2] = { 2,4 };
class Water :public Elements
{
	Water();
};
Water::Water() :Elements(WaterArray, 2, 3)
{

}
//////////////////////////////////

int AirArray[4] = { 1,2,3,4 };
class Air :public Elements
{
	Air();
};
Air::Air() :Elements(AirArray, 4, 4)
{

}
