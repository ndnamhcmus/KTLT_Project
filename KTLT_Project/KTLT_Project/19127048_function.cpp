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