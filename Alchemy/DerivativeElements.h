#pragma once
#include "BasicElements.h"
int PhilosophersStoneArray[4] = { 1,2,3,4 };
class PhilosophersStone :public Elements
{
	PhilosophersStone();
};
PhilosophersStone::PhilosophersStone() :Elements(PhilosophersStoneArray, 4, 10)
{

}
//////////////////////////////////

int MetalArray[4] = { 1,2,3,4 };
class Metal :public Elements
{
	Metal();
};
Metal::Metal() :Elements(MetalArray, 4, 5)
{

}
//////////////////////////////////

int StoneArray[4] = { 1,2,3,4 };
class Stone :public Elements
{
	Stone();
};
Stone::Stone() :Elements(StoneArray, 4, 6)
{

}
//////////////////////////////////

int EnergyArray[4] = { 1,2,3,4 };
class Energy :public Elements
{
	Energy();
};
Energy::Energy() :Elements(EnergyArray, 4, 7)
{

}
//////////////////////////////////

int SpiritArray[4] = { 1,2,3,4 };
class Spirit :public Elements
{
	Spirit();
};
Spirit::Spirit() : Elements(SpiritArray, 4, 8)
{

}
//////////////////////////////////

int GoldArray[4] = { 1,2,3,4, };
class Gold :public Elements
{
	Gold();
};
Gold::Gold() :Elements(GoldArray, 4, 9)
{

}
