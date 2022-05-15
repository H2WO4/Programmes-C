# include <stdio.h>
# include <stdlib.h>
# include "modules\h2list.h"

int main() {
	struct List *list = createList();

	list = range(1, 10);

	pop(list);

	unshift(list, 11);

	insertAt(list, -3, 98);

	printf("The value is: ");
	foreach (i, list) {
		printf("%d ", i->data);
	}

	return 0;
}