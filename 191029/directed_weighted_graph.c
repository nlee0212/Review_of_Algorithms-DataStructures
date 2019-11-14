#include <stdio.h>

typedef struct {
	int index;
	int distance;
	struct Node* next;
}Node;

void addFront(int index, int distance, Node* root) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->distance = distance;
	node->next = root->next;
	root->next = node;
}

void showAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		printf("%d(distance: %d) ", cur->index, cur->distance);
		cur = cur->next;
	}
}

int main(void) {
	int n, m;
	int i, j;
	int index, distance, vertex;

	scanf("%d %d", &n, &m);

	Node** a = (Node**)malloc(sizeof(Node*)*(n+1));
	for (i = 1; i <= n; i++) {
		a[i] = (Node*)malloc(sizeof(Node));
		a[i]->next = NULL;
	}

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &vertex, &index, &distance);
		addFront(index, distance, a[vertex]);
	}

	for (i = 1; i <= n; i++) {
		printf("Vertex %d: ", i);
		showAll(a[i]);
		printf("\n");
	}

	return 0;
}