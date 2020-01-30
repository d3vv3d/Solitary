#include "Card.h"

Card::Card(rank r, suit s, bool ifu):
	m_Rank(r), m_Suit(s), m_IsFaceUp(ifu) {}

int Card::GetRank() const {
	//if a card is face down, its value is 0
	int value = 0;
	if (m_IsFaceUp) {
		//value is the number showing on the card
		value = m_Rank;
	}
	return value;
}

int Card::GetSuit() const {
	//if a card is face down, its value is 0
	int suit = 0;
	if (m_IsFaceUp) {
		//value is the number showing on the card
		suit = m_Suit;
	}
	return suit;
}

string Card::GetCardAsString(Card* pCard) {
	const string RANKS[] = { " A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K" };
	const string SUITS[] = { "c", "d", "s", "h" };

	if ((*pCard).m_IsFaceUp) {
		return RANKS[(*pCard).m_Rank - 1] + SUITS[(*pCard).m_Suit - 1];;
	}
	else {
		return " XX";
	}
}

void Card::Flip() {
	m_IsFaceUp = !m_IsFaceUp;
}

// overloads << operator so Card object can be sent to cout
ostream& operator<<(ostream& os, const Card& aCard) {
	const string RANKS[] = {" A", " 2", " 3", " 4", " 5", " 6", " 7", " 8", " 9", "10", " J", " Q", " K"};
	const string SUITS[] = {"c", "d", "s", "h"};

	if (aCard.m_IsFaceUp) {
		os << RANKS[aCard.m_Rank - 1] << SUITS[aCard.m_Suit - 1];
	}
	else {
		os << " XX";
	}

	return os;
}
