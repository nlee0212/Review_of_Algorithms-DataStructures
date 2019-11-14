#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct Node {
	int data;
	struct Node *next;
}Node;

typedef struct Stack {
	Node* top;
}Stack;

void push(Stack* stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

int pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node* node = stack->top;
	int data = node->data;
	stack->top = node->next;
	free(node);
	return data;
}

void show(Stack* stack) {
	Node* cur = stack->top;
	printf("---������ �ֻ��---\n");
	while (cur != NULL) {
		printf("%d\n",cur->data);
		cur = cur->next;
	}
	printf("---������ ���ϴ�---");
}
	
int main(void) {
	Stack s;
	s.top = NULL;//�����Ҵ��� �ƴ� �׳� ����ü ������ �������־��� ����. ����ü�� ������ ������ �����Ҵ����� �������ָ� �׶� '->' �����.
	push(&s, 7);
	push(&s, 6);
	push(&s, 5);
	pop(&s);
	push(&s, 4);
	pop(&s);
	show(&s);//��� 6 7 �ϴ�
	return 0;
}