#include <stdlib.h>
#include "proto.h"

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
