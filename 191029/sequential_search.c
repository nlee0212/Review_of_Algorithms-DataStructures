#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LENGTH 100

int main(void) {
	int n, i;
	int found=0;
	char* word = (char*)malloc(sizeof(char)*LENGTH);

	scanf("%d %s", &n, word);

	char** array;
	array = (char**)malloc(sizeof(char*)*n);
	for (i = 0; i < n; i++) {
		array[i] = (char*)malloc(sizeof(char)*LENGTH);
		scanf("%s", array[i]);
	}

	for (i = 0; i < n; i++) {
		if (!strcmp(word, array[i])) {
			found = 1;
			printf("Word found.\nindex: %d\n",i);
		}
	}

	if (!found) printf("Word not found.\n");

	free(word);
	for (i = 0; i < n; i++) free(array[i]);
	free(array);

	return 0;
}