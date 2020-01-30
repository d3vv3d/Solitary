#pragma once

#include <vector>
#include "Card.h"

using std::vector;

class Hand
{
public:
	Hand();

	virtual ~Hand();

	//adds a card to the hand
	void Add(Card* aCard);

	//clears hand of all cards
	void Clear();

	vector<Card*> m_Cards;
};

