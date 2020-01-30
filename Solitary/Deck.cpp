#include <algorithm>
#include "Deck.h"

using std::random_shuffle;

Deck::Deck() {
	m_Cards.reserve(52);
	Populate();
}

Deck::~Deck() {}

void Deck::Populate() {
	Clear();
	//create standard deck
	for (int s = Card::CLUBS; s <= Card::HEARTS; s++) {
		for (int r = Card::ACE; r <= Card::KING; r++) {
			Add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
		}
	}
}

void Deck::Shuffle() {
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

bool Deck::Deal(Hand& aHand) {
	if (!m_Cards.empty()) {
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
		return true;
	}
	else {
		cout << "Out of cards. Unable to deal.";
		return false;
	}
}

Card* Deck::GetLastCard() const {
	if (!m_Cards.empty()) {
		return m_Cards.back();
	}
	else {
		cout << "Out of cards. Unable to deal.";
	}
}

Card* Deck::GetAndRemoveLastCard() {
	if (!m_Cards.empty()) {
		Card* temp = m_Cards.back();
		m_Cards.pop_back();
		return temp;
	}
	else {
		cout << "Out of cards. Unable to deal.";
	}
}

string Deck::CardsLeft() {
	if (!m_Cards.empty()) {
		return " XX";
	}
	return "   ";
}
