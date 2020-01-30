#include "AceStack.h"

AceStack::AceStack() {
	m_Cards.reserve(13);
}

AceStack::~AceStack() {}

string AceStack::StringLastCard() const {
	if (m_Cards.size()) {
		return Card::GetCardAsString(m_Cards.back());
	}
	return "   ";
}

bool AceStack::CanAddCard(Card* pCard) {
	//check if column is empty
	if (m_Cards.empty()) {
		//only allow aces to be placed
		if ((*pCard).GetRank() == Card::ACE) {
			return true;
		}
	}
	else if ((*pCard).GetRank() != 0) {
		//make sure each suit can only stack on itself
		if ((*pCard).GetSuit() == (*m_Cards.back()).GetSuit()) {
			//make sure the card is one more than the one it is to be put on top of
			if ((*pCard).GetRank() == ((*m_Cards.back()).GetRank() + 1)) {
				return true;
			}
		}
	}
	return false;
}

bool AceStack::MovedCard(Hand& aHand) {
	int j = aHand.m_Cards.size() - 1;
		if (CanAddCard(aHand.m_Cards[j])) {
			if (!((j - 1) < 0)) {
				if ((*aHand.m_Cards[j - 1]).GetRank() == 0) {
					(*aHand.m_Cards[j - 1]).Flip();
				}
			}
			for (int i = j; i <= aHand.m_Cards.size() - 1; i++) {
				Add(aHand.m_Cards[i]);
			}
			for (int k = aHand.m_Cards.size() - 1; k >= j; k--) {
				aHand.m_Cards.pop_back();
			}
			return true;
		}
	cout << "Can't make that move." << std::endl;
	return false;
}