#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "game.h"

void free_game(Game game)
{
	free(game.table);
	free(game.answer);
}

Game alloc_new_game()
{
	Game game;
	game.table = malloc(sizeof(int*[9]));
	game.answer = malloc(sizeof(int*[9]));

	for (int i = 0; i < 9; ++i)
	{
		game.table[i] = malloc(sizeof(int[9]));
		game.answer[i] = malloc(sizeof(int[9]));
	}

	return game;
}

Game load_game(FILE* file)
{
	Game game = alloc_new_game();
	game.is_loaded = false;

	char c;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (fscanf(file , "%c" , &c) == EOF)
				return game;

			game.table[i][j] = c - '0';
		}
	}

	fscanf(file , ",");
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			fscanf(file , "%c" , &c);
			game.answer[i][j] = c - '0';
		}
	}
	fscanf(file , "\n"); // Skips blank line in file stream

	game.is_loaded = true;
	return game;
}

Game load_game_from_file(char path[])
{
	FILE* file = fopen(path , "r");
	if (!file)
	{
		fprintf(stderr , "Error opening the file \"%s\"" , path);
		exit(1);
	}
	return load_game(file);
}

void show_game_table(Game game)
{
	for (int i = 0; i < 9; ++i)
	{
		if (i == 3 || i == 6)
			puts("           ");

		printf(" ");

		for (int j = 0; j < 9; ++j)
		{
			if (j == 3 || j == 6)
				printf(" ");

			printf("%d" , game.table[i][j]);
		}
		puts("");
	}
}

bool check_game_answer(Game game)
{
	bool check_passed = true;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (game.answer[i][j] != game.table[i][j])
			{
				check_passed = false;
				break;
			}
		}
	}
	return check_passed;
}
