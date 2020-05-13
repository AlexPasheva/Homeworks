#include <iostream>
using namespace std;
#include "Deck.h"
#include "SaveAndExtractToBinFile.h"

int UpgradePoints(Card card,Player NewPlayer)
{
	int points = 0;
	if (strcmp(card.GetFace(), "Ace") == 0)//това никак не е оптимално
	{
		if ((21 - (NewPlayer.GetCurrentPoints())) <= 10)
		{
			points=NewPlayer.GetCurrentPoints() + 1;//в случай, че не му достигат под 10 точки до 21 не рискуваме и добавяме 1 точка
		}
		else
		{
			points=NewPlayer.GetCurrentPoints() + 11;//в сличай, че му трябват повече от 10 точки му даваме 11 от асото
		}
	}
	else if (strcmp(card.GetFace(), "Jack") == 0 || strcmp(card.GetFace(), "King") == 0 || strcmp(card.GetFace(), "Queen") == 0)
	{
		points=NewPlayer.GetCurrentPoints() + 10;//стандартно добавяме 10 точки към тези, които вече има
	}
	else if(strcmp(card.GetFace(), "2") == 0)
	{
		points=NewPlayer.GetCurrentPoints()+2;
	}
	else if (strcmp(card.GetFace(), "3") == 0)
	{
		points = NewPlayer.GetCurrentPoints() + 3;
	}
	else if (strcmp(card.GetFace(), "4") == 0)
	{
		points = NewPlayer.GetCurrentPoints() + 4;
	}
	else if (strcmp(card.GetFace(), "5") == 0)
	{
		points = NewPlayer.GetCurrentPoints() + 5;
	}
	else if (strcmp(card.GetFace(), "6") == 0)
	{
		points = NewPlayer.GetCurrentPoints() + 6;
	}
	else if (strcmp(card.GetFace(), "7") == 0)
	{
		points = NewPlayer.GetCurrentPoints() + 7;
	}
	else if (strcmp(card.GetFace(), "8") == 0)
	{
		points = NewPlayer.GetCurrentPoints() + 8;
	}
	else if (strcmp(card.GetFace(), "9") == 0)
	{
		points = NewPlayer.GetCurrentPoints() + 9;
	}
	else if (strcmp(card.GetFace(), "10") == 0)
	{
		points = NewPlayer.GetCurrentPoints() + 10;
	}
	return points;
}



int main()
{
	int n = 3;//може да се въвежда от клавиатурата, но в примера нямаше такъв начален вход
	int age = 0;
	int IndexOfChosenPlayer = 0;
	Player NewPlayer;
	Player Dealer;
	Deck PlayingDeck;
	Player* Players= new Player[4];
	Players=ReadFromBinFile("BinTest.bin", n);//четем от файла играчите и ги запазваме в маси
	cout << "Players available:" << endl;
	for (int i = 0; i < 4; i++)//даваме списък с играчите
	{
		cout<<Players[i].GetName()<<", ";
		cout << Players[i].GetAge() << ", ";
		cout << Players[i].GetWinsCoefficient() << endl;
	}
	cout << "Choose from the players above by writing their name or create your own" << endl;
	char* name = new char[30];
	cin.getline(name, 30);
	if (ExistingPlayer(Players,name,n))// избираме играча от списъка от двоичния файл
	{
		int IndexOfChosenPlayer = GetPlayer(Players,name,n);
		NewPlayer = Players[IndexOfChosenPlayer];
		cout << "You are now playing as " << Players[IndexOfChosenPlayer].GetName() << endl;
	}
	else//даваме на новия играч години
	{
		cout << "You have to enter your player's age: " << endl;
		cin >> age;
		NewPlayer.SetName(name);
		NewPlayer.SetAge(age);
	}
	////////////////////////////////////////////////////////////////////////////////////// дотук сме избрали с кой играч на играем

	cout << "Now you have to choose the size of the deck you are going to play with:" << endl;
	int size;
	cin >> size;
	char SerialNumber[11];
	if (size<52||size>52)//частни случаи
	{
		cout << "You have choosen a custom deck give it serial number or just name it Custom:"<<endl;
		Deck PlayingDeck1(size);
		cin.getline(SerialNumber, 11);
		cin.getline(SerialNumber, 11);

		PlayingDeck.SetSize(size);
		PlayingDeck = PlayingDeck1;
		PlayingDeck.SetSerialNumber(SerialNumber);
		PlayingDeck.SetCurrentCard(size-1);
		PlayingDeck.Shuffle(size);
	}
	else//обикновено тесте
	{
		cout << "You are now playing with the default deck." << endl;
		PlayingDeck.SetSize(52);
		PlayingDeck.SetCurrentCard(51);
	}
	//////////////////////////////////////////////////////////////////////////////////// дотук сме избрали тесте, с което да играем.
	bool won = false;//променлива индикира дали играча е спечелил
	cout << "The game starts, your first card is:";
	Card DrawnCard = PlayingDeck.Draw();
	DrawnCard.NameCard();
	int points = UpgradePoints(DrawnCard, NewPlayer);
	NewPlayer.SetCurrentPoints(points);
	cout <<"Your points: "<< NewPlayer.GetCurrentPoints()<<endl;
	char command[12];
	while (true)
	{
		cout << "Hit/Stand/Probability" << endl;
		cin.getline(command, 12);
		if (strcmp(command,"Hit")==0)
		{
			DrawnCard = PlayingDeck.Draw();
			DrawnCard.NameCard();
			points =UpgradePoints(DrawnCard, NewPlayer);
			NewPlayer.SetCurrentPoints(points);
			cout <<"Your points:"<< NewPlayer.GetCurrentPoints()<<endl;
			if (NewPlayer.GetCurrentPoints()>21)
			{
				cout << "You lost." << endl;
				break;
			}
			else if (NewPlayer.GetCurrentPoints() == 21)
			{
				cout << "You won!" << endl;
				won = true;
				break;
			}
		}
		else if(strcmp(command, "Stand")==0)
		{
			cout << "The dealers cards are:" << endl;
			while (Dealer.GetCurrentPoints() < 17)
			{
				Card card;
				card = PlayingDeck.Draw();
				card.NameCard();
				Dealer.SetCurrentPoints(UpgradePoints(card, Dealer));
			}
			cout << "The dealers points: " << Dealer.GetCurrentPoints();
			cout << endl;
			if (Dealer.GetCurrentPoints()>21)
			{
				cout << "You won!" << endl;
				won = true;
				break;
			}
			else if (Dealer.GetCurrentPoints() <= 21&& Dealer.GetCurrentPoints() >= 17)
			{
				if (Dealer.GetCurrentPoints() <= NewPlayer.GetCurrentPoints())
				{
					cout << "You won!" << endl;
					won = true;
					break;
				}
				else 
				{
					cout << "You lost." << endl;
					break;
				}
			}
		}
		else if (strcmp(command, "Probability")==0)
		{
			cout<<PlayingDeck.Probability(21-NewPlayer.GetCurrentPoints())<<endl;
		}
		else
		{
			cout << "I can't understand you enter your command again:" << endl;
		}
	}
	if (!ExistingPlayer(Players, name, n))//записване обратно в двоичния файл
	{
		NewPlayer.SetCurrentPoints(0);
		if (won)
		{
			NewPlayer.SetWins(1);
			NewPlayer.SetWinsCoefficient(1.0);
		}
		int wins = NewPlayer.GetWins();
		int WinsCoefficient = NewPlayer.GetWinsCoefficient();
		cout << "Stopper";
		Players[4] = Player(name,age,1,wins,WinsCoefficient);//ъпдейт на нов играч
		SavePlayersToBinFile(Players, 4, "BinTest.bin");
		cout << "All changes are saved successfully in the file!";
	}
	else
	{
		NewPlayer.SetCurrentPoints(0);
		unsigned int GamesPlayed = NewPlayer.GetGamesPlayed();
		GamesPlayed++;
		NewPlayer.SetGamesPlayed(GamesPlayed);
		unsigned int Wins = NewPlayer.GetWins();
		if (won)
		{
			NewPlayer.SetWins(Wins++);
			NewPlayer.SetWinsCoefficient((double)Wins/(double)GamesPlayed);
		}
		NewPlayer.SetWinsCoefficient((double)Wins / (double)GamesPlayed);
		int IndexOfChosenPlayer = GetPlayer(Players, name, n);
		Players[IndexOfChosenPlayer] = NewPlayer;//ъпдейт на стар играч
		SavePlayersToBinFile(Players, n, "BinTest.bin");
		cout << "All changes are saved successfully in the file!";
	}
	delete[] name;
}
//Серийния номер за всяка каерта в тестето ми не е различен, и също така при започване на играта се принтира два пъти Hit/Stand/Probability, което не можах да оправя.
//За картите те винаги се повтарят най-много ((к-1)/52)+1 пъти и дори да имат различен сериен номер това не оказва влияние на играта.
