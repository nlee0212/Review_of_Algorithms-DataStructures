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
	if (visited[index]) return;//방문 했으면 더 들어갈 필요 x
	else {//방문을 하지 않았다면,
		visited[index] = 1;//방문 표시해주고,
		printf("%d ", index);//방문 현황 프린트 해주고,
		Node* cur = graph[index]->next;//인접 노드들을 cur노드를 이용하여
		while (cur != NULL) {
			dfs(cur->index);//dfs 반복 실행
			cur = cur->next;//모든 인접 노드들 다 탐색하도록.
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