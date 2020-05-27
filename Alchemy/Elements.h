#include <iostream>
enum Type { Earth, Fire, Water, Air, PhilosophersStone, Metal, Stone, Energy, Spirit, Gold};

class Elements
{
public:
	virtual bool ReactsWithEarth() = 0;
	virtual bool ReactsWithFire() = 0;
	virtual bool ReactsWithWater() = 0;
	virtual bool ReactsWithAir() = 0;

	virtual Type GetType()=0;
	virtual bool ReactsWithPhilosophersStone() = 0;
	virtual bool ReactsWithMetal() = 0;
	virtual bool ReactsWithStone() = 0;
	virtual bool ReactsWithEnergy() = 0;
	virtual bool ReactsWithSpirit() = 0;
	virtual bool ReactsWithGold() = 0;

	virtual Elements* clone() = 0;
};

class BaseElement :public Elements
{
private:
	Type type;
public:
	BaseElement(Type type);
	Type GetType();
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

	Elements* clone();
};
BaseElement::BaseElement(Type type)
{
	if (type == Earth, type == Fire, type == Water, type == Air)
	{
		this->type = type;
	}
}
Type BaseElement::GetType()
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

Elements* BaseElement::clone()
{
	BaseElement* NewEl = new BaseElement(*this);
	return NewEl;
}

class DerivedElement :public Elements
{
private:
	Type type;
	bool DerivesFrom[4];
public:
	DerivedElement(Type type);
	Type GetType();
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

	Elements* clone();
};
DerivedElement::DerivedElement(Type type)
{
	if (type==Metal || type==Stone || type==Energy || type == Spirit || type==Gold || type == PhilosophersStone)
	{
		this->type = type;
	}
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
Type DerivedElement::GetType()
{
	return type;
}
bool DerivedElement::ReactsWithEarth()
{
	return DerivesFrom[0];
}
bool DerivedElement::ReactsWithFire()
{
	return DerivesFrom[1];
}
bool DerivedElement::ReactsWithWater()
{
	return DerivesFrom[2];
}
bool DerivedElement::ReactsWithAir()
{
	return DerivesFrom[3];
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

Elements* DerivedElement::clone()
{
	DerivedElement* NewEl = new DerivedElement(*this);
	return NewEl;
}

