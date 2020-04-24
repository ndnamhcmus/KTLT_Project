#include "19127048.h"
#include "19127493.h"

////		PROTOTYPE		////
void shuffleCards(int deck[SUITS][RANKS])
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

int** dealingForHand(int deck[SUITS][RANKS])
{
	////		CẤP PHÁT ĐỘNG		////
	int** result = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(result + i) = new int[2];
	}


	////		RANDOM CÁC LÁ BÀI TRÊN TAY		////
	int handTest[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		handTest[i] = 1 + rand() % (52 + 1 - 1);
		for (int j = 0; j < i; j++)		// kiểm tra các lá bài trên tay có bị trùng nhau không
		{
			while (handTest[i] == handTest[j])	// trùng thì chạy vòng lặp đến khi hết trùng
			{
				handTest[i] = 1 + rand() % (52 + 1 - 1);
			}
		}
	}
	

	bool is_found = false;
	int IndexofResult = 0;
	for (int IndexofhandTest = 0; IndexofhandTest < 5; IndexofhandTest++)
	{
		is_found = false;
		for (int i = 0; i < SUITS; i++)
		{
			for (int j = 0; j < RANKS; j++)
			{
				if (deck[i][j] == handTest[IndexofhandTest])
				{
					is_found = true;	//	dừng lại không quét qua các lá bài phía sau nếu đã tìm thấy


					*(*(result + IndexofResult) + 0) = i;
					*(*(result + IndexofResult) + 1) = j;
					IndexofResult++;


					break;
				}
			}
			if (is_found)	//	dừng lại không quét qua các lá bài phía sau nếu đã tìm thấy
			{
				break;
			}
		}
	}


	return result;
}

int** createHandTest(int deck[SUITS][RANKS], int a[])
{
	////		CẤP PHÁT ĐỘNG DÙNG ĐỂ LƯU CÁC VỊ TRÍ TRONG BỘ BÀI		////
	int** result = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(result + i) = new int[2];
	}

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
		return 1;
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
		return 1;
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
		return 1;
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
		return 1;
	}
	else
	{
		return 0;
	}
}

int*** dealingForHands(int deck[SUITS][RANKS], int n)
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


	int card = 1;	// dùng để xác định lá bài đầu tiên chia cho người chơi
	int cardForDealing;		// dùng để chia bài
	int IndexofPlayers = 0;
	bool is_found;
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
						is_found = true;	//	dừng lại không quét qua các lá bài phía sau nếu đã tìm thấy


						////		LƯU VỊ TRÍ CỦA LÁ BÀI TRONG MA TRẬN DECK			////
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
			cardForDealing = cardForDealing + n;	// chia theo vòng tròn
		}
		IndexofPlayers = 0;		// reset Index của mảng 3D Players
		card++;		// tăng lá bài đầu tiên chia cho từng người lên
	}


	return Players;
}

int* rankingHands(int*** hands, int n)
{
	int* RankofThePlayer = new int[n];
	int* ScoreofThePlayer = new int[n];

	for (int i = 0; i < n; i++)
	{
		ScoreofThePlayer[i] = getStatusOfHand(*(hands + i));
		RankofThePlayer[i] = i;
	}


	////		SORT RANK		////
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (ScoreofThePlayer[i] < ScoreofThePlayer[j])
			{
				swap(ScoreofThePlayer[i], ScoreofThePlayer[j]);
				swap(RankofThePlayer[i], RankofThePlayer[j]);
			}
		}
	}

	
	delete[] ScoreofThePlayer;
	ScoreofThePlayer = nullptr;


	return RankofThePlayer;
}

////////////////////////////////////////////////////////////////////////////////

void printMatrix(int deck[SUITS][RANKS])
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

void print3DArray(int*** Array3D, int size, int row, int column)
{
	for (int i = 0; i < size; i++)
	{
		cout << i << endl;
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < column; k++)
			{
				cout << Array3D[i][j][k] << "\t";
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

int** DellocateDoublePointer(int** Matrix, int Row)
{
	for (int i = 0; i < Row; i++)
	{
		delete[] * (Matrix + i);
	}
	delete[] Matrix;
	Matrix = nullptr;


	return Matrix;
}

int*** DellocateTriplePointer(int*** Array3D, int sizeof3D, int Row)
{
	////		GIẢI PHÓNG MẢNG 1D		////
	for (int i = 0; i < sizeof3D; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			delete[] * (*(Array3D + i) + j);
		}
	}
	////		GIẢI PHÓNG MA TRẬN		////
	for (int i = 0; i < sizeof3D; i++)
	{
		delete[] * (Array3D + i);
	}
	////		GIẢI PHÓNG MẢNG 3D		////
	delete[] Array3D;


	Array3D = nullptr;


	return Array3D;
}