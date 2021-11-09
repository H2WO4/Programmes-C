# include <stdlib.h>

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
	/* Initialize the list to an empty list */

	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}


void push(struct List *list, void *data) {
	/* Add a new node to the end of the list */

	// Create a new node, and set its data
	struct Node *node = malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	// If the list is empty, set the head and tail to the new node
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	}
	// Else, set the new node's next to the current tail, and the tail's prev to the new node
	else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	// Increment the size of the list
	list->size++;
}

void* pop(struct List *list) {
	/* Remove the last node from the list, and return it */

	// If the list is empty, return NULL
	if (list->size == 0) {
		return NULL;
	}
	// Else, create a pointer to the tail of the list
	struct Node *node = list->tail;

	// Change the tail to the previous node
	list->tail = node->prev;
	list->tail->next = NULL;

	// Decrement the size of the list
	list->size--;

	// Return the data of the node
	return node->data;
}


void unshift(struct List *list, void *data) {
	/* Add a new node to the beginning of the list */

	// Create a new node, and set its data
	struct Node *node = malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	// If the list is empty, set the head and tail to the new node
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
	}
	// Else, set the new node's prev to the current head, and the head's next to the new node
	else {
		list->head->prev = node;
		node->next = list->head;
		list->head = node;
	}
	// Increment the size of the list
	list->size++;
}

void* shift(struct List *list) {
	/* Remove the first node from the list, and return it */

	// If the list is empty, return NULL
	if (list->size == 0) {
		return NULL;
	}
	// Else, create a pointer to the head of the list
	struct Node *node = list->head;

	// Change the head to the next node
	list->head = node->next;
	list->head->prev = NULL;

	// Decrement the size of the list
	list->size--;

	// Return the data of the node
	return node->data;
}


void insertAt(struct List *list, void *data, int index) {
	/* Insert a new node at the specified index */

	// If the index is out of bounds, return NULL
	if (index < -list->size || index > list->size-1) {
		return;
	}

	// Create a new node, and set its data
	struct Node *node = malloc(sizeof(struct Node));
	node->data = data;

	// If the index is positive, start from the head
	if (index >= 0) {
		// Create a pointer to the node at the specified index
		struct Node *current = list->head;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}

		// Set the new node's data and next
		node->data = data;
		node->next = current->next;
		node->prev = current;

		// Set the previous node's next to the new node
		current->next->prev = node;
		current->next = node;
	}
	// Else, start from the tail
	else {
		// Create a pointer to the node at the specified index
		struct Node *current = list->tail;
		for (int i = 0; i > index + 1; i--) {
			current = current->prev;
		}

		// Set the new node's data and prev
		node->data = data;
		node->prev = current->prev;
		node->next = current;

		// Set the previous node's next to the new node
		current->prev->next = node;
		current->prev = node;
	}
	// Increment the size of the list
	list->size++;
}

void removeAt(struct List *list, int index) {
	/* Remove the node at the specified index */

	// If the index is out of bounds, return NULL
	if (index < -list->size || index > list->size-1) {
		return;
	}

	// If the index is positive, start from the head
	if (index >= 0) {
		// Create a pointer to the node at the specified index
		struct Node *current = list->head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		// Set the previous node's next to the next node
		current->prev->next = current->next;

		// Set the next node's prev to the previous node
		if (current->next != NULL) {
			current->next->prev = current->prev;
		}
	}
	// Else, start from the tail
	else {
		// Create a pointer to the node at the specified index
		struct Node *current = list->tail;
		for (int i = 0; i > index; i--) {
			current = current->prev;
		}

		// Set the previous node's next to the next node
		current->prev->next = current->next;

		// Set the next node's prev to the previous node
		if (current->next != NULL) {
			current->next->prev = current->prev;
		}
	}
	// Decrement the size of the list
	list->size--;
}

void* peekAt(struct List *list, int index) {
	/* Return the data of the node at the specified index */

	// If the index is out of bounds, return NULL
	if (index < -list->size || index > list->size-1) {
		return NULL;
	}

	// If the index is positive, start from the head
	if (index >= 0) {
		// Create a pointer to the node at the specified index
		struct Node *current = list->head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}

		// Return the data of the node
		return current->data;
	}
	// Else, start from the tail
	else {
		// Create a pointer to the node at the specified index
		struct Node *current = list->tail;
		for (int i = 0; i > index; i--) {
			current = current->prev;
		}

		// Return the data of the node
		return current->data;
	}
}
