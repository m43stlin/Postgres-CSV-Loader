#include "headers/lnklist.h"
#include "headers/tble_funcs.h"

#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>


int main () {

	/*
	 * getColNames(char *str) from stdin
	 */
	char buf[LINE_MAX];

	if (!fgets(buf, LINE_MAX, stdin)) {
		perror("fgets");
	}

	/*
	 * Get rid of newline character in fgets buffer.
	 */
	buf[strcspn(buf, "\n")] = 0;

	/*
	 * Store column names in array.
	 */
	char *tmp = strdup(buf);
	char** arr = getColNames(tmp);

	/*
	 * Set the current node to the head.
	 */
	struct node* crrnt = head;

	/*
	 * Populate columns
	 */
	for (int j = 0; arr[j]; j++) {
		insertFirst(arr[j], arr[j]);
	}

	/*
	 * Print the linked list.
	 */
	printList();

	/*
	 * Print the length of the linked list.
	 */
	printf("\nLength of linked list: %d", length());

	/*
	 * Find at what index the value "id" exist and print it.
	 */
	printf("\nFound value id at key: %d",find("id"));

	/*
	 * Set current node back to head.
	 */
	crrnt = head;

	/*
	 * Test some values in the linked using
	 */
	printf("\n%s\n", crrnt->key);
	crrnt = crrnt->next;
	printf("%s\n", crrnt->key);

	/*
	 * Free fgets buffer.
	 */
	free(tmp);

	return 0;
}