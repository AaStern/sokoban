#include <ncurses.h>
#include "proto.h"

void move_player(map_t *map, int keyboard, char *arg)
{
	if (keyboard == KEY_LEFT)
		move_left(map, &map->x_player, &map->y_player);
	if (keyboard == KEY_RIGHT)
		move_right(map, &map->x_player, &map->y_player);
	if (keyboard == KEY_UP)
		move_up(map, &map->x_player, &map->y_player);
	if (keyboard == KEY_DOWN)
		move_down(map, &map->x_player, &map->y_player);
	if (keyboard == ' ')
		parsing(arg, map);
}
