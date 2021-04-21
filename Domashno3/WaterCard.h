#pragma once
#include <cstring>
#include <iostream>
class WaterCard
{
private:
	char* cardName;
	int power;
	int bonusPower;
	int type;
	void copy(const WaterCard& newCard);
	void erase();

public:
	WaterCard() {
		cardName = new char[100];
		power = 0;
		bonusPower = 0;
		type = 0;
	}
	WaterCard(const char* newCardName, int newPower, int newBonusPower, int newType);
	WaterCard(const WaterCard& newCard);
	WaterCard& operator=(const WaterCard& newCard);
	~WaterCard();
	void swap(WaterCard& newCard);
	char* getName() const;
	bool counters(int otherCardType) const;
	int getPower() const;
	int getBonusPower() const;
};

