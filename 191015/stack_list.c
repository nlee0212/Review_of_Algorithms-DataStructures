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
		printf("스택 언더플로우가 발생했습니다.\n");
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
	printf("---스택의 최상단---\n");
	while (cur != NULL) {
		printf("%d\n",cur->data);
		cur = cur->next;
	}
	printf("---스택의 최하단---");
}
	
int main(void) {
	Stack s;
	s.top = NULL;//동적할당이 아닌 그냥 구조체 변수를 선언해주었기 때문. 구조체의 포인터 변수를 동적할당으로 선언해주면 그땐 '->' 써야함.
	push(&s, 7);
	push(&s, 6);
	push(&s, 5);
	pop(&s);
	push(&s, 4);
	pop(&s);
	show(&s);//상단 6 7 하단
	return 0;
}