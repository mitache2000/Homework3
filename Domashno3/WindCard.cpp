#include "WindCard.h"

void WindCard::copy(const WindCard& newCard)
{
	this->cardName = new char[strlen(newCard.cardName) + 1];
	strcpy_s(this->cardName, strlen(newCard.cardName) + 1, newCard.cardName);

	this->power = newCard.power;
	this->bonusPower = newCard.bonusPower;
	this->type = newCard.type;

}

void WindCard::erase()
{
	//delete[] this->cardName;
}

WindCard::WindCard(const char* newCardName, int newPower, int newBonusPower, int newType)
{
	this->cardName = new char[strlen(newCardName) + 1];
	strcpy_s(this->cardName, strlen(newCardName) + 1, newCardName);
	this->power = newPower;
	this->bonusPower = newBonusPower;
	this->type = newType;
}

WindCard::WindCard(const WindCard& newCard)
{
	copy(newCard);
}

WindCard& WindCard::operator=(const WindCard& newCard)
{
	if (this != &newCard)
	{
		this->erase();
		this->copy(newCard);
	}
	return *this;
}

WindCard::~WindCard()
{
	this->erase();
}

void WindCard::swap(WindCard& newCard)
{
	std::swap(this->cardName, newCard.cardName);
	std::swap(this->power, newCard.power);
	std::swap(this->bonusPower, newCard.bonusPower);
	std::swap(this->type, newCard.type);
}

char* WindCard::getName() const
{
	return this->cardName;
}

bool WindCard::counters(int otherCardType) const
{
	return otherCardType == 0; //counters earth
}
int WindCard::getPower() const {
	return this->power;
}

int WindCard::getBonusPower() const
{
	return this->bonusPower;
}
