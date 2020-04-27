#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackRecord;
typedef struct StackRecord* stack;

bool isEmpty(stack s);
bool isFull(stack s);
stack CreatStack(int MaxElements);
void DisposeStack(stack s);
void MakeEmpty(stack s);
void push(int val, stack s);
void pop(stack s);
int top(stack s);
int top_pop(stack s);

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
	int Capacity;
	int Top_of_Stack;//key point
	int *Array;
};

int main() {
	stack s = CreatStack(1000);
	push(2, s);
	push(3, s);
	printf("%d\n", top(s));
	pop(s);
	printf("%d\n", top(s));
	pop(s);
	printf("is_empty=%s", isEmpty(s) ? "true" : "false");
	return 0;
}

bool isEmpty(stack s) {
	return s->Top_of_Stack == EmptyTOS;
}
bool isFull(stack s) {
	return !(s->Top_of_Stack < s->Capacity);
}
stack CreatStack(int MaxElements) {
	stack s;
	if (MaxElements < MinStackSize) {
		//error(too small)
		exit(-1);
	}
	s = (stack)malloc(sizeof(StackRecord));
	if (!s) {
		//heap overflow
		exit(-1);
	}
	s->Array = (int*)malloc(sizeof(int)*MaxElements);
	if (!s->Array) {
		//heap
		exit(-1);
	}
	s->Capacity = MaxElements;//contain_in this array
	MakeEmpty(s);
	return s;
}
void DisposeStack(stack s) {
	if (s) {
		free(s->Array);
		free(s);
	}
}
void MakeEmpty(stack s) {
	s->Top_of_Stack = EmptyTOS;
}
void push(int val, stack s) {
	if (isFull(s)) {
		//error
		exit(-1);
	}
	s->Array[++s->Top_of_Stack] = val;//from left to right,'->'is higher than '[]'
}
void pop(stack s) {
	if (isEmpty(s)) {
		//error
		exit(-1);
	}
	else
	{
		s->Top_of_Stack--;
	}
}
int top(stack s) {
	if (!isEmpty(s)) {
		return s->Array[s->Top_of_Stack];
	}
	//error
	exit(-1);
}
int top_pop(stack s) {
	if (!isEmpty(s)) {
		return s->Array[s->Top_of_Stack--];
	}
	//error
	exit(-1);
}