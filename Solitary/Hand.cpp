#include "Hand.h"

Hand::Hand() {
	m_Cards.reserve(7);
}

Hand::~Hand() {
	Clear();
}

void Hand::Add(Card* pCard) {
	m_Cards.push_back(pCard);
}

void Hand::Clear() {
	//iterate through vector, freeing all memory on the heap
	vector<Card*>::iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); iter++) {
		delete *iter;
		*iter = 0;
	}
	//clear vector of pointers
	m_Cards.clear();
}

