# ifndef DLL_H
# define DLL_H

# define foreach(n, l) for(struct Node* n = l.head; n != NULL; n = n->next)

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

void initList(struct List*);

void append(struct List*, int, ...);

void* getNFirst(struct List*, int);
void* getNLast(struct List*, int);

void push(struct List*, void*);

# endif