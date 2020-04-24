#include "19127048.h"
#include "19127493.h"

int main()
{
	int array[5] = { 0 };
	int deck[SUITS][RANKS] = { 0 };
	const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };


	////		FOR MENU		////
	int ChooseofGameMode;
	int ChooseofSinglePlayer;
	int ChooseofMultiPlayer;


	////		FOR MULTIPLAYER		////
	int NumberofPlayers;
	int times;


	////		POINTER		////
	int* rank = nullptr;
	int** hand = nullptr;
	int*** hands = nullptr;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	shuffleCards(deck);
	
	GameModeMenu();
	cin >> ChooseofGameMode;
	do
	{
		if (ChooseofGameMode < 1 || ChooseofGameMode > 4)
		{
			cout << "Something wrong, try again\n";
			GameModeMenu();
			cin >> ChooseofGameMode;
		}
	} while (ChooseofGameMode < 1 || ChooseofGameMode > 4);


	////		GAME MODE		////
	while (ChooseofGameMode != 4)
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


				SinglePlayerMenu();
				cin >> ChooseofSinglePlayer;
			}
			break;

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
				if (ChooseofMultiPlayer == 1 || ChooseofMultiPlayer == 3 || ChooseofMultiPlayer == 13)
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
				MultiPlayer(deck, rank, hands, NumberofPlayers, ChooseofMultiPlayer);


				system("pause");
				system("cls");


				MultiplayerMenu(NumberofPlayers);
				cin >> ChooseofMultiPlayer;
			}
			break;

			////		MULTIPLAYER MODE		////





		}
		

		//////////////////////////////////////////////////////////////////////////////////////////////////////


		system("pause");
		system("cls");


		GameModeMenu();
		cin >> ChooseofGameMode;
	}
	
	


	/*printMatrix(deck);
	int*** test = dealingForHands(deck, 5);
	rankingHands(test, 5);*/


	int *test;
	test = evaluateHands(5, 1);
	int* array1;
	array1 = evaluateHands(5, 1);
	for (int i = 0; i < 5; i++)
		cout << *(array1 + i) << endl;


	if (rank)
	{
		delete[] rank;
	}
	if (hand)
	{
		DellocateDoublePointer(hand, 5);
	}
	system("pause");
	return 0;
}
