#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack;
typedef struct Stack* stack;

bool isEmpty(stack P);
bool isFull(stack P);
stack CreatStack(void);
void DisposeStack(stack P);
void MakeEmpty(stack P);
void push(int val, stack P);
void pop(stack P);
int top(stack P);
int top_pop(stack P);


struct Stack
{
	int val;
	stack next;
};

int main() {
	stack P = CreatStack();//p is head
	printf("isEmpty=%s  %d\n", (isEmpty(P) ? "true" : "false"));
	push(2, P);
	printf("isEmpty=%s\n", (isEmpty(P) ? "true" : "false"));
	push(3, P);
	printf("%d\n", top(P));
	pop(P);
	printf("%d\n", top(P));
	pop(P);
	printf("isEmpty=%s\n", (isEmpty(P) ? "true" : "false"));
	return 0;
}
bool isEmpty(stack P) {
	return P->next == NULL;
}
bool isFull(stack P) {
	stack s = (stack)malloc(sizeof(struct Stack));
	return s == NULL;
}
stack CreatStack(void) {
	stack P = (stack)malloc(sizeof(struct Stack));
	if (P) {
		P->next = NULL;
	}
	else {
		//heap
		exit(-1);
	}
}
void DisposeStack(stack P) {
	if (P == NULL) {
		exit(-1);
		//empty
	}
	else
	{
		while (!isEmpty(P)) {
			pop(P);
		}
	}
}
void MakeEmpty(stack P) {
	stack temp = P->next;
	stack temp2 = temp;
	P->next = NULL;
	while (temp2 != NULL) {
		temp2 = temp->next;
		free(temp);
	}
}
void push(int val, stack P) {
	stack temp = (stack)malloc(sizeof(struct Stack));
	if (temp == NULL) {
		exit(-1);
		//heap
	}
	temp->val = val;
	temp->next = P->next;
	P->next = temp;
}
void pop(stack P) {
	stack temp = (stack)malloc(sizeof(struct Stack));
	temp = P->next;
	P->next = P->next->next;
	free(temp);
}
int top(stack P) {
	return P->next->val;
}
int top_pop(stack P) {
	stack temp = (stack)malloc(sizeof(struct Stack));
	temp = P->next;
	int tmp_val = temp->val;
	P->next=P->next->next;
	free(temp);
	return tmp_val;
}

