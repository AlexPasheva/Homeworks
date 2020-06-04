#pragma once
#include "Term.h"
class Operation : public Term
{
private:
	void setOperator(char op);
	char op;
	Term* left;
	Term* right;
public:
	Operation(Term* right, char op, Term* left);
	Operation(char op, Term* left);

	void print() override;
	int eval() override;

	Term* clone() override;
	bool Equals(Term* other) override;
	~Operation();
};
Operation::Operation(Term* right, char op, Term* left) : Term(1)
{
	this->left = left;
	this->right = right;
	setOperator(op);
}
Operation::Operation(char op, Term* left) : Term(1)
{
	this->left = left;
	setOperator(op);
}
void Operation::print()
{
	std::cout << "(";
	right->print();
	switch (op)
	{
	case '&': std::cout<<"^" ; break;//and
	case '|': std::cout << "|"; break;//or
	case '>': std::cout<<"=>"; break;//implication
	case '#': std::cout << "<=>"; break;//biconditional//XNOR
	case '^': std::cout << "+"; break;//XOR
	}
	left->print();
	std::cout << ")";
}
int Operation::eval()
{
	bool lhs = left->eval();
	if (op=='!')
	{
		return !lhs;
	}
	bool rhs = right->eval();

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
	if (op != '&' && op != '|' && op != '>' && op != '#' && op != '^')
		throw "Invalid opera=tion";

	this->op = op;
}
Term* Operation::clone()
{
	Operation* cloned = new Operation(*this);
	return cloned;
}
bool Operation::Equals(Term* other)
{
	if (other->getType() != 1)
		return false;
	Operation* otherPTR = (Operation*)other;
	return op == otherPTR->op
		&& left->Equals(otherPTR->left)
		&& right->Equals(otherPTR->right);
}
Operation::~Operation()
{
	delete left;
	delete right;
}