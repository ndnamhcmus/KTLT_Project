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


	bool is_found = false;
	int IndexofResult = 0;
	for (int card = 1; card <= 5; card++)
	{
		is_found = false;
		for (int i = 0; i < SUITS; i++)
		{
			for (int j = 0; j < RANKS; j++)
			{
				if (deck[i][j] == card)
				{
					is_found = true;	//	DÙNG ĐỂ BỎ QUA CÁC LÁ BÀI PHÍA SAU NẾU ĐÃ TÌM THẤY LÁ BÀI CẦN TÌM


					*(*(result + IndexofResult) + 0) = i;
					*(*(result + IndexofResult) + 1) = j;
					IndexofResult++;


					break;
				}
			}
			if (is_found)	//	DÙNG ĐỂ BỎ QUA CÁC LÁ BÀI PHÍA SAU NẾU ĐÃ TÌM THẤY LÁ BÀI CẦN TÌM
			{
				break;
			}
		}
	}


	return result;
}

int** createHandTest(int a[])
{
	////		CẤP PHÁT ĐỘNG DÙNG ĐỂ LƯU CÁC VỊ TRÍ TRONG BỘ BÀI		////
	int** result = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(result + i) = new int[2];
	}


	////		INPUT DECK		////
	int deck[SUITS][RANKS] = { 0 };
	shuffleCards(deck);
	printMatrix(deck);


	////		INPUT NHỮNG LÁ BÀI SẼ ĐƯỢC TEST			////
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter your card number: ";
		cin >> a[i];
	}



	////		TÌM CÁC LÁ BÀI TRONG MA TRẬN DECK		////
	bool is_found = false;
	int IndexofResult = 0;
	for (int IndexorArray = 0; IndexorArray < 5; IndexorArray++)
	{
		bool is_found = false;
		for (int i = 0; i < SUITS; i++)
		{
			for (int j = 0; j < RANKS; j++)
			{
				if (deck[i][j] == a[IndexorArray])
				{
					is_found = true;


					result[IndexofResult][0] = i;
					result[IndexofResult][1] = j;
					IndexofResult++;


					break;
				}
			}
			if (is_found)
			{
				break;
			}
		}
	}


	return result;
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
	if (checkFullHouse(hand))
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
	if (checkFlush(hand))
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
	if (checkStraight(hand))
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

int*** dealingForHands(int deck[SUITS][FACES], int n)
{
	////		CẤP PHÁT ĐỘNG		////
	////		CON TRỎ CẤP 3 LƯU CON TRỎ CẤP 2			////
	int*** Players = new int** [n];
	////		CON TRỎ CẤP 2 LƯU CON TRỎ CẤP 1 ( DÒNG CỦA MA TRẬN )		////
	for (int i = 0; i < n; i++)
	{
		*(Players + i) = new int* [5];
	}
	////		CẤP PHÁT ĐỘNG MẢNG 1 CHIỀU ( CỘT CỦA MA TRẬN )		////
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			*(*(Players + i) + j) = new int[2];
		}
	}


	bool is_found;
	int card = 1;	// dùng để xác định lá bài đầu tiên chia cho người chơi
	int cardForDealing;		// dùng để chia bài
	int IndexofPlayers = 0;
	for (int Player = 0; Player < n; Player++)
	{
		is_found = false;
		cardForDealing = card;
		for (int times = 0; times < 5; times++)
		{
			is_found = false;
			for (int i = 0; i < SUITS; i++)
			{
				for (int j = 0; j < RANKS; j++)
				{
					if (cardForDealing == deck[i][j])
					{
						is_found = true;


						*(*(*(Players + Player) + IndexofPlayers) + 0) = i;
						*(*(*(Players + Player) + IndexofPlayers) + 1) = j;
						IndexofPlayers++;


						break;
					}
				}
				if (is_found)
				{
					break;
				}
			}
			cardForDealing = cardForDealing + n;
		}
		IndexofPlayers = 0;
		card++;
	}


	return Players;
}
//
//int* rankingHands(int*** hands, int n)
//{
//
//}
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
			cout << *(*(Matrix + i) + j) << "\t";
		}
		cout << endl;
	}
}

void print3DArray(int*** ThreeDArray, int size, int row, int column)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << endl;
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < column; k++)
			{
				cout << ThreeDArray[i][j][k] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
}

bool checkFourOfAKind(int** hand)
{
	////		CẤP PHÁT ĐỘNG		////
	int** handTest = new int* [5];
	for (int i = 0; i < 5; i++)
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


	int checkcountArray[5] = { 0 };
	int IndexofcheckTemp = 0;


	int count = 1;
	for (int i = 0; i < 5 - 1; i++)
	{
		if (handTest[i][1] == handTest[i + 1][1])
		{
			count++;
			checkcountArray[IndexofcheckTemp] = count;

		}
		else
		{
			count = 1;
			IndexofcheckTemp++;
			checkcountArray[IndexofcheckTemp] = count;
		}

	}
	if ((checkcountArray[0] == 4 && checkcountArray[1] == 1) || (checkcountArray[0] == 1 || checkcountArray[1] == 4))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkFullHouse(int** hand)
{
	////		CẤP PHÁT ĐỘNG		////
	int** handTest = new int* [5];
	for (int i = 0; i < 5; i++)
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


	int checkcountArray[5] = { 0 };
	int IndexofcheckTemp = 0;


	int count = 1;
	for (int i = 0; i < 5 - 1; i++)
	{
		
		if (handTest[i][1] == handTest[i + 1][1])
		{
			count++;
			checkcountArray[IndexofcheckTemp] = count;
		}
		else
		{
			count = 1;
			IndexofcheckTemp++;
			checkcountArray[IndexofcheckTemp] = count;
		}
	}


	if ((checkcountArray[0] == 3 && checkcountArray[1] == 2) || (checkcountArray[0] == 2 || checkcountArray[1] == 3))
	{
		return true;
	}
	else
	{
		return false;
	}
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

int** DellocateDoublePointer(int** Matrix, int Row, int Column)
{
	for (int i = 0; i < Column; i++)
	{
		delete[] * (Matrix + i);
	}
	delete[] Matrix;
	Matrix = nullptr;


	return Matrix;
}