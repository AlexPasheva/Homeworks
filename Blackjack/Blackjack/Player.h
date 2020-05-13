#pragma once
#pragma warning(disable : 4996)

class Player
{
private:
	char* name;
	unsigned int age;
	unsigned int GamesPlayed;
	unsigned int wins;
	double WinsCoefficient;
	int CurrentPoints;
	void Free();
	void CopyFrom(const Player& other);
public:
	//Player(const char* name="No Name",unsigned int age=18, unsigned int GamesPlayed=0, unsigned int wins = 0, double WinsCoefficient=0);
	Player();
	Player(const char* name, unsigned int age, unsigned int GamesPlayed, unsigned int wins, double WinsCoefficient);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();
	//////////////////// getters, setters
	char* GetName();
	void SetName(const char* name);
	unsigned int GetAge();
	void SetAge(unsigned int age);
	unsigned int GetGamesPlayed();
	void SetGamesPlayed(unsigned int GamesPlayed);
	unsigned int GetWins();
	void SetWins(unsigned int GamesPlayed);
	double GetWinsCoefficient();
	void SetWinsCoefficient(double WinsCoefficient);
	int GetCurrentPoints();
	void SetCurrentPoints(int CurrentPoints);

	void Print();
};