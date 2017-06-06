#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stacknode {
	int item;
	struct stacknode* link;
}stackNode;

stackNode* top = NULL;

int isEmpty();
void push(int item);
int pop();
int peek();
void printStack();

void main(void) {
	int item;
	printf("\n** ���� ���� ���� **\n");
	printStack();
	push(1);	printStack();		// 1 ����
	printf("\n");
	push(2);    printStack();		// 2 ����
	printf("\n");
	push(3);	printStack();		// 3 ����
	printf("\n");

	item = peek(); 
	printStack();	// ���� top�� ���� ���
	printf("\n");
	printf("peek => %d\n", item);

	item = pop();  printStack();	// ����
	printf("\t pop  => %d\n", item);

	item = pop();  printStack();	// ����
	printf("\t pop  => %d\n", item);

	item = pop();  printStack();	// ����
	printf("\t pop  => %d\n", item);

	getchar();
}

int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}
void push(int item) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	newNode->item = item;	
	newNode->link = top;
	top = newNode;
}
int pop() {
	stackNode* temp = top;
	int item;
	if (isEmpty()) {
		printf("stack is empty");
		return 0;
	}
	else { 
		item = temp->item;
		top = temp->link;
		free(temp);
		return item;
	}
}
int peek() {
	if (isEmpty()) {
		printf("stack is empty");
		return 0;
	}
	else
		return top->item;
}
void printStack() {
	stackNode* temp = top;
	while (temp != NULL) {
		printf("%d", temp->item);
		temp = temp->link;
	}
}