#include <stdio.h>
#define MAX_SIZE 1000

int a[MAX_SIZE];
int found = 0;

int b_search(int start, int end, int target) {
	if (start > end) return -9999;
	else {
		int mid = (start + end) / 2;
		if (a[mid] < target) return b_search(mid + 1, end, target);
		else if (a[mid] > target) return b_search(start, mid - 1, target);
		else return mid;
	}
}

int main(void) {
	int n, target;
	int i;

	scanf("%d %d", &n, &target);
	
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	int res = b_search(0, n - 1, target);

	if (res < 0) printf("Target not found.\n");
	else printf("Target found.\nindex: %d\n", res);

	return 0;
}