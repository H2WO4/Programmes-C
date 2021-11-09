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

void push(struct List*, void*);
void* pop(struct List*);

void shift(struct List*, void*);
void* unshift(struct List*, void*);

void insertAt(struct List*, void*, int);
void removeAt(struct List*, int);
void* peekAt(struct List*, int);

# endif