#include "pilha.h"

/*******************************************************************************
 * Esta função é responsável por criar a "cabeça" da pilha.
 * 
 * @param capacity indica quantos elementos devem caber inicialmente na 
 * 				pilha criada.
 ******************************************************************************/
struct StackNode* CreateStack(int capacity) {
	if (capacity > 0) {
		struct StackNode* stackNode =\
			(struct StackNode*)malloc(sizeof(struct StackNode));
		stackNode->capacity = capacity;
		stackNode->top = -1;
		stackNode->itemType = 0;
		stackNode->next = NULL;
		return stackNode;
	} else {
		printf("Capacidade deve ser maior que zero!\n");
		return NULL;
	}
}

/*******************************************************************************
 * Esta função é responsável por deletar a pilha da memória do computador.
 *
 * @param stack É o endereço de memória da pilha criada; 
 * 
 ******************************************************************************/
void DeleteStack(struct StackNode** stack)  {
	struct StackNode* temp = *stack;

	while (!IsEmpty(*stack)) {
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}

	*stack = NULL;
}

/*******************************************************************************
 * Esta função é responsável por retornar o tamanho da pilha.

 * @param stack É a pilha criada; 
 * 
 ******************************************************************************/
int StackSize(struct StackNode* stack) {
	struct StackNode* current = stack;
    struct StackNode* next;
	int count = 0;

	if (stack == NULL)
		return 0;

    while (current != NULL) {
        next = current->next;
        count++;
		current = next;
    }

	if (count == 1 && stack->top == -1)
		count = 0;

	return count;
}

/*******************************************************************************
 * Esta função é responsável por redefinir o tamanho da pilha.

 * @param stack É o endereço de memória da pilha;
 * 
 * @param size É o tamanho desejado para a pilha;
 * 
 ******************************************************************************/
int SetSize(struct StackNode** stack, int size) {
	int current_size = StackSize(*stack);

	if ((*stack) == NULL)
		return 0;

	struct StackNode* current = *stack;

	while (current != NULL) {
		current->capacity = size;
		current = current->next;
	}
	
	if (current_size > size) {
		while (current_size > size) {
			Pop(stack);
			current_size = current_size - 1;
		}
	} else if (current_size < size) {
		while (current_size < size) {
			current_size = current_size + 1;
		}
	}
	
	if (current_size == size) {
		return 1;
	}

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

	if (stack->top == -1) {
		if (stack->capacity == 0)
			return 1;
		else
			return 0;
	}
	
	return stack->top == stack->capacity;
}

/*******************************************************************************
 * Esta função é responsável por retornar se a pilha está vazia.

 * @param stack É a pilha criada; 
 * 
 ******************************************************************************/
int IsEmpty(struct StackNode* stack) {
	return !stack || ((StackSize(stack) == 0 && stack != NULL && stack->top == -1));
}

/*******************************************************************************
 * Esta função é responsável por empilhar um elemento na pilha.

 * @param stack É o endereço de memória da pilha;
 * 
 * @param data É o valor que dejeja colocar nesse item da pilha;
 * 
 ******************************************************************************/
void Push(struct StackNode** stack, int data) {
	if (!(*stack)) {
		printf("Push sem a pilha ter sido inicializada.\nTerminando programa.\n");
		exit(0);
	}
	
	if (!IsFull(*stack)) {
		if (StackSize(*stack) == 0 && *stack != NULL && (*stack)->top == -1) {
			(*stack)->itemType = data;
			(*stack)->top = 1;
		} else {
			struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
			stackNode->itemType = data;
			stackNode->next = *stack;
			stackNode->top = (*stack)->top + 1;
			stackNode->capacity = (*stack)->capacity;
			*stack = stackNode;
		}
		printf("%d Adicionada a pilha\n", data);
	} else {
		printf("Pilha já está em sua capacidade máxima!\n");
	}
}

/*******************************************************************************
 * Esta função é responsável por desempilhar um elemento na pilha.

 * @param stack É o endereço de memória da pilha;
 * 
 ******************************************************************************/
int Pop(struct StackNode** stack) {
	int Popped;

	if (IsEmpty(*stack)) {
		if (StackSize(*stack) == 0 && *stack != NULL && (*stack)->top == -1) {
			Popped = (*stack)->itemType;
			(*stack)->itemType = 0;
			(*stack)->top = -1;
		}
		printf("A pilha já está vazia!\n");
		return INT_MIN;
	} else {
		struct StackNode* temp = *stack;
		if ((*stack)->next != NULL)
			(*stack)->next->top = (*stack)->top - 1;
		*stack = (*stack)->next;
		Popped = temp->itemType;
		free(temp);
	}

	printf("%d Removido da pilha\n", Popped);

	return Popped;
}

/*******************************************************************************
 * Esta função é responsável por retornar o elemento no topo da pilha.

 * @param stack É a pilha criada;
 * 
 ******************************************************************************/
int Top(struct StackNode* stack) {
	if (IsEmpty(stack))
		return INT_MIN;
	return stack->itemType;
}