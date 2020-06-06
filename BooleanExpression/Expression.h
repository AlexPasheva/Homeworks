#pragma once
#include "Interpret.h"
#include <iostream>
class Expression
{
	int type; //0 - NUMBER, 1-OP, 2 - VAR
public:
	Expression(int type);
	int GetType();

	virtual void Print() = 0;
	virtual bool Eval(const Interpret& i) = 0;
	virtual Expression* clone() = 0;

	virtual bool Equals(Expression* other) = 0;

	virtual ~Expression() {};
};
Expression::Expression(int type)
{
	this->type = type;
}
int Expression::GetType()
{
	return type;
}
