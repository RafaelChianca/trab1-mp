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
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

int main() {
	struct StackNode* stack = NULL;

	return 0;
}
