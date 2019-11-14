#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* head;

void addFront(Node* root, int data) {
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = root->next;
	root->next = newnode;
}

void removeFront(Node* root) {
	Node* front = root->next;
	root->next = front->next;
	free(front);
}

void FreeAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	free(root);
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->data = 1;
	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->data = 2;

	head->next = node1;
	node1->next = node2;
	node2->next = NULL;

	Node* cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

	printf("\nadd 7 in front:\n");
	addFront(head, 7);
	cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

	printf("\nRemove front:\n");
	removeFront(head);
	cur = head->next;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

	FreeAll(head);

	return 0;
}