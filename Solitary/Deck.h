#pragma once

#include "Hand.h"

class Deck : public Hand
{
public:
	Deck();

	virtual ~Deck();

	//create a standard deck of 52 cards
	void Populate();

	//shuffle cards
	void Shuffle();

	//deal one card to a hand
	bool Deal(Hand& aHand);

	Card* GetLastCard() const;
	Card* GetAndRemoveLastCard();

	string CardsLeft();
};

