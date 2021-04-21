#include "FireCard.h"

void FireCard::copy(const FireCard& newCard)
{
	this->cardName = new char[strlen(newCard.cardName) + 1];
	strcpy_s(this->cardName, strlen(newCard.cardName) + 1, newCard.cardName);

	this->power = newCard.power;
	this->bonusPower = newCard.bonusPower;
	this->type = newCard.type;

}

void FireCard::erase()
{
	//delete[] this->cardName;
}

FireCard::FireCard(const char* newCardName, int newPower, int newBonusPower, int newType)
{
	this->cardName = new char[strlen(newCardName) + 1];
	strcpy_s(this->cardName, strlen(newCardName) + 1, newCardName);
	this->power = newPower;
	this->bonusPower = newBonusPower;
	this->type = newType;
}

FireCard::FireCard(const FireCard& newCard)
{
	copy(newCard);
}

FireCard& FireCard::operator=(const FireCard& newCard)
{
	if (this != &newCard)
	{
		this->erase();
		this->copy(newCard);
	}
	return *this;
}

FireCard::~FireCard()
{
	this->erase();
}

void FireCard::swap(FireCard& newCard)
{
	std::swap(this->cardName, newCard.cardName);
	std::swap(this->power, newCard.power);
	std::swap(this->bonusPower, newCard.bonusPower);
	std::swap(this->type, newCard.type);
}

char* FireCard::getName() const
{
	return this->cardName;
}
bool FireCard::counters(int otherCardType) const
{
	return otherCardType == 3; //counters wind
}
int FireCard::getPower() const {
	return this->power;
}

int FireCard::getBonusPower() const
{
	return this->bonusPower;
}
