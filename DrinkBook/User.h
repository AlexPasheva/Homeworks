#pragma once
#include <cstring>
enum class ListeningTo 
{
	Rock, PopFolk, House, ListeningToEverithing
};
class User
{
private:
	char* name;
	unsigned int age;
	unsigned int budget;
	unsigned int wiskey;
	unsigned int vodka;
	ListeningTo taste;
	void Free();
	void CopyFrom(const User& other);
public:
	User(const char* name = "NoName", unsigned int age = 18, unsigned int budget = 0, unsigned int wiskey = 0, unsigned int vodka = 0, ListeningTo taste = ListeningTo::PopFolk);
	User(const User& other);
	User& operator=(const User& other);
	~User();

	ListeningTo GetTaste();
	unsigned int GetAge();
	unsigned int GetBudget();
	unsigned int GetWiskey();
	unsigned int GetVodka();
	bool operator==(const User& other);
};
