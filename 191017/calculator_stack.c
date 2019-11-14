#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999

typedef struct Node {
	char data[100];
	struct Node* next;
}Node;

typedef struct Stack {
	Node* top;
}Stack;

char res[1000] = "";

void push(Stack *stack, char* data) {
	Node* node = (Node*)malloc(sizeof(Node));
	strcpy(node->data, data);
	node->next = stack->top;
	stack->top = node;
}

char* getTop(Stack* stack) {
	if (stack->top == NULL) {
		printf("스택이 비었습니다.\n");
		return 0;
	}
	else
		return(stack->top->data);
}

char* pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("스택 언더플로우가 발생하였습니다.\n");
		return -INF;
	}

	Node* node = stack->top;
	char* data = (char*)malloc(sizeof(char)*strlen(node->data));
	strcpy(data, node->data);
	stack->top = node->next;
	free(node);
	return(data);
}

int getPriority(char* a) {
	if (!strcmp(a, "(")) return 0;
	else if (!strcmp(a, "+") || !strcmp(a, "-")) return 1;
	else if (!strcmp(a, "*") || !strcmp(a, "/")) return 2;
	else return 3;
}

void transition(Stack* stack, char**a, int size) {
	int i;
	for (i = 0; i < size; i++) {
		if (!strcmp(a[i], "+") || !strcmp(a[i], "-") || !strcmp(a[i], "*") || !strcmp(a[i], "/")) {
			while (stack->top != NULL && (getPriority(getTop(stack)) >= getPriority(a[i]))) {//우선순위가 섞여서 들어있지 않으니 우선순위가 작은거 만나면 바로 넘어가기
					strcat(res, pop(stack));
					strcat(res, " ");
			}
			push(stack, a[i]);
		}

		else if (!strcmp(a[i], "("))
			push(stack, a[i]);

		else if (!strcmp(a[i], ")")) {
			while (strcmp(getTop(stack), "(")) {//top에 '('들어간 걸 만나면 strcmp는 0이 되니까.
				strcat(res, pop(stack));
				strcat(res, " ");
			}
			pop(stack);//괄호는 print하지 않음.
		}

		else {
			strcat(res, a[i]);
			strcat(res, " ");
		}
	}

	while (stack->top != NULL) {
		strcat(res, pop(stack));
		strcat(res, " ");
	}
}

void calculate(Stack* stack, char**a, int size) {
	int x, y, z;
	for (int i = 0; i < size; i++) {
		if (!strcmp(a[i], "+") || !strcmp(a[i], "-") || !strcmp(a[i], "*") || !strcmp(a[i], "/")) {
			x = atoi(pop(stack));
			y = atoi(pop(stack));

			if (!strcmp(a[i], "+"))
				z = y + x;
			else if (!strcmp(a[i], "-"))
				z = y - x;
			else if (!strcmp(a[i], "*"))
				z = y * x;
			else if (!strcmp(a[i], "/"))
				z = y / x;

			char buffer[100];
			sprintf(buffer, "%d", z);
			push(stack, buffer);
		}
		else
			push(stack, a[i]);
	}
	printf("result: %s\n", pop(stack));
}

int main(void) {
	Stack stack;
	stack.top = NULL;
	int i;

	char a[100] = "( ( 3 + 4 ) * 5 ) - 5 * 7 * 5 - 5 * 10";
	int size = 1;
	for (i = 0; i < strlen(a); i++) {
		if(a[i]==' ')
			size++;
	}

	char* ptr = strtok(a, " ");
	char** input = (char**)malloc(sizeof(char*)*size);
	for (i = 0; i < size; i++) {
		input[i] = (char*)malloc(sizeof(char) * 100);
		strcpy(input[i], ptr);
		ptr = strtok(NULL, " ");
	}

	char* b = (char*)malloc(sizeof(char)*strlen(a));
	transition(&stack, input, size);
	strcpy(b, res);
	printf("후위 표기법: %s\n", b);

	size = 1;
	for (i = 0; i < strlen(b) - 1; i++) {
		if (b[i] == ' ')
			size++;
	}

	char* ptr2 = strtok(b, " ");
	for (i = 0; i < size; i++) {
		strcpy(input[i], ptr2);
		ptr2 = strtok(NULL, " ");
	}

	calculate(&stack, input, size);


	return 0;
}