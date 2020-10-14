struct StackNode {
	int itemType;
	struct StackNode* next;
};

struct StackNode* CreateStack(int);
void DeleteStack(struct StackNode*);
int IsEmpty(struct StackNode*);
void Push(struct StackNode**, int);
int Pop(struct StackNode**);