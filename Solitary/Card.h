#pragma once

#include <iostream>
#include <string>

using std::ostream;
using std::cout;
using std::string;

class Card
{
public:
	enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
	enum suit { CLUBS = 1, DIAMONDS, SPADES, HEARTS };

	//overloading << operator so can send Card object to standard output
	friend ostream& operator<<(ostream& os, const Card& aCard);

	Card(rank r = ACE, suit s = HEARTS, bool ifu = true);

	//returns the rank of a card, A - K
	int GetRank() const;

	//returns the suit of a card, clubs - spades
	int GetSuit() const;

	//flips a card; if face up, becomes face down and vice versa
	void Flip();

	static string GetCardAsString(Card* pCard);

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

