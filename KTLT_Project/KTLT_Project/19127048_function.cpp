#include "19127048.h"
#include "19127493.h"

void shuffleCards(int deck[][RANKS])
{
	int number = 1;
	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < RANKS; j++)
		{
			deck[i][j] = number;
			number++;
		}
	}
	

	srand(time(NULL));
	for (int i = 0; i < SUITS * RANKS; i++)
	{
		int pos1 = 0 + rand() % (3 + 1 - 0);
		int pos2 = 0 + rand() % (12 + 1 - 0);
		int pos3 = 0 + rand() % (3 + 1 - 0);
		int pos4 = 0 + rand() % (12 + 1 - 0);;


		swap(deck[pos1][pos2], deck[pos3][pos4]);
	}
}

int** dealingForHand(int deck[SUITS][FACES])
{
	////		CẤP PHÁT ĐỘNG		////
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(hand + i) = new int[2];
	}


	int card = 1;
	int IndexofHand = 0;
	while (card <= 5)
	{
		for (int i = 0; i < SUITS; i++)
		{
			for (int j = 0; j < RANKS; j++)
			{
				if (deck[i][j] == card)
				{
					hand[IndexofHand][0] = i;
					hand[IndexofHand][1] = j;
					IndexofHand++;
				}
			}
		}
		card++;
	}
	return hand;
}

int** createHandTest(int a[])
{
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(hand + i) = new int[2];
	}


}

int isFourOfAKind(int** hand)
{
	////		SO SÁNH CÁC 4 LÁ BÀI LIỀN KỀ		////
	if (isSequenceFourOfAKind(hand))
	{
		return 7;
	}
	else
	{
		return 0;
	}
}

int isFullHouse(int** hand)
{
	if (isSequenceFullHouse)
	{
		return 6;
	}
	else
	{
		return 0;
	}
}

int isFlush(int** hand)
{
	if (isSequenceFlush)
	{
		return 5;
	}
	else
	{
		return 0;
	}
}

////////////////////////////////////////////////////////////////////////////////

void printMatrix(int deck[][RANKS])
{
	for (int i = 0; i < SUITS; i++)
	{
		for (int j = 0; j < RANKS; j++)
		{
			cout << deck[i][j] << "\t";
		}
		cout << endl;
	}
}

bool isSequenceFourOfAKind(int** hand)
{
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


	for (int i = 0; i < 5 - 2; i++)
	{
		if (handTest[i][1] != handTest[i + 1][1])
		{
			return false;
		}
	}
	return true;
}

bool isSequenceFullHouse(int** hand)
{
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


	for (int i = 0; i < 5 - 3; i++)
	{
		if (handTest[i][1] != handTest[i + 1][1])
		{
			return false;
		}
	}
	return true;
}

bool isSequenceFlush(int** hand)
{
	for (int i = 0; i < 5 - 1; i++)
	{
		if (hand[i][0] != hand[i + 1][0])
		{
			return false;
		}
	}
	return true;
}