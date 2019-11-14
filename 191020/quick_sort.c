#include <stdio.h>
#define SIZE 1000

int a[SIZE];

void swap(int*a, int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int start, int end) {
	if (start >= end)
		return;
	int i, j;
	int key = start;
	i = start + 1;
	j = end;

	while (i <= j) {
		while (a[key] >= a[i] && i<=end)i++;
		while (a[key] <= a[j] && j>start)j--;
		if (i < j) swap(&a[i], &a[j]);
		else swap(&a[key], &a[j]);
	}

	quickSort(start, j - 1);
	quickSort(j + 1, end);
}

int main(void) {
	int n;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	quickSort(0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	return 0;
}