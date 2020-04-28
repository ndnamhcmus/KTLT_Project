#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define SUITS 4
#define RANKS 13

void shuffleCards(int deck[SUITS][RANKS]);

int** dealingForHand(int deck[SUITS][RANKS]);

int** createHandTest(int deck[SUITS][RANKS], int a[]);

int isFourOfAKind(int** hand);

int isFullHouse(int** hand);

int isFlush(int** hand);

int isStraight(int** hand);

int*** dealingForHands(int deck[SUITS][RANKS], int n);

int* rankingHands(int*** hands, int n);

////////////////////////////////////////////////////////////////////////////////

////		MENU		////

void GameModeMenu();

void LevelofdifficultMenu();

void SinglePlayerMenu();

void MultiplayerMenu(int n);

void DealerMenu();

////////////////////////////////////////////////////////////////////////////////

////		main		////

void SinglePlayer(int deck[SUITS][RANKS], int array[], const char* suits[], const char* ranks[], int**& hand, int ChooseofSinglePlayer);

void MultiPlayer(int deck[SUITS][RANKS], int***& hands, int n, const char* suits[], const char* ranks[], int ChooseofMultiPlayer);

////////////////////////////////////////////////////////////////////////////////

void printMatrix(int deck[SUITS][RANKS]);

void printPointerMatrix(int** Matrix, int row, int column);

void print3DArray(int*** Array3D, int size, int row, int column);

bool checkFourOfAKind(int** hand);

bool checkFullHouse(int** hand);

bool checkFlush(int** hand);

bool checkStraight(int** hand);

int** DellocateDoublePointer(int** Matrix, int Row);

int*** DellocateTriplePointer(int*** Array3D, int sizeof3D, int Row);
