#include <stdio.h>
#define SIZE 10000

int a[SIZE];

int main(void) {
	int n, i, m;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		a[m]++;
	}

	for (i = 0; i < SIZE; i++) {
		while (a[i] != 0) {
			printf("%d ", i);
			a[i]--;
		}
	}

	return 0;
}