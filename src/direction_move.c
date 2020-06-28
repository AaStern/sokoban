#include "proto.h"

void move_left(map_t *map, int *x, int *y)
{
	int pos_left = WIDTH * *y + (*x - 1);
	int pos_2left = WIDTH * *y + (*x - 2);

	if (map->map[pos_left] == 'X' && map->map[pos_2left] == ' ') {
		map->map[pos_left] = ' ';
		map->map[pos_2left] = 'X';
		(*x)--;
	}
	else if (map->map[pos_left] == 'X' && map->map[pos_2left] == 'O') {
		map->map[pos_left] = ' ';
		map->map[pos_2left] = 'X';
		(*x)--;
	}
	else if (map->map[pos_left] == ' ' || map->map[pos_left] == 'O')
		(*x)--;
}

void move_right(map_t *map, int *x, int *y)
{
	int pos_right = WIDTH * *y + (*x + 1);
	int pos_2right = WIDTH * *y + (*x + 2);

	if (map->map[pos_right] == 'X' && map->map[pos_2right] == ' ') {
		map->map[pos_right] = ' ';
		map->map[pos_2right] = 'X';
		(*x)++;
	}
	else if (map->map[pos_right] == 'X' && map->map[pos_2right] == 'O') {
		map->map[pos_right] = ' ';
		map->map[pos_2right] = 'X';
		(*x)++;
	}
	else if (map->map[pos_right] == ' ' || map->map[pos_right] == 'O')
		(*x)++;
}

void move_up(map_t *map, int *x, int *y)
{
	int pos_up = WIDTH * (*y - 1) + *x;
	int pos_2up = WIDTH * (*y - 2) + *x;

	if (map->map[pos_up] == 'X' && map->map[pos_2up] == ' ') {
		map->map[pos_up] = ' ';
		map->map[pos_2up] = 'X';
		(*y)--;
	}
	else if (map->map[pos_up] == 'X' && map->map[pos_2up] == 'O') {
		map->map[pos_up] = ' ';
		map->map[pos_2up] = 'X';
		(*y)--;
	}
	else if (map->map[pos_up] == ' ' || map->map[pos_up] == 'O')
		(*y)--;
}

void move_down(map_t *map, int *x, int *y)
{
	int pos_down = WIDTH * (*y + 1) + *x;
	int pos_2down = WIDTH * (*y + 2) + *x;

	if (map->map[pos_down] == 'X' && map->map[pos_2down] == ' ') {
		map->map[pos_down] = ' ';
		map->map[pos_2down] = 'X';
		(*y)++;
	}
	else if (map->map[pos_down] == 'X' && map->map[pos_2down] == 'O') {
		map->map[pos_down] = ' ';
		map->map[pos_2down] = 'X';
		(*y)++;
	}
	else if (map->map[pos_down] == ' ' || map->map[pos_down] == 'O')
		(*y)++;
}
