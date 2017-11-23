#include <stdbool.h>
#include <stddef.h>

#ifndef POSTGRES_CSV_LOADER_LNKLIST_H
#define POSTGRES_CSV_LOADER_LNKLIST_H

struct node {
	char* data;
	char* key;
	struct node *next;
};

extern struct node node;
extern struct node *head;
extern struct node *current;

void printList();
void insertFirst(char* key, char* data);
struct node* deleteFirst();
struct node* delete(char* key);
bool isEmpty();
int length();
struct node* reverse(struct node** head_ref);
struct node* find(char* key);

#endif //POSTGRES_CSV_LOADER_LNKLIST_H
