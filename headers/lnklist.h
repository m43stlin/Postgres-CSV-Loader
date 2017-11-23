#include <stdbool.h>
#include <stddef.h>

#ifndef POSTGRES_CSV_LOADER_LNKLIST_H
#define POSTGRES_CSV_LOADER_LNKLIST_H

struct node *head;

void printList();
void insertFirst(char* key, char* data);
struct node* deleteFirst();
struct node* delete(char* key);
bool isEmpty();
int length();
struct node* find(char* key);
struct node*(struct node** head_ref);

#endif //POSTGRES_CSV_LOADER_LNKLIST_H
