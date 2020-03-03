#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef struct game_t
{
	bool is_loaded;
	int** table;
	int** answer;
} Game;

void clear_game(Game game);

Game alloc_new_game();

Game load_game_from_file(char path[]);

Game load_game(FILE* file);

void show_game_table(Game game);

bool check_game_answer(Game game);
