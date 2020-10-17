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

void DeleteStack(struct StackNode** root)  {
	struct StackNode* temp = *root;

	while (!IsEmpty(*root)) {
		temp = *root;
		*root = (*root)->next;
		free(temp);
	}

}

int StackSize(struct StackNode* root) {
	struct StackNode* current = root;
    struct StackNode* next;
	int count = 0;

    while (current != NULL) {
        next = current->next;
        count++;
		current = next;
    }

	return count;
}

int SetSize(struct StackNode** root, int size) {
	int current_size = 0;
	current_size = StackSize(*root);
	
	if (current_size > size) {
		while (current_size > size) {
			Pop(root);
			--current_size;
		}
	} else if (current_size < size) {
		while (current_size < size) {
			Push(root, 0);
			++current_size;
		}
	}
	
	if (current_size == size) {
		return 1;
	}

	return 0;
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
	return root->itemType;
}

int main() {
	struct StackNode* stack = NULL;

	Push(&stack, 10);
	Push(&stack, 20);
	Push(&stack, 30);
	Push(&stack, 40);
	Push(&stack, 50);
	Push(&stack, 60);


	printf("Pop na pilha: %d\n", Pop(&stack));

	printf("Elemento no topo: %d\n", Top(stack));

	printf("set tamanho da pilha: %d\n", SetSize(&stack, 4));

	printf("Tamanho da pilha: %d\n", StackSize(stack));

	DeleteStack(&stack);

	return 0;
}