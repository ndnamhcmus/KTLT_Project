﻿#include "19127048.h"
#include "19127493.h"

void Poker_Game_For_Dealer(int deck[SUITS][RANKS], int***& hands, int n, int ChooseofDealerGame, const char* suits[], const char* ranks[]) {

	////		CẤP PHÁT ĐỘNG		////
	int** dealer = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		*(dealer + i) = new int[2];
	}
	
	hands = dealingForHands(deck, n);
	dealer = *(hands + n - 1);
	////		In các là bài của từng người chơi		////
	for (int i = 0; i < n - 1; i++) {
		cout << "Player " << i << "'s card is: " << endl;
		printHand(*(hands + i), suits, ranks);
	}
	cout << "Dealer's card is: " << endl;
	printHand(dealer, suits, ranks);


	int* rank = nullptr;
	int player;

	switch (ChooseofDealerGame)
	{

	case 1:	
		
		////		Kiểm tra điểm của từng người chơi		////
		do
		{
			cout << "Which player you want to check: ";
			cin >> player;
			if (player < 0 || player >= n - 1)
			{
				cout << "Something wrong, player is from 0 to " << n - 2 << " try again: ";
				cin >> player;
			}

		} while (player < 0 || player >= n - 2);
		cout << "Player" << player << "'s score is " << getStatusOfHand(*(hands + player)) << endl;
		break;

	case 2:	////		Kiểm tra điểm của Dealer		////
		
		cout << "Dealer's score is " << getStatusOfHand(*(hands + n - 1)) << endl;
		break;

	case 3:	////		Bốc và thay thế bài của dealer 		////
		
		int option;
		do {
			cout << "1. Draw card and random replacement." << endl;
			cout << "2. Draw card and replace to get better situation." << endl;
			cout << "3. Exit." << endl;
			cout << "Choose: " << endl;
			cin >> option;
		} while (option > 3 || option < 1);

		////		 Thay thế ngẫu nhiên		////

		if (option == 1) {
			int card;
			do {
				cout << "How many more cards do you want to draw ? (<=3): ";
				cin >> card;
			} while (card > 3 || card < 1);

			int draw_card[2];
			int slect_card;

			for (int i = 0; i < card; i++) {
				////		Random lá bài thay thế		////
				slect_card = rand() % 4;
				cout << "Card number " << slect_card << " will be replaced" << endl;

				////		Bốc bài		////
				for (int l = 0; l < SUITS; l++)
					for (int k = 0; k < RANKS; k++)
						if (deck[l][k] == n * 5 + i + 1)
						{
							draw_card[0] = l;
							draw_card[1] = k;
						}
				cout << "This is the card you just drew: " << endl;
				cout << "(" << suits[draw_card[0]] << ", " << ranks[draw_card[1]] << ")" << endl;

				////		Thay thế các lá bài		////
				dealer[slect_card][0] = draw_card[0];
				dealer[slect_card][1] = draw_card[1];
			}
		

			*(hands + n - 1) = dealer;

			cout << "Dealer's card after the change is: " << endl;
			printHand(dealer, suits, ranks);
			break;
		}

		////		 Thay thế có lựa chọn		////
		if (option == 2) {
			int card1;
			do {
				cout << "How many more cards do you want to draw ? (<=3): ";
				cin >> card1;
			} while (card1 > 3 || card1 < 1);

			int draw_card1[2];
			int slect_card1;

			for (int i = 0; i < card1; i++) {
				////		Bốc bài		////
				for (int l = 0; l < SUITS; l++)
					for (int k = 0; k < RANKS; k++)
						if (deck[l][k] == n * 5 + i + 1)
						{
							draw_card1[0] = l;
							draw_card1[1] = k;
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

			*(hands + n - 1) = dealer;

			cout << "Dealer's card after the change is: " << endl;
			printHand(dealer, suits, ranks);
			break;
		}

		if (option == 3) {
			break;
		}

	case 4:
		
		rank = rankingHands(hands, n);
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

	DellocateDoublePointer(dealer, 5);
	delete[] rank;

}