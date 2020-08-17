#include "19127048.h"
#include "19127493.h"

const int n = 2;

void Poker_Game(int deck[SUITS][RANKS], int***& hands, int**& player, int**& dealer, int& player_cards, int& dealer_cards, int ChooseofPokerGame, const char* suits[], const char* ranks[], string check) {

	
	////		In các là bài của người chơi và Dealer		////
	cout << "Player's card is: " << endl;
	printHand(player, suits, ranks);
	cout << "Dealer's card is: " << endl;
	printHand(dealer, suits, ranks);


	int* rank = nullptr;
	int times;
	int card;

	switch (ChooseofPokerGame)
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
					bool is_found = false;
					for (int l = 0; l < SUITS; l++)
						for (int k = 0; k < RANKS; k++) {
							if (deck[l][k] == n * 5 + card)
							{
								is_found = true;
								draw_card[0] = l;
								draw_card[1] = k;
								card++;
								player_cards++;
								break;
							}
							if (is_found)
							{
								break;
							}
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
					bool is_found1 = false;
					for (int l = 0; l < SUITS; l++)
						for (int k = 0; k < RANKS; k++) {
							if (deck[l][k] == n * 5 + card)
							{
								is_found1 = true;
								draw_card1[0] = l;
								draw_card1[1] = k;
								card++;
								dealer_cards++;
								break;
							}
							if (is_found1)
							{
								break;
							}
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
		}

		cout << "Player's card after the change is: " << endl;
		printHand(player, suits, ranks);
		cout << "Dealer's card after the change is: " << endl;
		printHand(dealer, suits, ranks);
		break;

	case 3:

		rank = NEW_rankingHands(hands, n, player_cards, dealer_cards, check);
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

	
	delete[] rank;
}