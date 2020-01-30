#pragma once

#include "Deck.h"
#include "Pile.h"
#include "Column.h"
#include "AceStack.h"

class Game
{
public:
	Game();

	~Game();

	//plays the game of solitary
	void Play();

private:
	Deck m_Deck;
	Pile m_Pile;
	Column m_Columns[7];
	AceStack m_AceStacks[4];
};

