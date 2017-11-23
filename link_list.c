#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

/*
 * functions for the link list which will store the data from the rows
 * of the csv list/file based on the keys defined by getColNames().
 */

struct node {
	char* data;
	char* key;
	struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;
struct node *del_search = NULL;

/*
 * Finding a link with a given key.
 */
struct node* find(char* key) {
	/*
	 * Start from the beginning.
	 */
	struct node* current = head;

	/*
	 * Check if empty.
	 */
	if (head == NULL) {
		return NULL;
	}

	/*
	 * Check if we are at the last node if not
	 * proceed.
	 */
	while (current -> key != key) {
		if (current -> next == NULL) {
			return NULL;
		} else {
			current = current -> next;
		}
	}

	return current;
}


/*
 * Reverse the FIFO as a user would expect.
 */
struct node* reverse(struct node** head_ref) {
	struct node* prev	 = NULL;
	struct node* current = *head_ref;
	struct node* next;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head_ref = prev;

	return *head_ref;
}

/*
 * Display.
 */
void printList() {
	struct node *ptr = reverse(&head);
	printf("\n[ ");

	while(ptr != NULL) {
		printf("(%s,%s) ",ptr->key, ptr->data);
		ptr = ptr->next;
	}

	printf(" ]");


}

/*
 * Insert link at the first location.
 */
void insertFirst(char* key, char* data) {

	struct node *link = (struct node *) malloc(sizeof(struct node));
	link->key = key;
	link->data = data;

	/*
	 * Pointing
	 */
	link->next = head;
	head = link;

}

/*
 * Deletion functions
 *
 * struct node* deleteFirst()
 * 		Delete first item in list.
 * 		Returns the deleted link.
 *
 * struct node* delete()
 * 		Delete a link with a given key.
 * 		Returns the new current head.
 *
 */
struct node* deleteFirst() {

	/*
	 * Save the reference to the first link.
	 */
	struct node *tempLink = head;

	/*
	 * Move head forward to mark the next link as the first.
	 */
	head = head -> next;

	return tempLink;
}

struct node* deleteOne(char* key) {

	struct node* current  = head;
	struct node* previous = NULL;

	/*
	 * Check if list is empty.
	 */
	if (head == NULL) {
		return NULL;
	}

	while (current -> key != key) {

		if (current->next == NULL) {
			return NULL;
		} else {
			previous = current;
			current = current->next;
		}
	}

	/*
	 * If a match is found update the link.
	 */
	if (current == head) {
		head = head -> next;
	} else {
		previous -> next = current -> next;
	}

	return current;
}

/*
 * Check if list is empty
 */
bool isEmpty() {
	return head == NULL;
}

/*
 * Retrieve the length of the list
 */
int length() {
	int length = 0;
	struct node *current;

	for(current = head; current != NULL; current = current->next) {
		length++;
	}

	return length;
}



