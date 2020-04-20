#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define SUITS 4
#define RANKS 13
#define FACES 13

void shuffleCards(int deck[][RANKS]);

int** dealingForHand(int deck[SUITS][FACES]);

int** createHandTest(int a[]);

int isFourOfAKind(int** hand);

int isFullHouse(int** hand);

int isFlush(int** hand);

int isStraight(int** hand);

////////////////////////////////////////////////////////////////////////////////

void printMatrix(int deck[][RANKS]);

void printPointerMatrix(int** Matrix, int row, int column);

bool checkFourOfAKind(int** hand);

bool checkFullHouse(int** hand);

bool checkFlush(int** hand);

bool checkStraight(int** hand);