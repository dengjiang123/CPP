#include<iostream>
#include"tabtenn0.h"
int main() {
	using std::cout;
	TableTennisPlayer player1("Chuck", "Blizzard", true);
	RatedPlayer player2(1140, "Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
		cout << " :Has a table.\n";
	else
		cout << " :Has't a table.\n";

	player2.Name();
	if (player2.HasTable())
		cout << " :Has a table.\n";
	else
		cout << " :Has't a table.\n";
	cout << player2.Rating() << std::endl;

	RatedPlayer player(1212, player1);
	player.Name();
	cout << player.Rating() << std::endl;

	TableTennisPlayer player3;
	player3 = player2;
	player3.Name();
	return 0;
}