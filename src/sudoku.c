#include <stdio.h>
#include "game.h"
#include "solve.h"

int main()
{
	FILE* file = fopen("tables.csv" , "r");
	Game game;

	int game_number = 1;
	while (true)
	{
		game = load_game(file);

		if (!game.is_loaded)
			break;

		solve_game(game);

		if (check_game_answer(game) == true)
		{
			printf("%d solved!!\n" , game_number);
		}
		else
		{
			printf("ERROR! %d\n" , game_number);
			return 1;
		}

		game_number++;
	}
}
