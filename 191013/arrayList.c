#include <stdio.h>
#define INF 10000

int a[INF];
int i, count = 0;

void addBack(int x) {
	a[count++] = x;
}

void addFront(int x) {
	for (i = count; i >0; i--) {
		a[i] = a[i-1];
	}
	a[0] = x;
	count++;
}

void show() {
	for (i = 0; i < count; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Delete(int n) {
	for (i = n+1; i < count; i++) {
		a[i-1] = a[i];
	}

	count--;
}

int main(void) {
	addBack(5);
	addBack(8);
	addBack(7);
	addFront(3);
	addFront(4);
	addBack(9);
	addFront(1);//1435879
	show();

	printf("\nDelete 0\n");
	Delete(0);
	show();//435879

	printf("\nDelete 3\n");
	Delete(3);
	show();//43579

	printf("\nDelete 4\n");
	Delete(4);
	show();//4357

	return 0;
}