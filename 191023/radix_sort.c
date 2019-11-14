#include <stdio.h>
#define SIZE 1000

void radixSort(int *a, int n) {
	int res[SIZE], bucket[10] = { 0 };
	int i;
	int exp = 1;
	int maxNum = 0;

	for (i = 0; i < n; i++) {
		if (maxNum < a[i])
			maxNum = a[i];
	}

	while (exp <= maxNum) {
		for (i = 0; i < 10; i++)bucket[i] = 0;
		for (i = 0; i < n; i++) bucket[a[i] / exp % 10]++;
		for (i = 1; i < 10; i++) bucket[i] += bucket[i - 1];
		for (i = n - 1; i >= 0; i--) res[--bucket[a[i] / exp % 10]] = a[i];
		for (i = 0; i < n; i++)a[i] = res[i];
		exp *= 10;
	}
}

int main(void) {
	int n;
	int i;
	int a[SIZE];

	scanf("%d", &n);

	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	radixSort(a, n);
	for (i = 0; i < n; i++) printf("%d ", a[i]);

	return 0;
}