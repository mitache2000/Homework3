#include "Game.h"

//Earth - 0, Fire - 1, Water - 2, Wind - 3
void Game::play()
{
	WaterCard card4("cardAaa", 5, 2, 1);
	WaterCard card5("cardBbb", 5, 2, 1);
	WaterCard card6("cardCcc", 5, 2, 1);
	EarthCard card7("cardDdd", 5, 2, 1);
	EarthCard card8("cardEee", 5, 2, 1);
	EarthCard card9("cardFff", 5, 2, 1);

	Deck<EarthCard> deck2(0);
	deck2.addCard(card7);
	deck2.addCard(card8);
	deck2.addCard(card9);
	Deck<WaterCard> deck3(2);
	deck3.addCard(card4);
	deck3.addCard(card5);
	deck3.addCard(card6);

	Player<EarthCard, WaterCard>* player1 = new Player<EarthCard, WaterCard>("Ivan", 1, 2);
	player1->assignDeck1(deck2);
	player1->assignDeck2(deck3);

	FireCard card1("cardGgg", 5, 2, 1);
	FireCard card2("cardHhh", 5, 2, 1);
	FireCard card3("cardIii", 5, 2, 1);

	WindCard card10("cardJjj", 5, 2, 1);
	WindCard card11("cardKkk", 5, 2, 1);
	WindCard card12("cardLll", 5, 2, 1);

	Deck<FireCard> fireDeck(1);
	fireDeck.addCard(card1);
	fireDeck.addCard(card2);
	Deck<WindCard> windDeck(3);
	windDeck.addCard(card10);
	windDeck.addCard(card11);
	windDeck.addCard(card12);

	Player<FireCard, WindCard>* player2 = new Player<FireCard, WindCard>("Pesho", 1, 2);
	std::cout << (player1 == nullptr) << std::endl;
	player2->assignDeck1(fireDeck);
	player2->assignDeck2(windDeck);
	int player1Points = 0;
	int player2Points = 0;
	//while (true) {
	//	int player1Power = player1->drawCard().getPower();
	//	int player2Power = player2->drawCard().getPower();
	//	if (player1Power > player2Power) {
	//		player1Points++;
	//		std::cout << "Player one wins, Points: " << player1Points << std::endl;
	//	}
	//	else {
	//		player2Points++;
	//		std::cout << "Player two wins, Points: " << player2Points << std::endl;
	//	}

	//	if (player1Points == 5 || player2Points == 5) {
	//		std::cout << "Game finished, score " << player1Points << " : " << player2Points << std::endl;
	//		break;
	//	}

	//}
		delete player1;
		delete player2;

}
