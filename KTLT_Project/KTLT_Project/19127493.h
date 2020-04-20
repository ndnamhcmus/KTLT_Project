#include <iostream>

#define SUITS 4
#define RANKS 13
#define FACES 13

using namespace std;

void printCardsShuffling(int deck[][RANKS], const char* suits[], const char* faces[]);

void printHand(int** hand,const char* suits[],const char* faces[]);

int isStraightFlush(int** hand);

int isThreeOfAKind(int** hand);

int isTwoPairs(int** hand);

int isPair(int** hand);

int getHighestCard(int** hand);
