# include <stdio.h>
# include "modules\h2list.h"

int main() {
	struct List list;
	initList(&list);

	for (int i = 0; i < 5; i++) {
		push(&list, i);
	}

	foreach (n, list) {
		printf("The value is: %d\n", n->data);
	}

	printf("\nSupressing a value ...\n");

	removeAt(&list, 3);

	foreach (n, list) {
		printf("The value is: %d\n", n->data);
	}

	return 0;
}