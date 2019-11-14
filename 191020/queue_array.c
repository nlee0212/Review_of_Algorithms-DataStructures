#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0;
int rear = 0;

void push(int data) {
	if (rear >= SIZE) {
		printf("큐 오버플로우가 발생했습니다.\n");
		return;
	}
	queue[rear++] = data;
}

int pop() {
	if (front == rear) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	return queue[front++];
}

void show() {
	int i;
	printf("---큐의 앞---\n");
	for (i = front; i < rear; i++) {
		printf("%d\n",queue[i]);
	}
	printf("---큐의 뒤---\n");
}

int main(void) {
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	show();//5 4 6

	return 0;
}