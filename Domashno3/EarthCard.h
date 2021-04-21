#ifndef EARTH_CARD_H
#define EARTH_CARD_H


#include <cstring>
#include <iostream>
class EarthCard
{
private:
	char* cardName;
	int power;
	int bonusPower;
	int type;
	void copy(const EarthCard& newCard);
	void erase();

public:
	EarthCard() {
		
	}
	EarthCard(const char* newCardName, int newPower, int newBonusPower, int newType);
	EarthCard(const EarthCard& newCard);
	EarthCard& operator=(const EarthCard& newCard);
	~EarthCard();
	void swap(EarthCard& newCard);
	char* getName() const;
	bool counters(int otherCardType) const;
	int getPower() const;
	int getBonusPower() const;
};

#endif // !EARTH_CARD_H