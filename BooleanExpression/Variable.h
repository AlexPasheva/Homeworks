#include "Expression.h"
class Variable : public Expression
{
public:
	char var;
	Variable(char var);
	void Print() override;
	bool Eval(const Interpret& i) override;
	Expression* clone() override;
	bool Equals(Expression* other) override;
};

Variable::Variable(char var) :Expression(2), var(var)
{
}

void Variable::Print()
{
	std::cout << var;
}
bool Variable::Eval(const Interpret& i)
{
	return i.GetValue(var);
}
Expression* Variable::clone()
{
	return new Variable(*this);
}
bool Variable::Equals(Expression* other)
{
	if (other->GetType() != 2)
		return false;
	Variable* converted = (Variable*)other;
	return var == converted->var;
}
