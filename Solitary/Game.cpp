#include "Game.h"

#include <ctime>

using std::endl;
using std::cin;

Game::Game() {
	//seed the random number generator
	//srand(static_cast<unsigned int>(0));
	srand(static_cast<unsigned int>(time(0)));

	//create and shuffle the deck
	m_Deck.Populate();
	m_Deck.Shuffle();

	//set up the game
	for (int j = 0; j < 7; j++) {
		for (int i = j; i < 7; i++) {
			m_Deck.Deal(m_Columns[i]);
		}
	}

	for (int i = 0; i < 7; i++) {
		m_Columns[i].FlipAllButLast();
	}
}

Game::~Game() {
}

void Game::Play() {
	int from, to;
	bool invalidInput;
	//print information to screen
	//Deck\tPile\t  \tAs0\tAs1\tAS2\tAS3
	//C1\tC2\tC3\t...
	do {
		system("cls");
		invalidInput = true;

		//cout << m_Columns[1] << endl;

		cout << m_Deck.CardsLeft() << "\t" << m_Pile.GetLastCardString() << "\t   \t" << m_AceStacks[0].StringLastCard() << "\t" << m_AceStacks[1].StringLastCard() << "\t"
			<< m_AceStacks[2].StringLastCard() << "\t" << m_AceStacks[3].StringLastCard() << "\t" << endl;
		for (int j = 0; j < 20; j++) {
			for (int i = 0; i < 7; i++) {
				cout << m_Columns[i].StringCardAt(j) << "\t";
			}
			cout << endl;
		}
		do {
			cin >> from;
			if (from == -1) {
				break;
			}
			cin >> to;

			if (to == 0) {
				if (from == 1) {
					invalidInput = m_Pile.RefillDeck(m_Deck);
				}
				else {
					cout << "Invalid Input." << endl;
				}
			}
			else if (to == 1) {
				if (from == 0) {
					invalidInput = m_Deck.Deal(m_Pile);
				}
				else {
					cout << "Invalid Input." << endl;
				}
			}
			//Moving to an AceStack
			else if (2 <= to && to <= 5) {
				to -= 2;
				if (from == 1) {
					invalidInput = m_AceStacks[to].MovedCard(m_Pile);
				}
				else if (6 <= from && from <= 12) {
					invalidInput = m_AceStacks[to].MovedCard(m_Columns[from - 6]);
				}
			}
			//Moving to a Column
			else if (6 <= to && to <= 12) {
				to -= 6;
				if (from == 1) {
					invalidInput = m_Columns[to].MovedCard(m_Pile);
				}
				else if (2 <= from && from <= 5) {
					invalidInput = m_Columns[to].MovedCard(m_AceStacks[from - 2]);
				}
				else if (6 <= from && from <= 12) {
					invalidInput = m_Columns[to].MovedCard(m_Columns[from - 6]);
				}
				else {
					cout << "Invalid Input." << endl;
				}
			}
		} while (!invalidInput);
	} while (from != -1);
}