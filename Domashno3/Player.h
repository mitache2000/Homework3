#pragma once
#include <cstring>
#include "Deck.h"
#include <time.h>
#include <fstream>

template <typename T, typename V>
class Player
{
private:
	char* name;
	int wins;
	int losses;
	Deck<T>* deck1;
	Deck<V>* deck2;
	void copy(const Player& newPlayer)
	{
		this->name = new char[strlen(newPlayer.name) + 1];
		strcpy_s(this->name, strlen(newPlayer.name) + 1, newPlayer.name);

		this->wins = newPlayer.wins;
		this->losses = newPlayer.losses;

		this->deck1 = new Deck<T>(newPlayer.deck1); //правим нов дек, като извикваме копи конструктора на дек
		this->deck2 = new Deck<T>(newPlayer.deck2);
	}

	void erase() 
	{
		delete[] this->name;
		delete deck1;
		delete deck2;
	}

public:
	Player(const char* newName, int newWins, int newLosses)
	{
		this->name = (char*)newName;
		this->wins = newWins;
		this->losses = newLosses;
		this->deck1 = new Deck<T>;
		this->deck2 = new Deck<V>;
	}

	Player(const Player& newPlayer)
	{
		this->copy(newPlayer);
	}

	Player& operator=(const Player& newPlayer)
	{
		if (this != &newPlayer)
		{
			this->copy(newPlayer);
			this->erase();
		}
		return *this;
	}

	~Player()
	{
		this->savePlayer(this->name);
		this->erase();
	}

	void assignDeck1(Deck<T>& newDeck) {
		for (int i = 0; i < newDeck.getSize(); i++) {
			this->deck1->addCard(newDeck.drawCard());
		}
	}
	void assignDeck2(Deck<V>& newDeck) {
		for (int i = 0; i < newDeck.getSize(); i++) {
			this->deck2->addCard(newDeck.drawCard());
		}
	}

	int drawCard()
	{
		srand(time(NULL));
		int randomNumber = rand() % 2;

		if (randomNumber == 1)
		{
			return deck1->drawCard().getPower();
		}
		return deck2->drawCard().getPower();
	}

	void savePlayer(char* fileName)
	{
		std::ofstream output(fileName, std::ios::trunc);
		output << this->name << " " << this->wins << " " << this->losses << " " << this->deck1->getType() << " " << this->deck2->getType() << std::endl;
		output.close();
	}

	void loadPlayer(char* fileName)
	{
		std::ifstream input(fileName);
		char name[100];
		int wins;
		int losses;
		int deck1Type;
		int deck2Type;

		input >> name >> wins >> losses >> deck1Type >> deck2Type;

		//return new Player<Cards::deck1Type, Cards::deck2Type>(name, wins, losses);


		//Earth - 0, Fire - 1, Water - 2, Wind - 3
		if (deck1Type == 0)
		{
			if (deck2Type == 1)
			{
				return new Player<EarthCard, FireCard>(name, wins, losses, new Deck<EarthCard>(), new Deck<FireCard>());
			}
			if (deck2Type == 2)
			{
				return new Player<EarthCard, WaterCard>(name, wins, losses, new Deck<EarthCard>(), new Deck<WaterCard>());
			}
			if (deck2Type == 3)
			{
				return new Player<EarthCard, WindCard>(name, wins, losses, new Deck<EarthCard>(), new Deck<WindCard>());
			}
		}
		if (deck1Type == 1)
		{
			if (deck2Type == 0)
			{
				return new Player<FireCard, EarthCard>(name, wins, losses, new Deck<FireCard>(), new Deck<EarthCard>());
			}
			if (deck2Type == 2)
			{
				return new Player<FireCard, WaterCard>(name, wins, losses, new Deck<FireCard>(), new Deck<WaterCard>());
			}
			if (deck2Type == 3)
			{
				return new Player<FireCard, WindCard>(name, wins, losses, new Deck<EarthCard>(), new Deck<WindCard>());
			}
		}
		if (deck1Type == 2)
		{
			if (deck2Type == 0)
			{
				return new Player<WaterCard, EarthCard>(name, wins, losses, new Deck<EarthCard>(), new Deck<EarthCard>());
			}
			if (deck2Type == 1)
			{
				return new Player<WaterCard, FireCard>(name, wins, losses, new Deck<EarthCard>(), new Deck<FireCard>());
			}
			if (deck2Type == 3)
			{
				return new Player<WaterCard, WindCard>(name, wins, losses, new Deck<EarthCard>(), new Deck<WindCard>());
			}
		}
		if (deck1Type == 3)
		{
			if (deck2Type == 0)
			{
				return new Player<WindCard, EarthCard>(name, wins, losses, new Deck<WindCard>(), new Deck<EarthCard>());
			}
			if (deck2Type == 1)
			{
				return new Player<WindCard, FireCard>(name, wins, losses, new Deck<WindCard>(), new Deck<FireCard>());
			}
			if (deck2Type == 2)
			{
				return new Player<WindCard, WaterCard>(name, wins, losses, new Deck<WindCard>(), new Deck<WaterCard>());
			}
		}

	}
};


