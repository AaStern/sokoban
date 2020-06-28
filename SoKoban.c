#include <ncurses.h>
#include <stdlib.h>

#define POS(x, y) ((WIDTH) * (y) + (x))
#define WIDTH (map->width)
#define HEIGHT (map->height)
#define X (i % WIDTH)
#define Y (i / WIDTH)

typedef struct
{
	int width;
	int height;
	char *map;
	int x_player;
	int y_player;
}map_t;

void my_putstr(char const *str)
{
	int a = 0;

	while (str[a] != '\0') {
		my_putchar(str[a]);
		a++;
	}
}

void my_putchar(char c)
{
	write(1, &c, 1);
}

char *concat(char *recept, char *new)
{
	int i = 0;
	int j = 0;
	int len_recept = (recept) ? my_strlen(recept) : 0;
	int len_new = my_strlen(new);
	char *newstr = malloc(sizeof(*newstr) * (len_recept + len_new + 1));

	while (recept && i < len_recept) {
		newstr[i] = recept[i];
		i++;
	}
	while (j < len_new) {
		newstr[i] = new[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	free(recept);
	return (newstr);
}

void my_put_nbr(int nb)
{
	if (nb == -2147483648) {
		my_putstr("-2147483648");
		return;
	}
	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	if (nb > 9)
		my_put_nbr(nb / 10);
	my_putchar(nb % 10 + '0');
}

int my_strlen(char const *str)
{
	int a = 0;

	while (str[a] != '\0')
		a++;
	return(a);
}

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


void h_option(char *arg)
{
	if (my_strlen(arg) == 2 && arg[0] == '-' && arg[1] == 'h') {
		my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap  ");
		my_putstr("file representing the warehouse map, containing");
		my_putstr(" '#' for walls,\n'P' for the player, 'X' ");
		my_putstr("for boxes and 'O' for storage locations.\n");
	}
}

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
