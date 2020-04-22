#include "19127048.h"
#include "19127493.h"

int main()
{
	int array[5] = { 0 };
	int deck[SUITS][RANKS] = { 0 };
	const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };


	int ChooseofGameMode;
	int ChooseofSinglePlayer;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	shuffleCards(deck);

	//GameMode();
	//cin >> ChooseofGameMode;
	//do
	//{
	//	if (ChooseofGameMode < 1 || ChooseofGameMode > 3)
	//	{
	//		cout << "Something wrong, try again\n";
	//		GameMode();
	//		cin >> ChooseofGameMode;
	//	}
	//} while (ChooseofGameMode < 1 || ChooseofGameMode > 3);


	//switch (ChooseofGameMode)
	//{
	//case 1:		// single player

	//	SinglePlayer();
	//	cin >> ChooseofSinglePlayer;
	//	do
	//	{
	//		if (ChooseofSinglePlayer < 1 || ChooseofSinglePlayer > 12)
	//		{
	//			cout << "Something wrong, try again\n";
	//			SinglePlayer();
	//			cin >> ChooseofSinglePlayer;
	//		}
	//	} while (ChooseofSinglePlayer < 1 || ChooseofSinglePlayer > 12);


	//	switch (ChooseofSinglePlayer)
	//	{
	//	case 1:

	//		int** hand = dealingForHand(deck);

	//		break;
	//	case 2:

	//		printHand(hand, suits, ranks);

	//		break;
	//	case 3:

	//		hand = createHandTest(deck, array);

	//		break;
	//	case 4:

	//		if (isFourOfAKind(hand))
	//		{
	//			cout << "Yes\n";
	//		}
	//		else
	//		{
	//			cout << "No\n";
	//		}

	//		break;
	//	default:
	//		break;
	//	}

	//	break;
	//default:
	//	break;
	//}
	

	system("pause");
	return 0;
}
