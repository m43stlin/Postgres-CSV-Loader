#include <stdlib.h>
#include <memory.h>

/*
 * Getting the column names from the first line in the csv file/list.
 */

char** getColNames(char* colNames) {

	char* token;
	char** n_arr = malloc(sizeof(char *) * 1024);
	int i = 0;

	/*
	 * Get the first token
	 */
	n_arr[i] = token = strtok(colNames, ",");
	++i;

	/*
	 * Walk through the remaining tokens.
	 */
	while (token != NULL) {
		token = strtok(NULL, ",");

		n_arr[i] = token;
		++i;
	}

	return n_arr;
}