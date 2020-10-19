#include "pilha.h"

struct StackNode* CreateStack(int capacity) {
	struct StackNode* stack =\
		(struct StackNode*)malloc(sizeof(struct StackNode)); 
    if (capacity > 0)
		stack->capacity = capacity;
	stack->top = -1; 
	stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
	return stack; 
}

void DeleteStack(struct StackNode** stack) {
    free((*stack)->array);
    free(*stack);
	*stack = NULL;
}

int StackSize(struct StackNode* stack) {
	if (stack == NULL)
		return 0;
	
	if(stack->array == NULL)
		return 0;
	
	return stack->top + 1;
}

int SetSize(struct StackNode** stack, int size) {
	if (*stack == NULL)
		return 0;
	
	int current_size = StackSize(*stack);
	int diff = 0;

	(*stack)->capacity = size;

	if (current_size > size) {
		diff = current_size - size;
		while (diff > 0) {
			Pop(stack);
			diff = diff - 1;
		}
	}

	if ((*stack)->capacity == size)
		return 1;

	return 0;
}

int IsFull(struct StackNode* stack) {
	if (stack == NULL)
		return 0; 
	return stack->top == stack->capacity - 1;
}

int IsEmpty(struct StackNode* stack) {
	if (stack == NULL)
		return 1; 
	return stack->top == -1; 
}

void Push(struct StackNode** stack, int item) {
	if (IsFull(*stack)) 
		return; 
	(*stack)->array[++(*stack)->top] = item; 
	printf("%d pushed to stack\n", item); 
}

int Pop(struct StackNode** stack) {
	if (IsEmpty(*stack))
		return INT_MIN;

	return (*stack)->array[(*stack)->top--]; 
}

int Top(struct StackNode* stack) {
	if (IsEmpty(stack)) 
		return INT_MIN; 
	return stack->array[stack->top]; 
}