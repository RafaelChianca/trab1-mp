#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct StackNode {
	int itemType;
	struct StackNode* next;
	int top; 
    unsigned capacity; 
    int* array;
};

struct ItemType {
	unsigned data;
};

struct StackNode* CreateStack(int);
void DeleteStack(struct StackNode**);
int StackSize(struct StackNode*);
int SetSize(struct StackNode**, int);
int IsFull(struct StackNode*);
int IsEmpty(struct StackNode*);
void Push(struct StackNode**, int);
int Pop(struct StackNode**);
int Top(struct StackNode*);