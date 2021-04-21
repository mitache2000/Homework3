#include "Player.h"
//!!!!!
//no cpp file because of a link error 
//!!!!!!





/*template<typename T, typename V>
void Player<T, V>::copy(const Player& newPlayer)
{
	this->name = new char[strlen(newPlayer.name) + 1];
	strcpy_s(this->name, strlen(newPlayer.name) + 1, newPlayer.name);

	this->wins = newPlayer.wins;
	this->losses = newPlayer.losses;

	this->deck1 = new Deck<T>(newPlayer.deck1); //правим нов дек, като извикваме копи конструктора на дек
	this->deck2 = new Deck<T>(newPlayer.deck2);
}

template<typename T, typename V>
void Player<T, V>::erase()
{
	delete[] this->name;
	delete this->deck1;
	delete this->deck2;
}

template<typename T, typename V>
Player<T, V>::Player(const char* newName, int newWins, int newLosses, Deck<T> newDeck1, Deck<V> newDeck2)
{
	this->name = newName;
	this->wins = newWins;
	this->losses = newLosses;
	this->deck1 = newDeck1;
	this->deck2 = newDeck2;
}

template<typename T, typename V>
Player<T, V>::Player(const Player& newPlayer)
{
	this->copy(newPlayer);
}

template<typename T, typename V>
Player<T,V>& Player<T, V>::operator=(const Player& newPlayer)
{
	if (this != newPlayer)
	{
		this->copy(newPlayer);
		this->erase();
	}
	return *this;
}

template<typename T, typename V>
Player<T, V>::~Player()
{
	this->erase();
}

template<typename T, typename V>
void Player<T, V>::drawCard()
{
	srand(time(NULL));
	int randomNumber = rand() % 2;

	if (randomNumber == 1)
	{
		deck1.drawCard();
	}
	else deck2.drawCard();
}

template<typename T, typename V>
void Player<T, V>::savePlayer(char* fileName)
{
	std::ofstream output(fileName, std::ios::trunc);
	output << this->name << " " << this->wins << " " << this->losses << " " << this->deck1.type << " " << this->deck2.type <<std::endl;
	output.close();
}

template<typename T, typename V>
void Player<T, V>::loadPlayer(char* fileName)
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
		if (deck2Type == 0)
		{
			//Player<EarthCard, EarthCard>
		}
		if (deck2Type == 1)
		{

		}
		if (deck2Type == 2)
		{

		}
		if (deck2Type == 3)
		{

		}

	}

}*/
