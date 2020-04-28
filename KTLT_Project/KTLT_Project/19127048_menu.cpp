#include "19127048.h"

void GameModeMenu()
{
	cout << "1. Single player\n";
	cout << "2. Multiplayer\n";
	cout << "3. Play with dealer\n";
	cout << "4. Exit\n";
	cout << "Choose: ";
}

void LevelofdifficultMenu()
{
	cout << "1. Easy\n";
	cout << "2. Medium\n";
	cout << "3. Hard\n";
	cout << "Choose: ";
}

void SinglePlayerMenu()
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
	cout << "13. Exit\n";
	cout << "Choose: ";
}

void MultiplayerMenu(int n)
{
	cout << "1. Distributes cards to " << n << " players\n";
	cout << "2. The hand-ranking of five cards\n";
	cout << "3. Ranking players in one turn\n";
	cout << "4. Play [times] and find the winner\n";
	cout << "5. Exit\n";
	cout << "Choose: ";
}

void DealerMenu()
{
	cout << "1. Check player score\n";
	cout << "2. Check dealer score\n";
	cout << "3. Dealer, do you want to draw?\n";
	cout << "4. Ranking players and dealer\n";
	cout << "5. Exit\n";
	cout << "Choose: ";
}