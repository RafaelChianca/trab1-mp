#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef PILHA_H_
  #define PILHA_H_
  #include "pilha.h"
#endif

struct StackNode* CreateStack(int data) {
	struct StackNode* stackNode = 
        (struct StackNode*)malloc(sizeof(struct StackNode));
	stackNode->itemType = data;
	stackNode->next = NULL;
	return stackNode;
}

void DeleteStack(struct StackNode* root)  {
    struct StackNode* current = root;
    struct StackNode* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int IsEmpty(struct StackNode* root) {
	return !root;
}

void Push(struct StackNode** root, int data) {
	struct StackNode* stackNode = CreateStack(data);
	stackNode->next = *root;
	*root = stackNode;
	printf("%d Adicionada a pilha\n", data);
}

int Pop(struct StackNode** root) {
	if (IsEmpty(*root))
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int Popped = temp->itemType;
	free(temp);

	return Popped;
}

int Top(struct StackNode* root) {
	if (IsEmpty(root))
		return INT_MIN;
	return root->data;
}

int main() {
	struct StackNode* stack = NULL;

	return 0;
}
