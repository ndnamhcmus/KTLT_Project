#include <iostream>

#define SUITS 4
#define RANKS 13
#define FACES 13

using namespace std;

void printCardsShuffling(int deck[][RANKS], const char* suits[], const char* faces[]);
int** dealingForHand(int deck[SUITS][FACES]);
void printHand(int** hand,const char* suits[],const char* faces[]);