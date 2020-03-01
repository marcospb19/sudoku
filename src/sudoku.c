#include <stdio.h>
#include "game.h"

int main()
{
	Game game = load_game_from_file("tables.csv");

	show_game_table(game);
}
