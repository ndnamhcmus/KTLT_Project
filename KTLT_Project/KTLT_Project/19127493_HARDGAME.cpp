#include "19127048.h"
#include "19127493.h"

const int n = 2;

void Hard_Game(int deck[SUITS][RANKS], int***& hands, int ChooseofHardGame, const char* suits[], const char* ranks[]) {

	////		CẤP PHÁT ĐỘNG		////
	int** dealer = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(dealer + i) = new int[2];
	}

	int** player = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(player + i) = new int[2];
	}

	hands = dealingForHands(deck, n);
	dealer = *(hands + n - 1);
	player = *(hands + n - 2);

	////		In các là bài của người chơi và Dealer		////
	cout << "Player's card is: " << endl;
	printHand(player, suits, ranks);
	cout << "Dealer's card is: " << endl;
	printHand(dealer, suits, ranks);


	int* rank = nullptr;
	int times;
	int card;
	int dealer_cards = 0;

	switch (ChooseofHardGame)
	{

	case 1:////		Kiểm tra điểm của người chơi và dealer 		////

		cout << "Player's score is " << getStatusOfHand(player) << endl;
		cout << "Dealer's score is " << getStatusOfHand(dealer) << endl;
		break;

	case 2:	////		Bốc và thay thế bài 		////

		times = 1;
		card = 1;
		for (times; times < 7; times++) {
			if (times % 2 == 1) {
				int option;
				do {
					cout << "Player can choose to draw or not" << endl;
					cout << "1. Yes" << endl;
					cout << "2. No" << endl;
					cout << "Choose: ";
					cin >> option;
				} while (option < 1 || option>2);
				if (option == 1) {
					int draw_card[2];
					int slect_card;

					////		Bốc bài		////
					for (int l = 0; l < SUITS; l++)
						for (int k = 0; k < RANKS; k++)
							if (deck[l][k] == n * 5 + card)
							{
								draw_card[0] = l;
								draw_card[1] = k;
								card++;
								dealer_cards++;
							}
					cout << "This is the card you just drew: " << endl;
					cout << "(" << suits[draw_card[0]] << ", " << ranks[draw_card[1]] << ")" << endl;

					////		Chọn lá bài thay thế		////
					do {
						cout << "Select the card you want to replace (0 -> 5): ";
						cin >> slect_card;
					} while (slect_card > 5 || slect_card < 0);

					////		Thay thế các lá bài		////
					if (slect_card != 5) {
						player[slect_card][0] = draw_card[0];
						player[slect_card][1] = draw_card[1];
					}
				}

			}
			if (times % 2 == 0) {
				int option1;
				do {
					cout << "Dealer can choose to draw or not" << endl;
					cout << "1. Yes" << endl;
					cout << "2. No" << endl;
					cout << "Choose: ";
					cin >> option1;
				} while (option1 < 1 || option1 > 2);
				if (option1 == 1) {
					int draw_card1[2];
					int slect_card1;

					////		Bốc bài		////
					for (int l = 0; l < SUITS; l++)
						for (int k = 0; k < RANKS; k++)
							if (deck[l][k] == n * 5 + card)
							{
								draw_card1[0] = l;
								draw_card1[1] = k;
								card++;
							}
					cout << "This is the card you just drew: " << endl;
					cout << "(" << suits[draw_card1[0]] << ", " << ranks[draw_card1[1]] << ")" << endl;

					////		Chọn lá bài thay thế		////
					do {
						cout << "Select the card you want to replace (0 -> 5): ";
						cin >> slect_card1;
					} while (slect_card1 > 5 || slect_card1 < 0);

					////		Thay thế các lá bài		////
					if (slect_card1 != 5) {
						dealer[slect_card1][0] = draw_card1[0];
						dealer[slect_card1][1] = draw_card1[1];
					}
				}

			}


			*(hands + n - 2) = player;
			*(hands + n - 1) = dealer;

			cout << "Player's card after the change is: " << endl;
			printHand(player, suits, ranks);
			cout << "Dealer's card after the change is: " << endl;
			printHand(dealer, suits, ranks);
			break;
		}

	case 3:

		rank = rankingHands_for_hardgame(hands, n, dealer_cards);
		cout << "Rank:\t";
		for (int i = 1; i <= n; i++)
		{
			cout << i << "\t";
		}
		cout << "\nPlayer:\t";
		for (int i = 0; i < n; i++)
		{
			cout << rank[i] << "\t";
		}
		break;

	default:
		cout << "Something wrong, try again:\n";
		break;
	}

	DellocateDoublePointer(player, 5);
	DellocateDoublePointer(dealer, 5);
	delete[] rank;

}