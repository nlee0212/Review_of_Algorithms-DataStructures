#include <stdio.h>
#include <limits.h>
#define SIZE 1000

int a[SIZE];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int n;
	int a[SIZE];
	int min = INT_MAX;
	int i, j;
	int index;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n; i++) {
		index = i;
		min = INT_MAX;
		for (j = i; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				index = j;
			}
		}
		swap(&a[i], &a[index]);
	}

	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}