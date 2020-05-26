
#include <iostream>
enum BaseType { Earth, Fire, Water, Air  };
enum DerivedType { PhilosophersStone, Metal, Stone, Energy, Spirit, Gold };

class Elements
{
public:
	virtual bool ReactsWithEarth() = 0;
	virtual bool ReactsWithFire() = 0;
	virtual bool ReactsWithWater() = 0;
	virtual bool ReactsWithAir() = 0;

	virtual bool ReactsWithPhilosophersStone() = 0;
	virtual bool ReactsWithMetal() = 0;
	virtual bool ReactsWithStone() = 0;
	virtual bool ReactsWithEnergy() = 0;
	virtual bool ReactsWithSpirit() = 0;
	virtual bool ReactsWithGold() = 0;
};
class BaseElement :public Elements
{
private:
	BaseType type;
public:
	BaseType GetType();
	bool ReactsWithEarth();
	bool ReactsWithFire();
	bool ReactsWithWater();
	bool ReactsWithAir();

	bool ReactsWithPhilosophersStone();
	bool ReactsWithMetal();
	bool ReactsWithStone();
	bool ReactsWithEnergy();
	bool ReactsWithSpirit();
	bool ReactsWithGold();
};
BaseType BaseElement::GetType()
{
	return type;
}
bool BaseElement::ReactsWithEarth()
{
	if (this->type == Earth)
	{
		return false;
	}
	else if (this->type == Fire)
	{
		return true;
	}
	else if (this->type == Water)
	{
		return false;
	}
	else if (this->type == Air)
	{
		return true;
	}
}
bool BaseElement::ReactsWithFire()
{
	if (this->type == Earth)
	{
		return true;
	}
	else if (this->type == Fire)
	{
		return true;
	}
	else if (this->type == Water)
	{
		return true;
	}
	else if (this->type == Air)
	{
		return true;
	}
}
bool BaseElement::ReactsWithWater()
{
	if (this->type == Earth)
	{
		return true;
	}
	else if (this->type == Fire)
	{
		return true;
	}
	else if (this->type == Water)
	{
		return false;
	}
	else if (this->type == Air)
	{
		return true;
	}
}
bool BaseElement::ReactsWithAir()
{
	if (this->type == Earth)
	{
		return true;
	}
	else if (this->type == Fire)
	{
		return false;
	}
	else if (this->type == Water)
	{
		return true;
	}
	else if (this->type == Air)
	{
		return true;
	}
}
bool BaseElement::ReactsWithPhilosophersStone()
{
	return true;
}
bool BaseElement::ReactsWithMetal()
{
	return true;
}
bool BaseElement::ReactsWithStone()
{
	return true;
}
bool BaseElement::ReactsWithEnergy()
{
	return true;
}
bool BaseElement::ReactsWithSpirit()
{
	return true;
}
bool BaseElement::ReactsWithGold()
{
	return true;
}

class DerivedElement :public Elements
{
private:
	DerivedType type;
	bool DerivesFrom[4];
public:
	DerivedElement(DerivedType type);
	DerivedType GetType();
	bool ReactsWithEarth();
	bool ReactsWithFire();
	bool ReactsWithWater();
	bool ReactsWithAir();

	bool ReactsWithPhilosophersStone();
	bool ReactsWithMetal();
	bool ReactsWithStone();
	bool ReactsWithEnergy();
	bool ReactsWithSpirit();
	bool ReactsWithGold();
};
DerivedElement::DerivedElement(DerivedType type)
{
	this->type = type;
	if (type==Metal)
	{
		this->DerivesFrom[0] = { 1 };
		this->DerivesFrom[1] = { 1 };
		this->DerivesFrom[2] = { 0 };
		this->DerivesFrom[3] = { 0 };
	}
	else if (type == Stone)
	{
		this->DerivesFrom[0] = { 0 };
		this->DerivesFrom[1] = { 1 };
		this->DerivesFrom[2] = { 1 };
		this->DerivesFrom[3] = { 0 };
	}
	else if (type == Energy)
	{
		this->DerivesFrom[0] = { 0 };
		this->DerivesFrom[1] = { 0 };
		this->DerivesFrom[2] = { 1 };
		this->DerivesFrom[3] = { 1 };
	}
	else if (type == Spirit)
	{
		this->DerivesFrom[0] = { 0 };
		this->DerivesFrom[1] = { 0 };
		this->DerivesFrom[2] = { 0 };
		this->DerivesFrom[3] = { 1 };
	}
	else if (type == PhilosophersStone)
	{
		this->DerivesFrom[0] = { 1 };
		this->DerivesFrom[1] = { 1 };
		this->DerivesFrom[2] = { 1 };
		this->DerivesFrom[3] = { 1 };
	}
}
DerivedType DerivedElement::GetType()
{
	return type;
}
bool DerivedElement::ReactsWithEarth()
{
	if (DerivesFrom[0] == 1)
		return true;
	return false;
}
bool DerivedElement::ReactsWithFire()
{
	if (DerivesFrom[1] == 1)
		return true;
	return false;
}
bool DerivedElement::ReactsWithWater()
{
	if (DerivesFrom[2] == 1)
		return true;
	return false;
}
bool DerivedElement::ReactsWithAir()
{
	if (DerivesFrom[3] == 1)
		return true;
	return false;
}

bool DerivedElement::ReactsWithPhilosophersStone()
{
	return (this->ReactsWithAir() && this->ReactsWithEarth() && this->ReactsWithFire() && this->ReactsWithWater());
}
bool DerivedElement::ReactsWithMetal()
{
	return (this->ReactsWithAir() && this->ReactsWithEarth() && this->ReactsWithFire() && this->ReactsWithWater());
}
bool DerivedElement::ReactsWithStone()
{
	return (this->ReactsWithAir() && this->ReactsWithEarth() && this->ReactsWithFire() && this->ReactsWithWater());
}
bool DerivedElement::ReactsWithEnergy()
{
	return (this->ReactsWithAir() && this->ReactsWithEarth() && this->ReactsWithFire() && this->ReactsWithWater());
}
bool DerivedElement::ReactsWithSpirit()
{
	return (this->ReactsWithAir() && this->ReactsWithEarth() && this->ReactsWithFire() && this->ReactsWithWater());
}
bool DerivedElement::ReactsWithGold()
{
	return (this->ReactsWithEarth() && this->ReactsWithFire());
}

