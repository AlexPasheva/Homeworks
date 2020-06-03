#pragma once
#include "Club.h"

class PopFolkClub :public Club
{
private:
	char* singer;
	Vector<User> users;
	void CopyFrom(const PopFolkClub& other);
	void Free();
public:
	PopFolkClub(const PopFolkClub& other);
	PopFolkClub& operator=(const PopFolkClub& other);
	PopFolkClub(const char* name, double VodkaPrice, double WiskeyPrice, const  char* singer);
	bool AddUser(User& user);
	bool RemoveUser(User& user);
	Club* clone();
};
