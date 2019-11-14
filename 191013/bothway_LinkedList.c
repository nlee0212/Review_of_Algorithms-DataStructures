#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
}Node;

Node *head, *tail;

void insert(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data=data;
	Node* cur = head->next;
	while (cur != tail && cur->data<data) {
		cur = cur->next;
	}
	Node* prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}

void removeFront() {
	Node* node = head->next;
	head->next = node->next;
	Node* next = node->next;
	next->prev = head;
	free(node);
}

void showAll() {
	Node* cur = head->next;
	while (cur != tail) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

void FreeAll() {
	Node* cur = head->next;
	while (cur != tail) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	free(tail);
	free(head);
}

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;

	insert(2);
	insert(4);
	insert(1);
	insert(3);
	insert(5);
	removeFront();
	showAll();
	FreeAll();
	return 0;
}