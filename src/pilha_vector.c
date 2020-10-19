#include "pilha.h"

/*******************************************************************************
 * Esta função é responsável por criar a "cabeça" da pilha.
 * 
 * @param capacity indica quantos elementos devem caber inicialmente na 
 * 				pilha criada.
 ******************************************************************************/
struct StackNode* CreateStack(int capacity) {
	struct StackNode* stack =\
		(struct StackNode*)malloc(sizeof(struct StackNode)); 
    if (capacity > 0)
		stack->capacity = capacity;
	stack->top = -1; 
	stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
	return stack; 
}

/*******************************************************************************
 * Esta função é responsável por deletar a pilha da memória do computador.
 *
 * @param root É o endereço de memória da pilha criada; 
 * 
 ******************************************************************************/
void DeleteStack(struct StackNode** stack) {
    free((*stack)->array);
    free(*stack);
	*stack = NULL;
}

/*******************************************************************************
 * Esta função é responsável por retornar o tamanho da pilha.

 * @param root É a pilha criada; 
 * 
 ******************************************************************************/
int StackSize(struct StackNode* stack) {
	if (stack == NULL)
		return 0;
	
	if(stack->array == NULL)
		return 0;
	
	return stack->top + 1;
}

/*******************************************************************************
 * Esta função é responsável por redefinir o tamanho da pilha.

 * @param stack É o endereço de memória da pilha;
 * 
 * @param size É o tamanho desejado para a pilha;
 * 
 ******************************************************************************/
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

/*******************************************************************************
 * Esta função é responsável por retornar se a pilha está cheia.

 * @param stack É a pilha criada; 
 * 
 ******************************************************************************/
int IsFull(struct StackNode* stack) {
	if (stack == NULL)
		return 0; 
	return stack->top == stack->capacity - 1;
}

/*******************************************************************************
 * Esta função é responsável por retornar se a pilha está vazia.

 * @param stack É a pilha criada; 
 * 
 ******************************************************************************/
int IsEmpty(struct StackNode* stack) {
	if (stack == NULL)
		return 1; 
	return stack->top == -1; 
}

/*******************************************************************************
 * Esta função é responsável por empilhar um elemento na pilha.

 * @param stack É o endereço de memória da pilha;
 * 
 * @param data É o valor que dejeja colocar nesse item da pilha;
 * 
 ******************************************************************************/
void Push(struct StackNode** stack, int item) {
	if (IsFull(*stack)) 
		return; 
	(*stack)->array[++(*stack)->top] = item; 
	printf("%d pushed to stack\n", item); 
}

/*******************************************************************************
 * Esta função é responsável por desempilhar um elemento na pilha.

 * @param stack É o endereço de memória da pilha;
 * 
 ******************************************************************************/
int Pop(struct StackNode** stack) {
	if (IsEmpty(*stack))
		return INT_MIN;

	return (*stack)->array[(*stack)->top--]; 
}

/*******************************************************************************
 * Esta função é responsável por retornar o elemento no topo da pilha.

 * @param stack É a pilha criada;
 * 
 ******************************************************************************/
int Top(struct StackNode* stack) {
	if (IsEmpty(stack)) 
		return INT_MIN; 
	return stack->array[stack->top]; 
}