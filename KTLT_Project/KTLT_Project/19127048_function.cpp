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
	int** result = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(result + i) = new int[2];
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
					result[IndexofHand][0] = i;
					result[IndexofHand][1] = j;
					IndexofHand++;
				}
			}
		}
		card++;
	}
	return result;
}

int** createHandTest(int a[])
{
	////		CẤP PHÁT ĐỘNG		////
	int** hand = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(hand + i) = new int[2];
	}


	int deck[SUITS][RANKS] = { 0 };
	shuffleCards(deck);


	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	return 0;
}

int isFourOfAKind(int** hand)
{
	////		SO SÁNH CÁC 4 LÁ BÀI LIỀN KỀ		////
	if (checkFourOfAKind(hand))
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
	if (checkFullHouse)
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
	if (checkFlush)
	{
		return 5;
	}
	else
	{
		return 0;
	}
}

int isStraight(int** hand)
{
	if (checkStraight)
	{
		return 4;
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

void printPointerMatrix(int** Matrix, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << "\t";
		}
		cout << endl;
	}
}

bool checkFourOfAKind(int** hand)
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

bool checkFullHouse(int** hand)
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

bool checkFlush(int** hand)
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

bool checkStraight(int** hand)
{
	////		CẤP PHÁT ĐỘNG		////
	int** handTest = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(handTest + i) = new int[2];
	}


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


	////		KIỂM TRA RANK LIÊN TIẾP		////
	for (int i = 0; i < 5 - 1; i++)
	{
		
		if (handTest[i][1] + 1 != handTest[i + 1][1])
		{
			return false;
		}
	}
	return true;
}