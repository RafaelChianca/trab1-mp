struct StackNode {
	int ItemType;
	struct StackNode* next;
};

struct StackNode* CreateStack(int);