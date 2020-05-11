#include "19127048.h"
#include "19127493.h"

void Easy_Game(int deck[SUITS][RANKS], int***& hands, int**& player, int**& dealer, int& player_cards, int& dealer_cards, int ChooseofPokerGame, const char* suits[], const char* ranks[]) {

	Poker_Game(deck, hands, player, dealer, player_cards, dealer_cards, ChooseofPokerGame, suits, ranks, "Easy Game");

}

void Medium_Game(int deck[SUITS][RANKS], int***& hands, int**& player, int**& dealer, int& player_cards, int& dealer_cards, int ChooseofPokerGame, const char* suits[], const char* ranks[]) {

	Poker_Game(deck, hands, player, dealer, player_cards, dealer_cards, ChooseofPokerGame, suits, ranks, "Medium Game");

}

void Hard_Game(int deck[SUITS][RANKS], int***& hands, int**& player, int**& dealer, int& player_cards, int& dealer_cards, int ChooseofPokerGame, const char* suits[], const char* ranks[]) {

	Poker_Game(deck, hands, player, dealer, player_cards, dealer_cards, ChooseofPokerGame, suits, ranks, "Hard Game");

}