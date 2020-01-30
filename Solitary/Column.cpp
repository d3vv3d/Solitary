#include "Column.h"

Column::Column() {
	m_Cards.reserve(20);
}

Column::~Column() {
}

bool Column::CanAddCard(Card* pCard) {
	//check if column is empty
	if (m_Cards.empty()) {
		//only allow kings to be placed
		if ((*pCard).GetRank() == Card::KING) {
			return true;
		}
	}
	else if ((*pCard).GetRank() != 0) {
		//make sure only red cards can go on black cards and vice versa
		if ((*pCard).GetSuit() % 2 != (*m_Cards.back()).GetSuit() % 2) {
			//make sure the card is oneless than the one it is to be put on top of
			if ((*pCard).GetRank() == ((*m_Cards.back()).GetRank() - 1)) {
				return true;
			}
		}
	}
	return false;
}

bool Column::MovedCard(Hand& aHand) {
	for (int j = aHand.m_Cards.size() - 1; j >= 0; j--) {
		if (CanAddCard(aHand.m_Cards[j])) {
			if (!((j - 1) < 0)) {
				if ((*aHand.m_Cards[j - 1]).GetRank() == 0) {
					(*aHand.m_Cards[j - 1]).Flip();
				}
			}
			for (int i = j; i <= aHand.m_Cards.size() -1; i++) {
				Add(aHand.m_Cards[i]);
			}
			for (int k = aHand.m_Cards.size() - 1; k >= j; k--) {
				aHand.m_Cards.pop_back();
			}
			return true;
		}
	}
	cout << "Can't make that move." << std::endl;
	return false;
}

string Column::StringCardAt(int cardNum) const {
	if (cardNum < m_Cards.size()) {
		return Card::GetCardAsString(m_Cards.at(cardNum));
	}
	return "   ";
}

void Column::FlipAllButLast() {
	for (int i = 0; i < (m_Cards.size() - 1); i++) {
		(*m_Cards.at(i)).Flip();
	}
}

ostream& operator<<(ostream& os, const Column& aColumn) {
	for (int i = 0; i < aColumn.m_Cards.size(); i++) {
		os << (*aColumn.m_Cards.at(i)) << "\t";
	}
	return os;
}