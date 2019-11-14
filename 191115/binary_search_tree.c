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

	else {//��͸� �̿������ν� ��������� leaf node�� �����ϰԲ� ��.
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
	if (root == NULL) return NULL;//���ʿ� Ʈ���� ����ų�, Ž���� ������ ��� �� �� NULL ��ȯ.
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
				node = (root->leftChild != NULL) ? root->leftChild : root->rightChild;//left�� ������ left�Ѹ��̴ϱ� �װ� ��ȯ���ָ� �ǰ�, ������right�� �ְų� 0���̴ϱ� right�� ��ȯ���ָ� ��
				free(root);
				return node;//�̷��� �Ǹ� ���ο� node�� ���� root�� left�� right�� ��. root �ǳ� �� ����
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