#pragma once
#include "Expression.h"
class Operation : public Expression
{
public:
	Operation(Expression* left, char op, Expression* right);
	Operation(char op, Expression* left);

	void Print() override;
	bool Eval(const Interpret& i) override;

	Expression* clone() override;
	bool Equals(Expression* other) override;
	~Operation();
private:
	void setOperator(char op);
	char op;
	Expression* left;
	Expression* right;

};
Operation::Operation(Expression* right, char op, Expression* left) : Expression(1)
{
	this->left = left;
	this->right = right;
	setOperator(op);
}
Operation::Operation(char op, Expression* left) : Expression(1)
{
	this->left = left;
	setOperator(op);
}
void Operation::Print()
{
	std::cout << "(";
	right->Print();
	switch (op)
	{
	case '&': std::cout<<"^" ; break;//and
	case '|': std::cout << "|"; break;//or
	case '>': std::cout<<"=>"; break;//implication
	case '#': std::cout << "<=>"; break;//biconditional//XNOR
	case '^': std::cout << "+"; break;//XOR
	}
	left->Print();
	std::cout << ")";
}
bool Operation::Eval(const Interpret& i)
{
	bool lhs = left->Eval(i);
	if (op=='!')
	{
		return !lhs;
	}
	bool rhs = right->Eval(i);

	switch (op)
	{
	case '&': return lhs && rhs; break;//and
	case '|': return lhs || rhs; break;//or
	case '>': return  !lhs || rhs; break;//implication
	case '#': return (lhs && rhs) || (!lhs && !rhs); break;//biconditional//XNOR
	case '^': return lhs ^ rhs; break;//XOR
	}
	return -1;
}
void Operation::setOperator(char op)
{
	if (op != '&' && op != '|' && op != '>' && op != '#' && op != '^'/* && op != '!'*/)
		throw "Invalid opera=tion";

	this->op = op;
}
Expression* Operation::clone()
{
	Operation* cloned = new Operation(*this);
	return cloned;
}
bool Operation::Equals(Expression* other)
{
	if (other->GetType() != 1)
		return false;
	Operation* otherPTR = (Operation*)other;
	return op == otherPTR->op && left->Equals(otherPTR->left) && right->Equals(otherPTR->right);
}
Operation::~Operation()
{
	delete left;
	delete right;
}
