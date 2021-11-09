# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

struct Node{
	struct Node *next;
	struct Node *prev;
	void *data;
};

struct List{
	struct Node *head;
	struct Node *tail;
	int size;
};

void initList(struct List *list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}


void append(struct List *list, int n, ...) {
	va_list ap;
	va_start(ap, n);
	for (int i = 0; i < n; i++) {
		void *data = va_arg(ap, void*);
		struct Node *node = malloc(sizeof(struct Node));
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
		if (list->head == NULL) {
			list->head = node;
			list->tail = node;
		} else {
			list->tail->next = node;
			node->prev = list->tail;
			list->tail = node;
		}
		list->size++;
	}
	va_end(ap);
}


void* getNFirst(struct List *list, int n) {
	if (n > list->size) {
		return NULL;
	}
	struct Node *node = list->head;
	for (int i = 0; i < n; i++) {
		node = node->next;
	}
	return node->data;
}

void* getNLast(struct List *list, int n) {
	if (n > list->size) {
		return NULL;
	}
	struct Node *node = list->tail;
	for (int i = 0; i < n; i++) {
		node = node->prev;
	}
	return node->data;
}


void push(struct List *list, void *data) {
	struct Node *node = malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	} else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	list->size++;
}