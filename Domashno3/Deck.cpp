#include "Deck.h"

//!!!!!
//no cpp file because of a link error 
//!!!!!!




/*template<typename T>
void Deck<T>::copy(const Deck& newDeck)
{
	this->cards = new T[30];

	for (int i = 0; i < newDeck.cards.length; i++)
	{
		this->addCard(newDeck.cards[i]); //в this->cards добавяме всички елементи на newCards
	}
}

template<typename T>
void Deck<T>::erase()
{
	delete[] cards;
}

template<typename T>
bool Deck<T>::hasDuplicates()
{
	for (int i = 0; i < numberOfCards; i++)
	{
		for (size_t j = 0; j < numberOfCards; j++)
		{
			if (strcmp(cards[i].name, cards[j].name) == 0)
			{
				return true;
			}
			
		}

	}
	return false;
}

template<typename T>
bool Deck<T>::hasCard(char* cardName)
{
	for (int i = 0; i < numberOfCards; i++)
	{
		if (strcmp(cards[i].name, cards[i].name) == 0)
		{
			return true;
		}
	}
	return false;
}

template<typename T>
Deck<T>::Deck()
{
	cards = new T[30];
	numberOfCards = 0;
}

template<typename T>
Deck<T>::Deck(T* newCards)
{
	cards = new T[30];
	numberOfCards = 0;

	for (int i = 0; i < newCards.length; i++)
	{
		this->cards[numberOfCards] = newCards[i];
		numberOfCards++;
	}
}

template<typename T>
void Deck<T>::shuffle()
{
	srand(time(NULL));

	for (int i = 0; i < numberOfCards; i++)
	{
		int randomPos = i + (rand() % (numberOfCards - i));
		cards[i].swap(cards[randomPos]);
	}
}

template<typename T>
T Deck<T>::drawCard()
{
	if (numberOfCards == 0)
	{
		std::cout << "No cards left" << std::endl;
		return EarthCard();
	}
	else
	{
		T card = cards[0];
		T* newCards = new T[30];

		for (int i = 1; i < numberOfCards; i++)
		{
			newCards[i - 1] = cards[i];
			numberOfCards++;
		}

		newCards[numberOfCards] = (card);

		T* temp = cards;

		cards = newCards;

		delete[] temp;

		return card;
	}

}

template<typename T>
void Deck<T>::addCard(T card)
{
	if (this->hasCard(card)) {
		this->cards[numberOfCards] = card;
		numberOfCards++;
	}
	else std::cout << card.name << "is already in deck!" << std::endl;
}

template<typename T>
Deck<T> Deck<T>::operator+(T& card) const
{
	Deck<T> copyDeck = new Deck<T>(this);
	copyDeck.addCard(card);
	return copyDeck;
}

template<typename T>
Deck<T>& Deck<T>::operator+=(const T& card)
{
	this->addCard(card);
	return *this;
}

template<typename T>
int Deck<T>::getType() const
{
	return this->type;
}

template<typename T>
Deck<T>::Deck(const Deck& newDeck)
{
	this->copy(newDeck);
}

template<typename T>
Deck<T>& Deck<T>::operator=(const Deck<T>& newDeck)
{
	if (this != newDeck)
	{
		this->copy(newDeck);
	}
	return *this;
}

template<typename T>
Deck<T>::~Deck()
{
	erase();
}

template class Deck<EarthCard>;
template class Deck<WaterCard>;
template class Deck<FireCard>;
template class Deck<WindCard>;*/