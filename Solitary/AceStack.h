#pragma once

#include "Hand.h"

class AceStack : public Hand
{
public:
	AceStack();
	~AceStack();

	string StringLastCard() const;

	bool MovedCard(Hand& aHand);

private:
	bool CanAddCard(Card* pCard);
};

