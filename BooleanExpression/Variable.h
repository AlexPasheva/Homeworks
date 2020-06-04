#include "Term.h"

class Variable : public Term
{
public:
	Variable(char var);

	char var;

	void print() override;
	int eval() override;
	Term* clone() override;
	bool Equals(Term* other) override;
};

Variable::Variable(char var) :Term(2), var(var)
{}

void Variable::print()
{
	std::cout << var;
}
int Variable::eval()
{
	return 0; //temp
}
Term* Variable::clone()
{
	return new Variable(*this);
}
bool Variable::Equals(Term* other)
{
	if (other->getType() != 2)
		return false;
	Variable* converted = (Variable*)other;
	return var == converted->var;
}
