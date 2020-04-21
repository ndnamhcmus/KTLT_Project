#include "19127048.h"
#include "19127493.h"

void printCardsShuffling(int deck[][RANKS], const char* suits[], const char* faces[]) {
	
	int key = 1;
	int time = 0;
	for (time; time < 52; time++)
		for (int i = 0; i < SUITS; i++)
			for (int j = 0; j < RANKS; j++)
				if (deck[i][j] == key) {
					cout << "(" << suits[i] << ", " << faces[j] << ")" << endl;
					key++;
				}
}

void printHand(int** hand,const char* suits[],const char* faces[]) {
	for (int i = 0; i < 5; i++)
		cout << "(" << suits[hand[i][0]] << ", " << faces[hand[i][1]] << ")" << endl;
}

int isStraightFlush(int** hand) {
	if (checkStraight(hand) && checkFlush(hand))
		return 8;
	return 0;
}
int isThreeOfAKind(int** hand) {
	////		CẤP PHÁT ĐỘNG		////
	int** handTest = new int* [5];
	for (int i = 0; i < 2; i++)
	{
		*(handTest + i) = new int[2];
	}
	handTest = hand;

	////		SORT RANK		////
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (handTest[i][1] > handTest[j][1])
			{
				swap(handTest[i][1], handTest[j][1]);
			}
		}
	}
	///         Check Three of a kind		////
	int count = 0;
	for (int i = 0; i < 5 - 1; i++)
	{
		if (handTest[i][1] == handTest[i + 1][1])
		{
			count++;
		}
	}
	int count1 = 0;
	for (int i = 0; i < 5 - 1; i++)
	{
		if (handTest[i][1] != handTest[i + 1][1])
		{
			count1++;
		}
	}
	if (count == 2 && count1 == 2)
		return 3;
	else
		return 0;
}
int isTwoPairs(int** hand) {
	////		CẤP PHÁT ĐỘNG		////
	int** handTest = new int* [5];
	for (int i = 0; i < 2; i++)
	{
		*(handTest + i) = new int[2];
	}
	handTest = hand;

	////		SORT RANK		////
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (handTest[i][1] > handTest[j][1])
			{
				swap(handTest[i][1], handTest[j][1]);
			}
		}
	}
	///         Check different		////
	int count = 0;
	for (int i = 0; i < 5 - 1; i++)
	{
		if (handTest[i][1] != handTest[i + 1][1])
		{
			count++;
		}
	}
	if (count != 2)
		return 0;
	else {
		if (checkFlush(hand) == false) {
			if (handTest[0][1] == handTest[1][1] && handTest[2][1] == handTest[3][1])
				return 2;
			if (handTest[1][1] == handTest[2][1] && handTest[3][1] == handTest[4][1])
				return 2;
			if (handTest[0][1] == handTest[1][1] && handTest[3][1] == handTest[4][1])
				return 2;
		}
		return 0;
	}
}
int isPair(int** hand) {
	////		CẤP PHÁT ĐỘNG		////
	int** handTest = new int* [5];
	for (int i = 0; i < 2; i++)
	{
		*(handTest + i) = new int[2];
	}
	handTest = hand;

	////		SORT RANK		////
	for (int i = 0; i < 5 - 1; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (handTest[i][1] > handTest[j][1])
			{
				swap(handTest[i][1], handTest[j][1]);
			}
		}
	}
	///         Check different		////
	int count = 0;
	for (int i = 0; i < 5 - 1; i++)
	{
		if (handTest[i][1] != handTest[i + 1][1])
		{
			count++;
		}
	}
	if (count == 3 && checkFlush(hand) == false)
		return 0;
	else 
		return 1;
	
}
int getHighestCard(int** hand) {
	if (isStraightFlush(hand) == 8)
		return 8;
	if (isFourOfAKind(hand) == 7)
		return 7;
	if (isFullHouse(hand) == 6)
		return 6;
	if (isFlush(hand) == 5)
		return 5;
	if (isStraight(hand) == 4)
		return 8;
	if (isThreeOfAKind(hand) == 3)
		return 3;
	if (isTwoPairs(hand) == 2)
		return 8;
	if (isPair(hand) == 1)
		return 8;
	return 0;
}
int getStatusOfHand(int** hand) {
	return getHighestCard(hand);
}
int* evaluateHands(int* ranked_hands, int s) {
	return 0;
}
////////////////////////////////////////////////////////////////////////////////

