# include <stdio.h>
# include "modules\h2list.h"

int main() {
	struct List list;
	void* a;
	initList(&list);

	append(&list, 3, 1, 2, 3);

	push(&list, a = 4);

	foreach (n, list) {
		printf("The value is: %d\n", n->data);
	}

	return 0;
}