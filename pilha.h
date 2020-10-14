struct StackNode {
	int itemType;
	struct StackNode* next;
};

struct StackNode* CreateStack(int);
void DeleteStack(struct StackNode*);