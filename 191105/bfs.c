#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001
#define INF 99999999

typedef struct {
	int index;
	struct Node* next;
}Node;

typedef struct {
	int count;
	Node* front;
	Node* rear;
}Queue;

Node** graph;
int vertex, edge, visited[MAX_SIZE] = { 0 };

void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void queuePush(Queue* q, int index) {
	if (q->count >= MAX_SIZE) {
		printf("Queue Overflow!\n");
		return;
	}
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = NULL;
	if (q->count == 0) q->front = node;
	else q->rear->next = node;
	q->rear = node;//
	q->count++;//이 두 줄은 q->count에 관계없이 꼭 해야하므로.
}

int queuePop(Queue* q) {
	if (!q->count) {
		printf("Queue Underflow!\n");
		return -INF;
	}
	else {
		Node* cur = q->front;
		int index = cur->index;
		q->front = cur->next;
		free(cur);
		q->count--;
		return index;
	}
}

void bfs(int index) {
	Queue q;
	q.count = 0;
	q.front = q.rear = NULL;
	queuePush(&q, index);
	visited[index] = 1;
	while (q.count != 0) {
		int now = queuePop(&q);
		printf("%d ", now);
		Node* cur = graph[now]->next;
		while (cur != NULL) {
			if (!visited[cur->index]) {
				queuePush(&q, cur->index);
				visited[cur->index] = 1;
			}
			cur = cur->next;
		}
	}
}

int main(void) {
	int i;
	int x, y;

	scanf("%d %d", &vertex, &edge);

	graph = (Node**)malloc(sizeof(Node*)*vertex);
	for (i = 1; i <= vertex; i++) {
		graph[i] = (Node*)malloc(sizeof(Node));
		graph[i]->next = NULL;
	}

	for (i = 0; i < edge; i++) {
		scanf("%d %d", &x, &y);
		addFront(graph[x], y);
		addFront(graph[y], x);
	}

	bfs(1);

	return 0;
}