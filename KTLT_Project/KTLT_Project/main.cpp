#include "19127048.h"
#include "19127493.h"

int main()
{
	int array[5] = { 0 };
	int deck[SUITS][RANKS] = { 0 };
	const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };


	////		FOR MENU		////
	int Choose;
	int ChooseofGameMode;
	int ChooseofSinglePlayer;
	int ChooseofMultiPlayer;
	int ChooseofDealer;
	int ChooseofDealervsPlayer;
	int ChooseofLevel;


	////		FOR MULTIPLAYER		////
	int NumberofPlayers;
	int times;

	////		FOR LEVELs		////
	int player_cards = 0;
	int dealer_cards = 0;
	int** dealer;
	int** player;

	////		POINTER		////
	int** hand = nullptr;
	int*** hands = nullptr;
	
	
	/*int *a;
	a = new int[3];
	a = evaluateHands(3, 3);
	for (int i = 0; i < 3; i++)
		cout << a[i] << endl;*/


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	

	srand(time(NULL));


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	shuffleCards(deck);

	GameModeMenu();
	cin >> ChooseofGameMode;
	do
	{
		if (ChooseofGameMode < 1 || ChooseofGameMode > 5)
		{
			cout << "Something wrong, try again\n";
			GameModeMenu();
			cin >> ChooseofGameMode;
		}
	} while (ChooseofGameMode < 1 || ChooseofGameMode > 5);


	////		GAME MODE		////
	while (ChooseofGameMode != 5)
	{
		switch (ChooseofGameMode)
		{

			////		SINGLE PLAYER MODE			////
		case 1:

			system("cls");
			SinglePlayerMenu();
			cin >> ChooseofSinglePlayer;


			////		KIỂM TRA LỖI NGƯỜI DÙNG		////
			do
			{
				if (ChooseofSinglePlayer < 1 || ChooseofSinglePlayer > 13)
				{
					system("cls");
					cout << "Something wrong, try again\n";
					SinglePlayerMenu();
					cin >> ChooseofSinglePlayer;
				}
			} while (ChooseofSinglePlayer < 1 || ChooseofSinglePlayer > 13);


			////		KIỂM TRA LỖI NGƯỜI DÙNG		////
			while (true)
			{
				if (ChooseofSinglePlayer == 1 || ChooseofSinglePlayer == 3 || ChooseofSinglePlayer == 13)
				{
					break;
				}
				else
				{
					system("cls");
					cout << "Distribute cards to player before play\n";
					SinglePlayerMenu();
					cin >> ChooseofSinglePlayer;
				}
			}


			////		OPTION		////
			while (ChooseofSinglePlayer != 13)
			{
				SinglePlayer(deck, array, suits, ranks, hand, ChooseofSinglePlayer);


				system("pause");
				system("cls");


				cout << "Card on hand:\n";
				printHand(hand, suits, ranks);


				SinglePlayerMenu();
				cin >> ChooseofSinglePlayer;
			}

			DellocateDoublePointer(hand, 5);


			break;

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			////		MULTIPLAYER MODE		////
		case 2:

			system("cls");
			cout << "How many players you want to play with: ";
			cin >> NumberofPlayers;
			do
			{
				if (NumberofPlayers < 2 || NumberofPlayers > 10)
				{
					system("cls");
					cout << "Number of players must greater than 2 and smaller than 10, try again: ";
					cin >> NumberofPlayers;
				}
			} while (NumberofPlayers < 2  || NumberofPlayers > 10);


			MultiplayerMenu(NumberofPlayers);
			cin >> ChooseofMultiPlayer;


			////		KIỂM TRA LỖI NGƯỜI DÙNG		////
			do
			{
				if (ChooseofMultiPlayer < 1 || ChooseofMultiPlayer > 5)
				{
					system("cls");
					cout << "Something wrong, try again\n";
					MultiplayerMenu(NumberofPlayers);
					cin >> ChooseofMultiPlayer;
				}
			} while (ChooseofMultiPlayer < 1 || ChooseofMultiPlayer > 5);


			////		KIỂM TRA LỖI NGƯỜI DÙNG		////
			while (true)
			{
				if (ChooseofMultiPlayer == 1 || ChooseofMultiPlayer == 5)
				{
					break;
				}
				else
				{
					system("cls");
					cout << "Distribute cards to player before play\n";
					MultiplayerMenu(NumberofPlayers);
					cin >> ChooseofMultiPlayer;
				}
			}


			////		OPTION		////
			while (ChooseofMultiPlayer != 5)
			{
				MultiPlayer(deck, hands, NumberofPlayers, suits, ranks, ChooseofMultiPlayer);


				system("pause");
				system("cls");


				
				////		In các là bài của từng người chơi		////
				for (int i = 0; i < NumberofPlayers; i++) {
					cout << "Player " << i << "'s card is: " << endl;
					printHand(*(hands + i), suits, ranks);
				}

				
				MultiplayerMenu(NumberofPlayers);
				cin >> ChooseofMultiPlayer;
			}


			DellocateTriplePointer(hands, NumberofPlayers, 5);


			break;

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			////		DEALER MODE			////
		case 3:

			system("cls");
			cout << "How many players (include dealer) you want to play with: ";
			cin >> NumberofPlayers;
			////		KIỂM TRA LỖI NGƯỜI DÙNG		////s
			do
			{
				if (NumberofPlayers < 2 || NumberofPlayers > 10)
				{
					system("cls");
					cout << "Number of players (include dealer) must greater than 2 and smaller than 10, try again: ";
					cin >> NumberofPlayers;
				}
			} while (NumberofPlayers < 2 || NumberofPlayers > 10);


			DealerMenu();
			cin >> ChooseofDealer;


			////		KIỂM TRA LỖI NGƯỜI DÙNG		////
			do
			{
				if (ChooseofDealer < 1 || ChooseofDealer > 5)
				{
					system("cls");
					cout << "Something wrong, try again\n";
					DealerMenu();
					cin >> ChooseofDealer;
				}
			} while (ChooseofDealer < 1 || ChooseofDealer > 5);


			


			////		OPTION		////
			while (ChooseofDealer != 5)
			{
				Poker_Game_For_Dealer(deck, hands, NumberofPlayers, ChooseofDealer, suits, ranks);


				system("pause");
				system("cls");


				DealerMenu();
				cin >> ChooseofDealer;
			}


			DellocateTriplePointer(hands, NumberofPlayers, 5);


			break;

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

			////		LEVEL		////
		case 4:

			NumberofPlayers = 2;	//	dùng để xóa con trỏ cấp 3 hands


			system("cls");
			LevelofdifficultMenu();
			cin >> ChooseofLevel;

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


			////		KIỂM TRA LỖI NGƯỜI DÙNG		////
			do
			{
				if (ChooseofLevel < 1 || ChooseofLevel > 3)
				{
					system("cls");
					cout << "Something wrong, try again\n";
					LevelofdifficultMenu();
					cin >> ChooseofLevel;
				}
			} while (ChooseofLevel < 1 || ChooseofLevel > 3);


			////		CHỌN MỨC ĐỘ KHÓ			////
			while (ChooseofLevel != 4)
			{
				switch (ChooseofLevel)	// chọn mức độ
				{
					////		EASY		////
				case 1:
					system("cls");
					cout << "Easy\n";

					shuffleCards(deck);

					hands = dealingForHands(deck, 2);
					player = *hands;
					dealer = *(hands + 1);

					player_cards = 0;
					dealer_cards = 0;

					DealervsPlayerMenu();
					cin >> Choose;
					isChooseValid(Choose);


					while (Choose != 4)
					{
						*hands = player;
						*(hands + 1) = dealer;

						Easy_Game(deck, hands, player, dealer, player_cards, dealer_cards, Choose, suits, ranks);


						system("pause");
						system("cls");


						DealervsPlayerMenu();
						cin >> Choose;
					}


					DellocateTriplePointer(hands, NumberofPlayers, 5);


					break;

					////		MEDIUM		////
				case 2:
					system("cls");
					cout << "Medium\n";

					shuffleCards(deck);

					hands = dealingForHands(deck, 2);
					player = *hands;
					dealer = *(hands + 1);

					player_cards = 0;
					dealer_cards = 0;

					DealervsPlayerMenu();
					cin >> Choose;
					isChooseValid(Choose);


					while (Choose != 4)
					{
						*hands = player;
						*(hands + 1) = dealer;

						Medium_Game(deck, hands, player, dealer, player_cards, dealer_cards, Choose, suits, ranks);


						system("pause");
						system("cls");


						DealervsPlayerMenu();
						cin >> Choose;
					}


					DellocateTriplePointer(hands, NumberofPlayers, 5);


					break;

					////		HARD		////
				case 3:
					system("cls");
					cout << "Hard\n";

					shuffleCards(deck);

					hands = dealingForHands(deck, 2);
					player = *hands;
					dealer = *(hands + 1);

					player_cards = 0;
					dealer_cards = 0;

					DealervsPlayerMenu();
					cin >> Choose;
					isChooseValid(Choose);


					while (Choose != 4)
					{
						*hands = player;
						*(hands + 1) = dealer;

						Hard_Game(deck, hands, player, dealer, player_cards, dealer_cards, Choose, suits, ranks);


						system("pause");
						system("cls");


						cout << "Hard\n";
						DealervsPlayerMenu();
						cin >> Choose;
					}
					

					DellocateTriplePointer(hands, NumberofPlayers, 5);


					break;
				default:
					cout << "Something wrong, try again\n";
					break;
				}


				system("pause");
				system("cls");


				LevelofdifficultMenu();
				cin >> ChooseofLevel;
			}

			DellocateDoublePointer(player, 5);
			DellocateDoublePointer(dealer, 5);
			break;
		}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		system("pause");
		system("cls");


		GameModeMenu();
		cin >> ChooseofGameMode;
	}
	

	system("pause");
	return 0;
}
