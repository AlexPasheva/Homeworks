#pragma once
#include <iostream>
class Term
{
	int type; //0 - NUMBER, 1-OP, 2 - VAR
public:
	Term(int type);
	int getType();

	virtual void print() = 0;
	virtual int eval() = 0;
	virtual Term* clone() = 0;

	virtual bool Equals(Term* other) = 0;

	virtual ~Term() {};
};
Term::Term(int type)
{
	this->type = type;
}
int Term::getType()
{
	return type;
}