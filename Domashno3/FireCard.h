#ifndef FIRE_CARD_H
#define FIRE_CARD_H
#include <cstring>
#include <iostream>
class FireCard
{
private:
	char* cardName;
	int power;
	int bonusPower;
	int type;
	void copy(const FireCard& newCard);
	void erase();

public:
	FireCard() {
		cardName = new char[100];
		power = 0;
		bonusPower = 0;
		type = 0;
	}
	FireCard(const char* newCardName, int newPower, int newBonusPower, int newType);
	FireCard(const FireCard& newCard);
	FireCard& operator=(const FireCard& newCard);
	~FireCard();
	void swap(FireCard& newCard);
	char* getName() const;
	int getPower() const;
	int getBonusPower() const;
	bool counters(int otherCardType) const;
};

#endif
