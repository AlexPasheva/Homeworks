#pragma once

#include "Expression.h"
class BooleanNumber : public Expression
{
public:
	BooleanNumber(bool value);

	bool GetValue() const;
	void SetValue(bool value);

	void Print() override;
	bool Eval(const Interpret& i) override;

	Expression* clone() override;

	bool Equals(Expression* other) override;
private:
	bool value;
};

BooleanNumber::BooleanNumber(bool value) : Expression(0)
{
	SetValue(value);
}

bool BooleanNumber::GetValue() const
{
	return value;
}
void BooleanNumber::SetValue(bool value)
{
	this->value = value;
}
void BooleanNumber::Print()
{
	std::cout << value;
}
bool BooleanNumber::Eval(const Interpret& i)
{
	return value;
}
Expression* BooleanNumber::clone()
{
	BooleanNumber* cloned = new BooleanNumber(*this);
	return cloned;
}
bool BooleanNumber::Equals(Expression* other)
{
	if (other->GetType() != 0)
		return false;

	BooleanNumber* otherPtr = (BooleanNumber*)other;
	return value == otherPtr->value;
}
