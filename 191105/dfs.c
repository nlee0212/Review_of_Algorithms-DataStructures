#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct {
	int index;
	struct Node* next;
}Node;

Node** graph;
int vertex, edge, visited[MAX_SIZE] = { 0 };

void addFront(Node* root, int index) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->next = root->next;
	root->next = node;
}

void dfs(int index) {
	if (visited[index]) return;//�湮 ������ �� �� �ʿ� x
	else {//�湮�� ���� �ʾҴٸ�,
		visited[index] = 1;//�湮 ǥ�����ְ�,
		printf("%d ", index);//�湮 ��Ȳ ����Ʈ ���ְ�,
		Node* cur = graph[index]->next;//���� ������ cur��带 �̿��Ͽ�
		while (cur != NULL) {
			dfs(cur->index);//dfs �ݺ� ����
			cur = cur->next;//��� ���� ���� �� Ž���ϵ���.
		}
	}
}

int main(void) {
	int i;
	int start, end;

	scanf("%d %d", &vertex, &edge);

	graph = (Node**)malloc(sizeof(Node*)*vertex);
	for (i = 1; i <= vertex; i++) {
		graph[i] = (Node*)malloc(sizeof(Node));
		graph[i]->next = NULL;
	}

	for (i = 0; i < edge; i++) {//undirected unweighted graph
		scanf("%d %d", &start, &end);
		addFront(graph[start], end);
		addFront(graph[end], start);
	}

	dfs(1);

	return 0;
}