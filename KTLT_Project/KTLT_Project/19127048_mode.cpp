#include "19127048.h"
#include "19127493.h"

void SinglePlayer(int deck[SUITS][RANKS], int array[], const char* suits[], const char* ranks[], int**& hand, int ChooseofSinglePlayer)
{
	switch (ChooseofSinglePlayer)
	{

	case 1:

		hand = dealingForHand(deck);
		break;

	case 2:

		printHand(hand, suits, ranks);
		break;

	case 3:

		hand = createHandTest(deck, array);
		break;

	case 4:

		if (isFourOfAKind(hand))
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
		break;

	case 5:

		if (isFullHouse(hand))
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
		break;

	case 6:

		if (isFlush(hand))
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
		break;

	case 7:

		if (isStraight(hand))
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
		break;

	case 8:

		if (isStraightFlush(hand))
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
		break;

	case 9:

		if (isThreeOfAKind(hand))
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
		break;

	case 10:

		if (isTwoPairs(hand))
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
		break;

	case 11:

		if (isPair(hand))
		{
			cout << "Yes\n";
		}
		else
		{
			cout << "No\n";
		}
		break;

	case 12:

		cout << " The value of the highest card: " << getHighestCard(hand) << endl;
		break;

	default:
		cout << "Something wrong, try again: ";
		break;
	}
}

void MultiPlayer(int deck[SUITS][RANKS], int***& hands, int n, int ChooseofMultiPlayer)
{

	int* rank = nullptr;
	int player;
	int times;
	switch (ChooseofMultiPlayer)
	{

	case 1:

		hands = dealingForHands(deck, n);
		break;

	case 2:

		cout << "Which player you want to check: ";
		cin >> player;
		do
		{
			if (player < 0 || player >= n)
			{
				cout << "Something wrong, player is from 0 to " << n - 1 << " try again: ";
				cin >> player;
			}
			
		} while (player < 0 || player >= n);
		getStatusOfHand(*(hands) + player);
		break;

	case 3:

		rank = rankingHands(hands, n);;
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

	case 4:

		cout << "How many times you want to play: ";
		cin >> times;
		rank = evaluateHands(n, times);
		

		cout << "Rank:\t";
		for (int j = 1; j <= n; j++)
		{
			cout << j << "\t";
		}
		cout << "\nPlayer:\t";
		for (int j = 0; j < n; j++)
		{
			cout << rank[j] << "\t";
		}
		break;
	default:
		cout << "Something wrong, try again:\n";
		break;
	}


	delete[] rank;
}