#include <memory.h>
#include <stdio.h>
#include <string.h>

typedef struct Stack {
	int* top;
	size_t size;
	size_t items;
	int isEmpty;
	int isFull;
} Stack;

Stack stackCreate(size_t size) {
	Stack s = {
		.top = calloc(size * sizeof(int)),
		.size = size,
		.items = 0,
		.isEmpty = 1,
		.isFull = 0
	};

	return s;
}

void stackPush(Stack* s, int data) {
	if (s->items == s->size) {
		printf("The stack is full. Can't push an item.\n");
		return;
	}
	else {
		s->top++;
		s->items++;
		s->isEmpty = 0;
		*(s->top) = data;
		if (s->items == s->size) s->isFull = 1;
	}
}

int stackPeek(Stack* s) {
	if (!s->isEmpty) return *(s->top);
	else return -1;
}

int stackPop(Stack* s) {
	if (!s->isEmpty) {
		int data = *(s->top);
		s->top--;
		s->items--;
		if (s->items < 1) s->isEmpty = 1;
		return data;
	}
	else {
		printf("The stack is empty.\n");
	}
}

int main(int argc, char* argv[]) {
	Stack s = stackCreate(10);

	printf("Initialization:\n");

	for (int i = 1; i <= s.size; i++) {
		stackPush(&s, i);
		printf("%d ", stackPeek(&s));
	}
	printf("\n");

	if (s.isFull) printf("The stack is full.\n");
	else printf("The stack is not full.\n");

	printf("\n###Popping the stack###\n\n");

	int* arr = malloc(10 * sizeof(int));

	for (int i = 0; i < s.size; i++) 
		arr[i] = stackPop(&s);

	printf("After pop:\n\n");

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	printf("\n");

	if (s.isEmpty) printf("The stack is empty.\n");
	else printf("The stack is not empty.\n");

	free(arr);

	return 0;
}