#pragma once

#include <ncurses.h>
#include "struct.h"

#define POS(x, y) ((WIDTH) * (y) + (x))
#define WIDTH (map->width)
#define HEIGHT (map->height)
#define X (i % WIDTH)
#define Y (i / WIDTH)

void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);

void parsing(char *pathname, map_t *map);
void h_option(char *arg);
char *concat(char *recept, char *new);
void move_player(map_t *map, int keyboard, char *arg);
int put_map(map_t *map);
void move_left(map_t *map, int *x, int *y);
void move_right(map_t *map, int *x, int *y);
void move_up(map_t *map, int *x, int *y);
void move_down(map_t *map, int *x, int *y);
void my_free(map_t *map);
