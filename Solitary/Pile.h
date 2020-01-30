#pragma once

#include "Deck.h"

class Pile : public Deck
{
public:
	Pile();
	~Pile();

	bool RefillDeck(Deck& aDeck);
	string GetLastCardString();
};

