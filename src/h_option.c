#include "proto.h"

void h_option(char *arg)
{
	if (my_strlen(arg) == 2 && arg[0] == '-' && arg[1] == 'h') {
		my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap  ");
		my_putstr("file representing the warehouse map, containing");
		my_putstr(" '#' for walls,\n'P' for the player, 'X' ");
		my_putstr("for boxes and 'O' for storage locations.\n");
	}
}
