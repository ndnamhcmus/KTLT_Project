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

void MultiPlayer(int deck[SUITS][RANKS], int ChooseofMultiPlayer)
{
	switch (ChooseofMultiPlayer)
	{

	case 1:

		/*dealingForHands(deck)*/
	default:
		break;
	}
}
