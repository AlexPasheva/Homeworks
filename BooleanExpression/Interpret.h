#pragma once
const int DEFAULTVALUE = -1;
const int ALPHABETSIZE = 26;
const int AINDEX = 97;

class Interpret
{
	int intpret[26];

public:
	Interpret();
	void SetValue(char ch, bool value);
	bool GetValue(char ch) const;
};

Interpret::Interpret()
{
	for (int i = 0; i < ALPHABETSIZE; i++)
		intpret[i] = DEFAULTVALUE;
}
void Interpret::SetValue(char ch, bool value)
{
	intpret[ch - AINDEX] = value;
}
bool Interpret::GetValue(char ch) const
{
	return intpret[ch - AINDEX];
}
