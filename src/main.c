#include <ncurses.h>
#include <stdlib.h>
#include "proto.h"

int main(int argc, char **argv)
{
	int keyboard = 0;
	SCREEN *window;
	map_t map;

	if (argc != 2)
		return (84);
	parsing(argv[1], &map);
	window = newterm(NULL, stderr, stdin);
	curs_set(0);
	keypad(stdscr, TRUE);
	while (keyboard != '\e') {
		move_player(&map, keyboard, argv[1]);
		if (put_map(&map))
			break;
		keyboard = getch();
	}
	endwin();
	delscreen(window);
	free(map.map);
	return (0);
}
