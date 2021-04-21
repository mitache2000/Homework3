#include "WaterCard.h"

void WaterCard::copy(const WaterCard& newCard)
{
	this->cardName = new char[strlen(newCard.cardName) + 1];
	strcpy_s(this->cardName, strlen(newCard.cardName) + 1, newCard.cardName);
	
	this->power = newCard.power;
	this->bonusPower = newCard.bonusPower;
	this->type = newCard.type;

}

void WaterCard::erase()
{
	std::cout << "deleting water " << this->cardName;
	delete[] this->cardName;
}

WaterCard::WaterCard(const char* newCardName, int newPower, int newBonusPower, int newType)
{
	this->cardName = new char[strlen(newCardName) + 1];
	strcpy_s(this->cardName, strlen(newCardName) + 1, newCardName);
	this->power = newPower;
	this->bonusPower = newBonusPower;
	this->type = newType;
}

WaterCard::WaterCard(const WaterCard& newCard)
{
	copy(newCard);
}

WaterCard& WaterCard::operator=(const WaterCard& newCard)
{
	if (this != &newCard)
	{
		this->erase();
		this->copy(newCard);
	}
	return *this;
}

WaterCard::~WaterCard()
{
	this->erase();
}

void WaterCard::swap(WaterCard& newCard)
{
	std::swap(this->cardName, newCard.cardName);
	std::swap(this->power, newCard.power);
	std::swap(this->bonusPower, newCard.bonusPower);
	std::swap(this->type, newCard.type);
}

char* WaterCard::getName() const
{
	return this->cardName;
}

bool WaterCard::counters(int otherCardType) const
{
	return otherCardType == 1; //counters fire
}
int WaterCard::getPower() const{
	return this->power;
}

int WaterCard::getBonusPower() const
{
	return this->bonusPower;
}
