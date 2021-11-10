# include <stdio.h>
# include <stdlib.h>
# include "modules\h2list.h"

int main() {
	struct List *list = malloc(sizeof(struct List));
	initList(list);

	copyList(range(0, 10), list);

	printf("The value is: ");
	foreach (n, list) {
		printf("%d ", n->data);
	}

	return 0;
}