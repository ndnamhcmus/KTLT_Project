#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define SUITS 4
#define RANKS 13
#define FACES 13

void shuffleCards(int deck[][RANKS]);

int** dealingForHand(int deck[SUITS][FACES]);

////////////////////////////////////////////////////////////////////////////////

void printMatrix(int deck[][RANKS]);
