#include <stdbool.h>
#include "game.h"

bool solve_game(Game game)
{
	int** table  = game.table;
	int** answer = game.answer;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			printf("%d" , table[i][j]);
		}
		puts("");
	}

	return true; //
}
