#pragma once
#include <cstring>
#include <iostream>
class WindCard
{
private:
	char* cardName;
	int power;
	int bonusPower;
	int type;
	void copy(const WindCard& newCard);
	void erase();

public:
	WindCard() {
		
	}
	WindCard(const char* newCardName, int newPower, int newBonusPower, int newType);
	WindCard(const WindCard& newCard);
	WindCard& operator=(const WindCard& newCard);
	~WindCard();
	void swap(WindCard& newCard);
	char* getName() const;
	bool counters(int otherCardType) const;
	int getPower() const;
	int getBonusPower() const;
};

