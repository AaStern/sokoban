#include <ncurses.h>
#include "proto.h"

int put_map(map_t *map)
{
	int i = 0;
	int counter = 0;

	while (i <= WIDTH * HEIGHT) {
		move(Y, X);
		if (map->map[i] == 'O')
			counter++;
		printw(&map->map[i]);
		i++;
	}
	move(map->y_player, map->x_player);
	printw("P");
	if (counter == 0)
		return (1);
	return (0);
}
