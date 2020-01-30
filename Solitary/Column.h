#pragma once

#include "Hand.h"

class Column : public Hand
{
public:
	Column();
	~Column();

	//retruns a string with the information about the card at the give position and three spaces if no card exists at the given position
	string StringCardAt(int cardNum) const;

	void FlipAllButLast();

	friend ostream& operator<<(ostream& os, const Column& aColumn);

	bool MovedCard(Hand& aHand);

private:
	bool CanAddCard(Card* pCard);
};

