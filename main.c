#include <string.h>
#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>


char** getColNames(char* colNames) {

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

	return n_arr;
}


int main () {
	/*
	 * Test getColNames(char *str) from stdin
	 */
	char buf[LINE_MAX];
	char **arr;

	if (!fgets(buf, LINE_MAX, stdin)) {
		perror("fgets");
	}
	/*
	 * Get rid of newline character in fgets buffer
	 */
	buf[strcspn(buf, "\n")] = 0;

	char *tmp = strdup(buf);
	arr = getColNames(tmp);

	/*
	 * Test return values of getColNames
	 */
	for (int j = 0; j < 6 ; ++j) {
		printf("%s\n", arr[j]);
	}

	free(tmp);

	return 0;
}