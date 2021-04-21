#include "EarthCard.h"

void EarthCard::copy(const EarthCard& newCard)
{
	std::cout << "earth card name: " << newCard.cardName << std::endl;
	this->cardName = new char[strlen(newCard.cardName) + 1];
	strcpy_s(this->cardName, strlen(newCard.cardName) + 1, newCard.getName());
	std::cout << "earth new card name: " << this->cardName << std::endl;

	this->power = newCard.power;
	this->bonusPower = newCard.bonusPower;
	this->type = newCard.type;

}

void EarthCard::erase()
{
	//delete[] this->cardName;
}

EarthCard::EarthCard(const char* newCardName, int newPower, int newBonusPower, int newType)
{
	this->cardName = new char[strlen(newCardName) + 1];
	strcpy_s(this->cardName, strlen(newCardName) + 1, newCardName);
	this->power = newPower;
	this->bonusPower = newBonusPower;
	this->type = newType;
}

EarthCard::EarthCard(const EarthCard& newCard)
{
	copy(newCard);
}

EarthCard& EarthCard::operator=(const EarthCard& newCard)
{
	if (this != &newCard)
	{
		this->erase();
		this->copy(newCard);
	}
	return *this;
}

EarthCard::~EarthCard()
{
	this->erase();
}

void EarthCard::swap(EarthCard& newCard)
{
	std::swap(this->cardName, newCard.cardName);
	std::swap(this->power, newCard.power);
	std::swap(this->bonusPower, newCard.bonusPower);
	std::swap(this->type, newCard.type);

}

char* EarthCard::getName() const
{
	return this->cardName;
}

bool EarthCard::counters(int otherCardType) const
{
	return otherCardType == 2; //counters water
}
int EarthCard::getPower() const{
	return this->power;
}

int EarthCard::getBonusPower() const
{
	return this->bonusPower;
}
