#include "pilha.h"

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

void DeleteStack(struct StackNode** root)  {
	struct StackNode* temp = *root;

	while (!IsEmpty(*root)) {
		temp = *root;
		*root = (*root)->next;
		free(temp);
	}

	*root = NULL;
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

	if (count == 1 && root->top == -1)
		count = 0;

	return count;
}

int SetSize(struct StackNode** root, int size) {
	int current_size = StackSize(*root);

	if ((*root) == NULL)
		return 0;

	struct StackNode* current = *root;

	while (current != NULL) {
		current->capacity = size;
		current = current->next;
	}
	
	if (current_size > size) {
		while (current_size > size) {
			Pop(root);
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

int IsFull(struct StackNode* root) {
	if (root == NULL)
		return 0;

	if (root->top == -1) {
		if (root->capacity == 0)
			return 1;
		else
			return 0;
	}
	
	return root->top == root->capacity;
}

int IsEmpty(struct StackNode* root) {
	return !root || ((StackSize(root) == 0 && root != NULL && root->top == -1));
}

void Push(struct StackNode** root, int data) {
	if (!(*root)) {
		printf("Push sem a pilha ter sido inicializada.\nTerminando programa.\n");
		exit(0);
	}
	
	if (!IsFull(*root)) {
		if (StackSize(*root) == 0 && *root != NULL && (*root)->top == -1) {
			(*root)->itemType = data;
			(*root)->top = 1;
		} else {
			struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
			stackNode->itemType = data;
			stackNode->next = *root;
			stackNode->top = (*root)->top + 1;
			stackNode->capacity = (*root)->capacity;
			*root = stackNode;
		}
		printf("%d Adicionada a pilha\n", data);
	} else {
		printf("Pilha já está em sua capacidade máxima!\n");
	}
}

int Pop(struct StackNode** root) {
	int Popped;

	if (IsEmpty(*root)) {
		if (StackSize(*root) == 0 && *root != NULL && (*root)->top == -1) {
			Popped = (*root)->itemType;
			(*root)->itemType = 0;
			(*root)->top = -1;
		}
		printf("A pilha já está vazia!\n");
		return INT_MIN;
	} else {
		struct StackNode* temp = *root;
		if ((*root)->next != NULL)
			(*root)->next->top = (*root)->top - 1;
		*root = (*root)->next;
		Popped = temp->itemType;
		free(temp);
	}

	printf("%d Removido da pilha\n", Popped);

	return Popped;
}

int Top(struct StackNode* root) {
	if (IsEmpty(root))
		return INT_MIN;
	return root->itemType;
}