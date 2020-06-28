#include <stdlib.h>
#include "proto.h"

FILE *fopen_file(char *pathname)
{
	FILE *file;

	h_option(pathname);
	if ((file = fopen(pathname, "r")) == NULL)
		exit(84);
	return (file);
}

void check_bad_map(map_t *map, char *characters)
{
	int i = 0;
	int j = 0;

	while (map->map[i] != '\0') {
		j = 0;
		if (map->map[i] == 'P') {
			map->x_player = X;
			map->y_player = Y;
			map->map[i] = ' ';
		}
		while (characters[j] != map->map[i])
			(j == i ? exit(84) : j++);
		i++;
	}
}

void parsing(char *pathname, map_t *map)
{
	int height = 0;
	size_t len = 0;
	char *line = NULL;
	FILE *file = fopen_file(pathname);

	if (map == NULL)
		exit(84);
	map->map = NULL;
	map->width = getline(&line, &len, file);
	fclose(file);
	file = fopen(pathname, "r");
	while (getline(&line, &len, file) != -1) {
		map->map = concat(map->map, line);
		check_bad_map(map, "# \nOPX");
		height++;
	}
	map->height = height;
	free(line);
	fclose(file);
}
