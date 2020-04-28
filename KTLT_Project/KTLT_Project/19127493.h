#include <iostream>

#define SUITS 4
#define RANKS 13
#define FACES 13

using namespace std;

void printCardsShuffling(int deck[][RANKS], const char* suits[], const char* ranks[]);

void printHand(int** hand,const char* suits[],const char* ranks[]);

int isStraightFlush(int** hand);

int isThreeOfAKind(int** hand);

int isTwoPairs(int** hand);

int isPair(int** hand);

int getHighestCard(int** hand);

int getStatusOfHand(int** hand);

int* evaluateHands(int n, int s);

////////////////////////////////////////////////////////////////////////////////

int getHighestMark(int** hand);

void Poker_Game_For_Dealer(int deck[SUITS][RANKS], int***& hands, int n, int ChooseofDealer, const char* suits[], const char* ranks[]);

void Poker_Game(int deck[SUITS][RANKS], int***& hands, int n, int ChooseofPokerGame, const char* suits[], const char* ranks[]);