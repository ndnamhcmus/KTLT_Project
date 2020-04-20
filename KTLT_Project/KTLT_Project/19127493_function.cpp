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
	if (count == 3 && checkFullHouse(hand) == false)
		return 3;
	if (count != 3 || checkFullHouse(hand) == true)
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
	///         Check diffrent		////
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
		if (handTest[0][1] == handTest[1][1] && handTest[2][1] == handTest[3][1])
			return 2;
		if (handTest[1][1] == handTest[2][1] && handTest[3][1] == handTest[4][1])
			return 2;
		if (handTest[0][1] == handTest[1][1] && handTest[3][1] == handTest[4][1])
			return 2;
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
	///         Check diffrent		////
	int count = 0;
	for (int i = 0; i < 5 - 1; i++)
	{
		if (handTest[i][1] != handTest[i + 1][1])
		{
			count++;
		}
	}
	if (count != 3)
		return 0;
	else 
		return 1;
	
}
int getHighestCard(int** hand) {

}
