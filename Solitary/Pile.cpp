#include "Pile.h"

Pile::Pile() {
	Clear();
}


Pile::~Pile() {}

bool Pile::RefillDeck(Deck& aDeck) {
	if (aDeck.m_Cards.empty()) {
		std::reverse(m_Cards.begin(), m_Cards.end());
		aDeck.m_Cards = m_Cards;
		m_Cards.clear();
		return true;
	}
	else {
		cout << "Can only refill an empty deck.";
		return false;
	}
}

string Pile::GetLastCardString() {
	if (!m_Cards.empty()) {
		return Card::GetCardAsString(m_Cards.back());
	}
	else {
		return "   ";
	}
}
