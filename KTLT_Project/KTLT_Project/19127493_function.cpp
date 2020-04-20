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
	/*	////		INPUT NHỮNG LÁ BÀI SẼ ĐƯỢC TEST (Create hand test)			////
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	int** result;
	result = createHandTest(a, deck);
	cout << isStraightFlush(result) << endl;
*/
	return 0;
}