#ifndef DECK_H
#define DECK_H
#include "WaterCard.h"
#include "FireCard.h"
#include "WindCard.h"
#include "EarthCard.h"
#include<time.h>

template <typename T>
class Deck
{
private:
	int type;
	T* cards;
	int numberOfCards; //max 30
	void copy(const Deck& newDeck) 
	{
		this->cards = new T[30];

		for (int i = 0; i < newDeck.numberOfCards; i++)
		{
			this->addCard(newDeck.cards[i]); //в this->cards добавяме всички елементи на newCards
		}
	}



	bool hasDuplicates()
	{
		for (int i = 0; i < numberOfCards; i++)
		{
			for (size_t j = 0; j < numberOfCards; j++)
			{
				if (strcmp(cards[i].getName(), cards[j].getName()) == 0)
				{
					return true;
				}

			}

		}
		return false;
	}

	bool hasCard(char* cardName)
	{
		for (int i = 0; i < numberOfCards; i++)
		{
			if (strcmp(cards[i].getName(), cards[i].getName()) == 0)
			{
				return true;
			}
		}
		return false;
	}

public:
	Deck()
	{
		cards = new T[30];
		numberOfCards = 0;
	}
	Deck(int cardType) 
	{
		this->type = cardType;
		cards = new T[30];
		numberOfCards = 0;
	}

	Deck(T* newCards, int length) 
	{
		cards = new T[30];
		numberOfCards = 0;

		for (int i = 0; i < length; i++)
		{
			this->cards[numberOfCards] = newCards[i];
			numberOfCards++;
		}
	}

	Deck(const Deck& newDeck)
	{
		this->copy(newDeck);
	}

	Deck& operator=(const Deck& newDeck)
	{
		if (this != &newDeck)
		{
			this->copy(newDeck);
		}
		return *this;
	}

	void erase()
	{
		delete[] cards;
	}

	~Deck() 
	{
		this->erase();
	}

	void shuffle() 
	{
		srand(time(NULL));

		for (int i = 0; i < numberOfCards; i++)
		{
			int randomPos = i + (rand() % (numberOfCards - i));
			cards[i].swap(cards[randomPos]);
		}
	}

	T drawCard() 
	{
		if (numberOfCards == 0)
		{
			std::cout << "No cards left in deck" << std::endl;
		}
		else
		{
			T topCard = cards[0];
			T* newCards = new T[30];

			for (int i = 1; i < numberOfCards; i++)
			{
				newCards[i - 1] = cards[i];
				numberOfCards++;
			}

			newCards[numberOfCards] = topCard;

			T* temp = cards;

			cards = newCards;

			delete[] temp;

			return topCard;
		}

	}

	void addCard(T card) 
	{
		if (!this->hasCard(card.getName())){
			this->cards[numberOfCards] = card;
			numberOfCards++;
		}
		else std::cout << card.getName() << "is already in deck!" << std::endl;
	}

	Deck<T> operator+(T& card) const 
	{
		Deck<T> copyDeck = new Deck<T>(this);
		copyDeck.addCard(card);
		return copyDeck;
	}

	Deck<T>& operator+=(const T& card) 
	{
		this->addCard(card);
		return *this;
	}

	int getType() const 
	{
		return this->type;
	}
	int getSize() const
	{
		return this->numberOfCards;
	}
};


#endif