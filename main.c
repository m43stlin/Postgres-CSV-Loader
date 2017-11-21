#include <string.h>
#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>


int getColNames(char* colNames) {

	char *token;
	char **n_arr = (char**) malloc(sizeof(char*) * 100);
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

	/*
	 * TEMP - test to ensure column names are stored in array.
	 */
	for (int j = 0; j < 6 ; ++j) {
		printf("%s\n", n_arr[j]);
	}

	return 0;
}


int main () {
	/*
	 * Test getColNames(char *str) from stdin
	 */
	char buf[LINE_MAX];

	if (!fgets(buf, LINE_MAX, stdin)) {
		perror("fgets");
	}

	char *tmp = strdup(buf);
	getColNames(tmp);
	free(tmp);

	return 0;
}