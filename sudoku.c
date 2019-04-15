#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void drawMap(int** map)
{
	int j;

	for (int i = 0 ; i < 9 ; i++)
	{
		if (!(i % 3))
		{
			printf(" --------------------\n");
		}
		for (j = 0 ; j < 3 ; j++)
			printf(" %d" , map[i][j]);

		printf(" |");
		for (j = 3 ; j < 6 ; j++)
			printf(" %d" , map[i][j]);

		printf(" |");
		for (j = 6 ; j < 9 ; j++)
			printf(" %d" , map[i][j]);

		puts("");
	}
}


int** generateMap()
{
	int** newMap = malloc(sizeof(int*) * 9);
	for (int i = 0 ; i < 9 ; i++)
		newMap[i] = malloc(sizeof(int) * 9 * 9);

	return newMap;
}


int main()
{
	int** map = generateMap();
	drawMap(map);
}
