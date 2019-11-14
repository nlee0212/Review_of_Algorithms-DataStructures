#include <stdio.h>
#include <stdlib.h>

typedef struct {
	struct Node* leftChild;
	struct Node* rightChild;
	int data;
}Node;

Node* insertNode(Node* root, int data) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->data = data;
		root->leftChild = NULL;
		root->rightChild = NULL;
		return root;
	}

	else {//재귀를 이용함으로써 결과적으로 leaf node에 도달하게끔 함.
		if (root->data > data) {
			root->leftChild = insertNode(root->leftChild, data);
		}
		else {
			root->rightChild = insertNode(root->rightChild, data);
		}
		return root;
	}
}

Node* searchNode(Node* root, int data) {
	if (root == NULL) return NULL;//애초에 트리가 비었거나, 탐색에 실패할 경우 둘 다 NULL 반환.
	else if (root->data == data) return root;
	else if (root->data > data) return searchNode(root->leftChild, data);
	else if (root->data < data) return searchNode(root->rightChild, data);
}

void preorder(Node* root) {
	if (root == NULL) return;
	else {
		printf("%d ", root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

Node* findMinNode(Node* root) {
	if (root == NULL) return NULL;
	Node* node = root;
	while (node->leftChild != NULL) {
		node = node->leftChild;
	}
	return node;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) return NULL;
	else {
		Node* node;
		if (root->data > data) root->leftChild = deleteNode(root->leftChild, data);
		else if (root->data < data) root->rightChild = deleteNode(root->rightChild, data);
		else {
			if (root->leftChild != NULL && root->rightChild != NULL) {
				node = findMinNode(root->rightChild);
				root->data = node->data;
				root->rightChild = deleteNode(root->rightChild, node->data);
			}
			else {
				node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;//left가 있으면 left한명이니까 그걸 반환해주면 되고, 없으면right가 있거나 0명이니까 right를 반환해주면 됨
				free(root);
				return node;//이렇게 되면 새로운 node가 상위 root의 left나 right가 됨. root 건너 뛴 느낌
			}
		}
		return root;
	}
}

int main(void) {
	Node* root = NULL;
	root = insertNode(root, 30);
	root = insertNode(root, 17);
	root = insertNode(root, 5);
	root = insertNode(root, 23);
	root = insertNode(root, 48);
	root = insertNode(root, 37);
	root = insertNode(root, 50);
	root = deleteNode(root, 30);
	preorder(root);

	return 0;
}