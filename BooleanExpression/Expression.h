#include <iostream>
#include "BooleanNumber.h"
#include "Variable.h"
#include "Operation.h"
int* FromDecimalToBinaryArray(int dec, int length)
{
	int* helper = new int[length];
	int* a = new int[length];
	int i = 0;
	for (i; i < length; i++)
	{
		if (dec<=(pow(2,length)/2))
		{
			helper[i] = 0;
		}
		helper[i] = dec % 2;
		dec /= 2;
	}
	int j=0;
	for (i = i-1; i >= 0; i--)
	{
		a[j]=helper[i];
		j++;
	}
	delete[] helper;
	return a;
}
bool IsTautology(Expression* expr,const char* vars, int NumOfVars)
{
	Interpret i;
	int* array = new int[NumOfVars];
	int CombNumber = NumOfVars * NumOfVars;
	for (int j = 0; j < CombNumber; j++)               // върти външния цикъл толкова колкото е дължината на цялата таблица
	{
		array = FromDecimalToBinaryArray(j, NumOfVars);// това е всеки един ред от таблицата
		for (int k = 0; k < NumOfVars; k++)            //за всяко число от таблицата интерпретира променливата с 0 или 1
		{
			i.SetValue(vars[k], array[k]);
		}
		if (expr->Eval(i)==0)                          //гледа дали е лъжа и ако стане лъжа няма как изразът да е тавтология
		{
			delete[] array;
			return false;
		}
	}
	delete[] array;
	return true;
}
bool IsContradiction(Expression* expr, const char* vars, int NumOfVars)
{
	Interpret i;
	int* array = new int[NumOfVars];
	int CombNumber = NumOfVars * NumOfVars;
	for (int j = 0; j < CombNumber; j++)               // върти външния цикъл толкова колкото е дължината на цялата таблица
	{
		array = FromDecimalToBinaryArray(j, NumOfVars);// това е всеки един ред от таблицата
		for (int k = 0; k < NumOfVars; k++)            //за всяко число от таблицата интерпретира променливата с 0 или 1
		{
			i.SetValue(vars[k], array[k]);
		}
		if (expr->Eval(i)==1)                          //гледа дали е истина и ако е значи няма как да е contradiction
		{
			delete[] array;
			return false;
		}
	}
	delete[] array;
	return true;
}
bool IsContingency(Expression* expr, const char* vars, int NumOfVars)
{
	if (!(IsTautology(expr, vars, NumOfVars))&& !(IsContradiction(expr, vars, NumOfVars)))
	{
		return true;
	}
	return false;
}

int main()
{
	Expression* expr = new Operation(new Variable('p'), '&', new Operation('!', new Variable('p')));

	const char an[2] = { 'p'};
	if (!(IsTautology(expr, an, 1)))
		std::cout << "Not Tautology"<< std::endl;
	else
		std::cout << "Tautology" << std::endl;

	if (!(IsContradiction(expr, an, 1)))
		std::cout << "Not Contradiction" << std::endl;
	else
		std::cout << "Contradiction" << std::endl;

	if (!(IsContingency(expr, an, 1)))
		std::cout << "Not Contingency" << std::endl;
	else
		std::cout << "Contingency" << std::endl;

	expr->Print();
}
