# ifndef DLL_H
# define DLL_H

# define foreach(n, l) for(struct Node* n = l->head; n != NULL; n = n->next)

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

void push(struct List*, void* obj);
void* pop(struct List*);

void* unshift(struct List*, void* obj);
void shift(struct List*);

void insertAt(struct List*, int index, void* obj);
void removeAt(struct List*, int index);
void* peekAt(struct List*, int index);

void emptyList(struct List*);
void copyList(struct List* src, struct List* dest);
void strToList(struct List* dest, char* str);
void concatList(struct List* src, struct List* dest);

struct List* range(int start, int end);

# endif