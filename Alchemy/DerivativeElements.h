
#include "BasicElements.h"
class PhilosophersStone :public Elements
{
public:
	PhilosophersStone();
};
PhilosophersStone::PhilosophersStone() :Elements(HaveTheSameArray, HaveTheSameArray, 4, 10)
{
}
//////////////////////////////////


class Metal :public Elements
{
public:
	Metal();
};
Metal::Metal() :Elements(HaveTheSameArray, HaveTheSameArray, 4, 5)
{
}

//////////////////////////////////

class Stone :public Elements
{
public:
	Stone();
};
Stone::Stone() :Elements(HaveTheSameArray, HaveTheSameArray, 4, 6)
{
}
//////////////////////////////////


class Energy :public Elements
{
public:
	Energy();
};
Energy::Energy() :Elements(HaveTheSameArray, HaveTheSameArray, 4, 7)
{
}

//////////////////////////////////

class Spirit :public Elements
{
public:
	Spirit();
};
Spirit::Spirit() : Elements(HaveTheSameArray, HaveTheSameArray, 4, 8)
{
}
//////////////////////////////////


class Gold :public Elements
{
public:
	Gold();
};
Gold::Gold() :Elements(HaveTheSameArray, CanReactWithG, 4, 9)
{
}
