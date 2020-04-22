#include "19127048.h"

void GameMode()
{
	cout << "1. Single player\n";
	cout << "2. Multiplayer\n";
	cout << "3. Play with dealer\n";
	cout << "Choose: ";
}

void Levelofdifficult()
{
	cout << "1. Easy\n";
	cout << "2. Medium\n";
	cout << "3. Hard\n";
	cout << "Choose: ";
}

void SinglePlayer()
{
	cout << "1. Distribute random cards to player\n";
	cout << "2. Prints out five cards assigned to a player\n";
	cout << "3. Player can choose cards\n";
	cout << "4. Does a hand contain Four of a kind?\n";
	cout << "5. Does a hand contain Full house?\n";
	cout << "6. Does a hand contain Flush?\n";
	cout << "7. Does a hand contain Straight?\n";
	cout << "8. Does a hand contain Straight Flush?\n";
	cout << "9. Does a hand contain Three of a kind?\n";
	cout << "10. Does a hand contain Two pairs?\n";
	cout << "11. Does a hand contain Pair?\n";
	cout << "12. The value of the highest card\n";
	cout << "Choose: ";
}

void Multiplayer(int n, int s)
{
	cout << "1. Distributes cards to " << n << " players\n";
	cout << "2. Ranks players in one turn\n";
	cout << "3. Play " << s << " times and find the winner\n";
	cout << "Choose: ";
}

void DealerMenu()
{

}