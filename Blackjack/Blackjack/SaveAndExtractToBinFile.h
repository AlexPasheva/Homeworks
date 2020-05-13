#pragma once
#include "Player.h"
#include <fstream>
void SavePlayersToBinFile(Player* array, int len, const char* fileName) 
{
	ofstream oFile(fileName, ios::binary | ios::out);

	oFile.write((const char*)&len, sizeof(int));

	for (int i = 0; i < len; i++) 
	{
		int nameLen = strlen(array[i].GetName()) + 1;
		oFile.write((const char*)&nameLen, sizeof(unsigned int));

		oFile.write(array[i].GetName(), nameLen * sizeof(char));

		unsigned int age = array[i].GetAge();
		oFile.write((const char*)&age, sizeof(unsigned int));

		unsigned int GamesPlayed = array[i].GetGamesPlayed();
		oFile.write((const char*)&GamesPlayed, sizeof(unsigned int));

		unsigned int wins = array[i].GetWins();
		oFile.write((const char*)&wins, sizeof(unsigned int));

		double WinsCoefficient = array[i].GetWinsCoefficient();
		oFile.write((const char*)&WinsCoefficient, sizeof(double));
	}
}
Player* ReadFromBinFile(const char* fileName, int PlayerLen) 
{
	ifstream iFile(fileName, ios::binary | ios::in);

	int number;
	iFile.read((char*)&number, sizeof(int));
	PlayerLen = number;

	Player* array = new Player[number+1];
	int nameLen;
	unsigned int newAge;
	unsigned int newGamesPlayed;
	unsigned int newWins;
	double newWinsCoefficient;
	for (int i = 0; i < number; i++)
	{
		iFile.read((char*)&nameLen, sizeof(int));
		char* newName = new char[nameLen];
		iFile.read(newName, nameLen * sizeof(char));
		array[i].SetName(newName);

		iFile.read((char*)&newAge, sizeof(unsigned int));
		array[i].SetAge(newAge);

		iFile.read((char*)&newGamesPlayed, sizeof(unsigned int));
		array[i].SetGamesPlayed(newGamesPlayed);

		iFile.read((char*)&newWins, sizeof(unsigned int));
		array[i].SetWins(newWins);

		iFile.read((char*)&newWinsCoefficient, sizeof(double));
		array[i].SetWinsCoefficient(newWinsCoefficient);
	}
	return array;
}
bool ExistingPlayer(Player* array, char* name, int PlayerLen)
{
	for (int i = 0; i < PlayerLen; i++)
	{
		if (strcmp(array[i].GetName(),name)==0)
		{
			return true;
		}
	}
	return false;
}
int GetPlayer(Player* array, char* name, int PlayerLen)
{
	for (int i = 0; i < PlayerLen; i++)
	{
		if (strcmp(array[i].GetName(), name) == 0)
		{
			return i;
		}
	}
}
