#include "19127048.h"
#include "19127493.h"

void Easy_Game(int deck[SUITS][RANKS], int***& hands, int ChooseofPokerGame, const char* suits[], const char* ranks[]) {

	Poker_Game(deck, hands, ChooseofPokerGame, suits, ranks, "Easy Game");

}

void Medium_Game(int deck[SUITS][RANKS], int***& hands, int ChooseofPokerGame, const char* suits[], const char* ranks[]) {

	Poker_Game(deck, hands, ChooseofPokerGame, suits, ranks, "Medium Game");

}

void Hard_Game(int deck[SUITS][RANKS], int***& hands, int ChooseofPokerGame, const char* suits[], const char* ranks[]) {

	Poker_Game(deck, hands, ChooseofPokerGame, suits, ranks, "Hard Game");

}