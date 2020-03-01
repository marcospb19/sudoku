#include <stdlib.h>
#include <stdio.h>
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

	char c;
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			fscanf(file , "%c" , &c);
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
	return game;
}

Game load_game_from_file(char path[])
{
	FILE* file = fopen(path , "r");
	if (!file)
	{
		fprintf(stderr , "Error opening the file: %s" , path);
		exit(1);
	}
	return load_game(file);
}

void show_game_table(Game game)
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			printf("%d" , game.table[i][j]);
		}
		puts("");
	}
}
