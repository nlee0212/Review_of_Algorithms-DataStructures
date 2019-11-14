#include <stdio.h>
#define MAX_SIZE 10000

void swap(int*a, int*b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

typedef struct {
	int heap[MAX_SIZE];
	int count;
}priorityQueue;

void push(priorityQueue* pq, int data) {
	if (pq->count >= MAX_SIZE) return;

	else {
		pq->heap[pq->count] = data;//�� �� �ε����� ���ο� ���� ����

		int now = pq->count;
		int parent = (now - 1) / 2;
		while (now > 0 && pq->heap[now] > pq->heap[parent]) {//���� ������ ��Ʈ ��忡 ������ �� ���� max heap �����ϰԲ�.(��������� �� ����)
			swap(&pq->heap[now], &pq->heap[parent]);
			now = parent;
			parent = (parent - 1) / 2;
		}
		pq->count++;
	}
}

int pop(priorityQueue* pq) {
	if (pq->count <= 0) return -9999;
	pq->count--;
	int res = pq->heap[0];
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	while (leftChild < pq->count) {
		if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
		if (pq->heap[target] < pq->heap[rightChild] && rightChild<pq->count) target = rightChild;
		if (target == now) break;
		else {
			swap(&pq->heap[target], &pq->heap[now]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}

int main(void) {
	int i,n;
	int data;

	priorityQueue pq;
	pq.count = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &data);
		push(&pq, data);
	}

	for (i = 0; i < n; i++) {
		printf("%d ", pop(&pq));
	}

	return 0;
}