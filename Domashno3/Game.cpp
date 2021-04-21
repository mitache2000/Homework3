#include "Game.h"

void Game::play()
{
	WaterCard card4("cardAaa", 5, 2, 1);
	WaterCard card5("cardBbb", 5, 2, 1);
	WaterCard card6("cardCcc", 5, 2, 1);
	EarthCard card7("cardDdd", 5, 2, 1);
	EarthCard card8("cardEee", 5, 2, 1);
	EarthCard card9("cardFff", 5, 2, 1);

	Deck<EarthCard> earthDeck;
	earthDeck.addCard(card7);
	earthDeck.addCard(card8);
	earthDeck.addCard(card9);
	Deck<WaterCard> waterDeck;
	waterDeck.addCard(card4);
	waterDeck.addCard(card5);
	waterDeck.addCard(card6);

	Player<EarthCard, WaterCard> player1("Ivan", 1, 2);
	player1.assignDeck1(earthDeck);
	player1.assignDeck2(waterDeck);


	FireCard card1("cardGgg", 5, 2, 1);
	FireCard card2("cardHhh", 5, 2, 1);
	FireCard card3("cardIii", 5, 2, 1);

	WindCard card10("cardJjj", 5, 2, 1);
	WindCard card11("cardKkk", 5, 2, 1);
	WindCard card12("cardLll", 5, 2, 1);

	Deck<FireCard> fireDeck;
	fireDeck.addCard(card1);
	fireDeck.addCard(card2);
	fireDeck.addCard(card3);
	Deck<WindCard> windDeck;
	windDeck.addCard(card10);
	windDeck.addCard(card11);
	windDeck.addCard(card12);

	Player<FireCard, WindCard> player2("Pesho", 1, 2);
	player2.assignDeck1(fireDeck);
	player2.assignDeck2(windDeck);
	int player1Points = 0;
	int player2Points = 0;
	/*while (true) {
		int player1Power = player1->drawCard();
		int player2Power = player2->drawCard();
		if (player1Power > player2Power) {
			player1Points++;
			std::cout << "Player one wins, Points: " << player1Points << std::endl;
		}
		else {
			player2Points++;
			std::cout << "Player two wins, Points: " << player2Points << std::endl;
		}

		if (player1Points == 5 || player2Points == 5) {
			if (player1Points == 5)
			{
				std::cout << "Game finished, " << player1->getName() << " wins! Score: " << player1Points << " : " << player2Points << std::endl;
			}
			else
			{
				std::cout << "Game finished, " << player2->getName() << " wins! Score: " << " : " << player2Points << std::endl;
			}
			break;
		}

	}*/


}
